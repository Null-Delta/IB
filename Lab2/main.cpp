#include<iostream>
#include<math.h>
#include<string.h>

using namespace std;

int findSubstringIndex(string content, string subString, int fromIndex) {
    for(int index = fromIndex; index <= content.size() - subString.size(); index++) {
        if (content.substr(index, subString.size()) == subString) {
            return index;
        }
    }

    return -1;
}

string format(string substr, int repeateCount) {
    return to_string(repeateCount) + "(" + substr + ")";
}

string zipRepeate(string input, int repeateSize) {
    string result = input;

    for(int index = 0; index < result.size() - repeateSize; index++) {

        string subStr = result.substr(index,repeateSize);
        int currentSubStringIndex = index;
        int repeateCount = 1;

        while(findSubstringIndex(result, subStr, currentSubStringIndex + repeateSize) == currentSubStringIndex + repeateSize) {
            repeateCount++;
            currentSubStringIndex += repeateSize;
        }

        if (repeateCount > 1) {
            result.erase(index, currentSubStringIndex + repeateSize - index);
            result.insert(index, format(subStr, repeateCount));
            return result;
        } else {
            index++;
        }
    }

    return result;
}


int main() {
    string s;
    getline(cin, s);

    for(int length = 1; length <= s.size() / 2; length++) {
        string newS = zipRepeate(s, length);

        while(newS != s) {
            cout << newS << endl;
            s = newS;
            newS = zipRepeate(s, length);
        }
    }
}