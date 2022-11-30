//
//  functions.hpp
//  lab12
//
//  Created by Delta Null on 30.11.2022.
//

#include <stdio.h>
#include "BigInt.hpp"
#include <vector>

using namespace std;

BigInt pow(BigInt x, BigInt n, BigInt y) {
    BigInt result = x % n;
    for(BigInt i = 1; i < y; i++) {
        result = (result * x) % n;
    }
    
    return result;
}

BigInt gcd(BigInt a, BigInt b) {
    return b == 0 ? a : gcd(b, a % b);
}

BigInt getEasy(BigInt of) {
    vector<BigInt> easys = vector<BigInt>();
    for(BigInt i = 2; i < of; i++) if (gcd(of, i) == 1) easys.push_back(i);
    return easys[rand() % easys.size()];
}

BigInt eiler(BigInt n) {
    BigInt result;
    for(BigInt i = 1; i <= n; i++) if (gcd(n, i) == 1) result++;
    return result;
}

BigInt getD(BigInt e, BigInt nEiler) {
    BigInt d = 1;
    while((d * e) % nEiler != 1) d++;
    return d;
}

bool isGenerator(BigInt value, BigInt p) {
    set<BigInt> values = set<BigInt>();
    BigInt currentValue = value;
    
    for(int i = 0; i < p - 1; i++) {
        currentValue = (currentValue * value) % p;
        if (values.contains(currentValue)) return false;
        values.insert(currentValue);
    }
        
    return true;
}

BigInt getG(BigInt n) {
    for(BigInt i = 1; i < n; i++) if (isGenerator(i, n)) return i;
    return -1;
}

BigInt stringToInt(string message) {
    BigInt result;
    result = 0;
    
    for(int i = 0; i < message.size(); i++) {
        result = result * pow(2, sizeof(message[i]) * 8) + message[i];
    }
    
    return result;
}
