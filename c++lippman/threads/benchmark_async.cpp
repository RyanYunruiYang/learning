#include <vector>
#include <numeric>
#include <future>
#include <chrono>
#include <iostream>

using std::vector;
using std::async;

double accum(double* beg, double* end, double init)
{
    return std::accumulate(beg, end, init);
}

double accum2(vector<double>::iterator beg, vector<double>::iterator end, double init)
{
    return std::accumulate(beg, end, init);
}


double comp4(vector<double>& v, bool async_on)
// spawn many tasks if v is large enough
{
        if (!async_on) // is it wor th using concurrency?
            return accum2(v.begin(),v.end(),0.0);
        auto v0 = &v[0];
        auto sz = v.size();
        auto f0 = async(accum,v0,v0+sz/4,0.0); // first quarter
        auto f1 = async(accum,v0+sz/4,v0+sz/2,0.0); // second quarter
        auto f2 = async(accum,v0+sz/2,v0+sz*3/4,0.0); // third quarter
        auto f3 = async(accum,v0+sz*3/4,v0+sz,0.0); // four th quar ter
        return f0.get()+f1.get()+f2.get()+f3.get(); // collect and combine the results
}

int main() {
    std::cout << "Length\tAsync Time\tNormal Time" << std::endl;
    for (int length = 100* 1000; length <= 1000*1000; length += 100*1000) {
        vector<double> v;
        // Populate the vector with data
        for (int i = 0; i < length; i++) {
            v.push_back(i);
        }

        auto start = std::chrono::high_resolution_clock::now();
        double result = comp4(v, true);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;
        std::cout << length << "\t" << duration.count() << "\t";

        start = std::chrono::high_resolution_clock::now();
        result = comp4(v, false);
        end = std::chrono::high_resolution_clock::now();

        duration = end - start;
        std::cout << duration.count() << std::endl;
    }

    return 0;
}
