#include <iostream>

using namespace std;

int pow (int a, int b);
bool equal (string str, string substr);

int rabinKarpSubstringSearch(string str, string substr, int prime) {
    int M = (int)str.length();
    int N = (int)substr.length();

    int substrHash = 0;
    int strHash = 0;
    for (int i = 0; i < N; i++) {
        substrHash += substr[i] * pow(prime, i);
        strHash += str[i] * pow(prime, i);
    }

    for (int i = 0; i <= M - N + 1; i++) {
        if (strHash == substrHash && equal(str.substr(i, N), substr)) {
            return i;
        }
        else {
            strHash = (strHash - str[i]) / prime + str[i + N] * pow(prime, N - 1);
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

int pow (int a, int b) {
    int c = 1;
    for (int i = 0; i < b; i++) {
        c *= a;
    }
    return c;
}