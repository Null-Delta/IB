#include<iostream>
#include<fstream>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace std;

fstream file;

void printAll(int two = 2, int five = 2, int deep = 8, string result = "") {
    if (deep == 0) {
        file << result << endl;
    } else {
        if (two > 0) {
            printAll(two - 1, five, deep - 1, result + "2");
        }
        if (five > 0) {
            printAll(two, five - 1, deep - 1, result + "5");
        }
        if (deep != two + five) {
            printAll(two,five, deep - 1, result + "7");
        }
    }
}

int main() {
    file.open("output.txt");
    printAll();
    file.close();
}