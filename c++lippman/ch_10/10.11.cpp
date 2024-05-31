/*
Exercise 10.11: Write a program that uses stable_sort and isShorter to sort a
vector passed to your version of elimDups. Print the vector to verify that your
program is correct.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

void printVector(const vector<string> &words) {
    for (const auto &word : words) {
        cout << word << " ";
    }
    cout << endl;
}

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool isShorter(const string &s1, const string &s2) { return s1.size() < s2.size();}


int main() {
    vector<string> words;
    string word;

    while (cin >> word && word != "end") {
        words.push_back(word);
    }

    cout << "Original vector: ";
    printVector(words);

    elimDups(words);
    stable_sort(words.begin(), words.end(), isShorter);
    printVector(words);

    /* 
    Original vector: zz c b a yy xx 
    a b c xx yy zz
    */

}