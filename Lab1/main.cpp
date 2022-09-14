//
//  main.cpp
//  IBLab1
//
//  Created by Rustam Khakhuk on 14.09.2022.
//

#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>

using namespace std;

vector<pair<int, int>> pairs = vector<pair<int, int>>();

int xnor(int a, int b)
{
    int result = 0;

    for(int i = 0; i < 10; i++) {
        if (a / int(pow(2, i)) % 2 == b / int(pow(2, i)) % 2) {
            result += pow(2,i);
        }
    }

    return result;
}


int convert(string s) {
    int result = 0;
    for(int i = 0; i < 10; i++) {
        if (s[i] == 't') {
            result += pow(2, i);
        }
    }
    return result;
}

string convert(int n) {
    string result = "";
    for(int i = 0; i < 10; i++) {
        if (n % 2 == 1) {
            result += 't';
        } else {
            result += 'f';
        }
        n /= 2;
    }
    return result;
}

int rightAnswers(string s) {
    return stoi(string(1, s[10]));
}

int onesCount(int value) {
    int onesCount = 0;
    while(value > 0) {
        if (value % 2 == 1) {
            onesCount += 1;
        }
        value /= 2;
    }

    return onesCount;
}

bool checkAnswer(int answer) {
    for(int i = 0; i < pairs.size(); i++) {
        if (onesCount(xnor(answer, pairs[i].first)) != pairs[i].second) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    string s;
    getline(cin,s);

    for(int i = 0; i < N; i++) {
        getline(cin, s);
        pairs.push_back(pair<int, int>(convert(s), rightAnswers(s)));
    }

    int countOfAnswers = 0;
    int lastSolution = -1;
    for(int i = 0; i < pow(2, 10); i++) {
        if (checkAnswer(i)) {
            countOfAnswers += 1;
            lastSolution = i;
        }
    }

    if (countOfAnswers == 1) {
        cout << "ONE SOLUTION" << endl;
    } else {
        cout << "POSSIBLE SOLUTION" << endl;
    }
    cout << convert(lastSolution);

    return 0;
}
