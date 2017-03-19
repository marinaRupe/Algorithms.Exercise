#include <iostream>
#include <math.h>

using namespace std;

bool equal (string str, string substr);
int naiveSubstringSearch(string str, string substr);
int rabinKarpSubstringSearch(string str, string substr, int p);

int main() {
    string str = "abcdefaaaa";
    string substr = "efa";
    int prime = 3;

    cout << "String: " << str << endl;
    cout << "Substring: " << substr << endl << endl;

    cout << "Naive string matching algorithm: " << endl;
    cout << "\tSubstring found on index " << naiveSubstringSearch(str, substr) << endl;

    cout << "Rabin-Karp algorithm: " << endl;
    cout << "\tSubstring found on index " << rabinKarpSubstringSearch(str, substr, prime) << endl;

    return 0;
}

int rabinKarpSubstringSearch(string str, string substr, int prime) {
    int M = (int)str.length();
    int N = (int)substr.length();

    int substrHash = 0;
    int strHash = 0;
    for (int i = 0; i < N; i++) {
        substrHash += substr[i] * (int)pow(prime, i);
        strHash += str[i] * (int)pow(prime, i);
    }

    for (int i = 0; i <= M - N + 1; i++) {
        if (strHash == substrHash && equal(str.substr(i, N), substr)) {
            return i;
        }
        else {
            strHash = (strHash - str[i]) / prime + str[i + N] * (int)pow(prime, N - 1);
        }
    }
    return -1;
}

bool equal (string str, string substr) {
    int N = (int)substr.length();
    bool flag = true;

    for (int i = 0; i < N; i++) {
        if (str[i] != substr[i]) {
            flag = false;
            break;
        }
    }
    return flag;
}

int naiveSubstringSearch(string str, string substr) {
    int M = (int)str.length();
    int N = (int)substr.length();

    for (int i = 0; i < M - N; i++) {
        bool flag = true;
        for (int j = 0; j < N; j++) {
            if (substr[j] != str[i + j]) {
                flag = false;
                break;
            }
        }
        if (flag) return i;
    }
    return -1;
}