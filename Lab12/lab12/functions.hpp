//
//  functions.hpp
//  lab12
//
//  Created by Delta Null on 30.11.2022.
//

#include <stdio.h>
#include <vector>
#include "longest.hpp"

using namespace std;

ulongest pow(ulongest x, ulongest n, ulongest y) {
    ulongest result = x % n;
    for(ulongest i = 1; i < y; i++) {
        result = (result * x) % n;
    }
    
    return result;
}

ulongest gcd(ulongest a, ulongest b) {
    return b == 0 ? a : gcd(b, a % b);
}

ulongest getEasy(ulongest of) {
    vector<ulongest> easys = vector<ulongest>();
    for(ulongest i = 2; i < of; i++) if (gcd(of, i) == 1) easys.push_back(i);
    return easys[rand() % easys.size()];
}

ulongest eiler(ulongest n) {
    ulongest result = 0;
    for(ulongest i = 1; i <= n; i++) if (gcd(n, i) == 1) result++;
    return result;
}

ulongest getD(ulongest e, ulongest nEiler) {
    ulongest d = 1;
    while((d * e) % nEiler != 1) d++;
    return d;
}

bool isGenerator(ulongest value, ulongest p) {
    set<ulongest> values = set<ulongest>();
    ulongest currentValue = value;
    
    for(ulongest i = 0; i < p - 1; i++) {
        currentValue = (currentValue * value) % p;
        if (values.contains(currentValue)) return false;
        values.insert(currentValue);
    }
        
    return true;
}

ulongest getG(ulongest n) {
    for(ulongest i = 1; i < n; i++) if (isGenerator(i, n)) return i;
    return -1;
}
