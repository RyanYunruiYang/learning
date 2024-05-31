/*
Exercise 10.9: Implement your own version of elimDups. Test your program by
printing the vector after you read the input, after the call to unique, and after the
call to erase.
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
    // Sort the vector
    sort(words.begin(), words.end());
    cout << "After sorting: ";
    printVector(words);

    // Remove duplicates
    auto end_unique = unique(words.begin(), words.end());
    cout << "After unique: ";
    printVector(words);

    // Erase the non-unique elements
    words.erase(end_unique, words.end());
    cout << "After erase: ";
    printVector(words);
}

int main() {
    vector<string> words;
    string word;

    while (cin >> word && word != "end") {
        words.push_back(word);
    }

    cout << "Original vector: ";
    printVector(words);

    elimDups(words);
}
