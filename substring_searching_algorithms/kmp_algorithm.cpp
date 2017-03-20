#include <iostream>

using namespace std;

int KMPsubstringSearch(string str, string substr);
void computeTemporaryArray (string substr, int N, int* temporaryArray);

int KMPsubstringSearch(string str, string substr) {
    int M = (int)str.length();
    int N = (int)substr.length();

    int temporaryArray[N];
    computeTemporaryArray(substr, N, temporaryArray);

    int index = -1;
    int i = 0;
    int j = 0;
    while(i < M && j < N) {
        if (str[i] == substr[j]) {
            if (index == -1) {
                index = i - j;
            }
            i++;
            j++;
        }
        else {
            index = -1;
            if (j != 0) {
                j = temporaryArray[j - 1];
            }
            else {
                i++;
            }
        }
        if (j == N) {
            break;
        }
    }
    return index;
}

void computeTemporaryArray (string substr, int N, int* temporaryArray) {
    int j = 0;
    temporaryArray[0] = 0;

    for (int i = 1; i < N;) {
        if (substr[i] == substr[j]) {
            temporaryArray[i] = j + 1;
            i++;
            j++;
        }
        else {
            if (j != 0) {
                j = temporaryArray[j - 1];
            }
            else {
                temporaryArray[i] = 0;
                i++;
            }
        }
    }
    cout << "\tTemporary array: ";
    for (int i = 0; i < N; i++) {
        cout << temporaryArray[i] << " ";
    }
    cout << endl;
}