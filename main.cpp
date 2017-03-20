#include <iostream>
#include "./substring_searching_algorithms/substring_search_algorithms.h"

using namespace std;

void testSubstringSearchAlgorithms();

int main() {
    testSubstringSearchAlgorithms();
    return 0;
}

void testSubstringSearchAlgorithms() {
    int prime = 3;

    string str = "abcdefaaaa";
    string substr = "efa";
    string str2 = "abxabcabcaby";
    string substr2 = "abcaby";

    cout << "String: " << str << endl;
    cout << "Substring: " << substr << endl << endl;

    cout << "Naive string matching algorithm: " << endl;
    cout << "\tSubstring found on index " << naiveSubstringSearch(str, substr) << endl << endl;

    cout << "Rabin-Karp algorithm: " << endl;
    cout << "\tSubstring found on index " << rabinKarpSubstringSearch(str, substr, prime) << endl << endl;

    cout << "KMP algorithm: " << endl;
    cout << "\tSubstring found on index " << KMPsubstringSearch(str, substr) << endl << endl;
}