//
//  main.cpp
//  LR6
//
//  Created by Rustam Khakhuk on 13.10.2022.
//

#include <iostream>

using namespace std;

bool checkSystem(int n, int m, int* ls, int* lo, int** matrix) {
    for(int s = 0; s < n; s++) {
        for(int o = 0; s < m; o++) {
            if(!(
               (ls[s] > lo[o] && matrix[s][o] == 1) ||
               (ls[s] <= lo[o] && matrix[s][o] == 0)
            )) {
                return false;
            }
        }
    }

    return true;
}

void printSystem(int n, int m, int* ls, int* lo, int** matrix) {
    cout << "matrix:" << endl;
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            cout << matrix[x][y] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "ls:";
    for(int x = 0; x < n; x++) {
        cout << ls[x] << " ";
    }

    cout << endl;
    cout << "lo:";
    for(int x = 0; x < m; x++) {
        cout << lo[x] << " ";
    }
}

int main(int argc, const char * argv[]) {
    int n, m, maxLevels;

    n = 5;
    m = 5;
    maxLevels = 3;

    int* ls = new int[n];
    int* lo = new int[m];


    // 0 - w, 1 - r
    int** matrix = new int*[n];

    for(int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }

    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            matrix[x][y] = rand() % 2;
        }
    }

    for(int x = 0; x < n; x++) { ls[x] = rand() % maxLevels + 1; }
    for(int x = 0; x < m; x++) { lo[x] = rand() % maxLevels + 1; }

    cout << checkSystem(n, m, ls, lo, matrix) << endl;
    printSystem(n, m, ls, lo, matrix);
    cout << endl;

    return 0;
}
