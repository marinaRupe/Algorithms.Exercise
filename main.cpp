#include <iostream>
#include "./substring_searching_algorithms/substring_search_algorithms.h"

using namespace std;

void testSubstringSearchAlgorithms();

int main() {
    testSubstringSearchAlgorithms();
    return 0;
}

void testSubstringSearchAlgorithms() {
    string str = "abcdefaaaa";
    string substr = "efa";
    int prime = 3;

    cout << "String: " << str << endl;
    cout << "Substring: " << substr << endl << endl;

    cout << "Naive string matching algorithm: " << endl;
    cout << "\tSubstring found on index " << naiveSubstringSearch(str, substr) << endl;

    cout << "Rabin-Karp algorithm: " << endl;
    cout << "\tSubstring found on index " << rabinKarpSubstringSearch(str, substr, prime) << endl;

    cout << "KMP algorithm: " << endl;
    cout << "\tSubstring found on index " << KMPsubstringSearch(str, substr) << endl;
}