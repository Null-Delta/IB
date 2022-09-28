#include<iostream>
#include<fstream>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

double factorial(int num) {
    return num <= 1 ? 1.0 : factorial(num - 1) * double(num);
}

bool isEasy(int num) {
    for(int i = 2; i < sqrt(num); i++) {
        if (num % i == 0) return false;
    }

    return true;
}

int nextEasy(int after) {
    for(int i = after + 1; ; i++) {
        if (isEasy(i)) return i;
    }

    return -1;
}

bool divide(int num, int diver) {
    double divResult = double(num) / double(diver);
    return divResult == floor(divResult);
}

vector<int> parts(int of, int minEasy = 2, vector<int> totalParts = vector<int>()) {
    if (of == 1) {
        return totalParts;
    } else {
        if (divide(of, minEasy)) {
            totalParts.push_back(minEasy);
            return parts(of / minEasy, minEasy, totalParts);
        } else {
            return parts(of, nextEasy(minEasy), totalParts);
        }
    }
}

int f(int num) {
    vector<int> values = parts(num);
    vector<int> counts = vector<int>();

    double bottomFactorial = 1;

    counts.push_back(1);

    for(int i = 1; i < values.size(); i++) {
        if (values[i] != values[i - 1]) {
            bottomFactorial *= factorial(counts[counts.size() - 1]);
            counts.push_back(1);
        } else {
            counts[counts.size() - 1]++;
        }
    }

    bottomFactorial *= factorial(counts[counts.size() - 1]);

    return factorial(values.size()) / bottomFactorial;
}

int main() {
    fstream input;
    fstream output;
    input.open("input.txt");
    output.open("output.txt");

    while(!input.eof()) {
        int n;
        input >> n;
        int value = 2;
        for(; f(value) != n; value++) { }
        output << n << " " << value << endl;
    }

    input.close();
    output.close();

    cout << "finish";
}

