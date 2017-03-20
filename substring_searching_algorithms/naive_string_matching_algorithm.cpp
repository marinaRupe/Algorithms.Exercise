#include <iostream>

using namespace std;

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