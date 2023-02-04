//
//  main.cpp
//  lab14
//
//  Created by Delta Null on 15.12.2022.
//

#include <iostream>
#include <string>
#include "/Users/deltanull/Documents/GitHub/IB/lab14/ttmath/ttmath.h"



using namespace std;
using namespace ttmath;

struct point {
    Big<256, 256> x, y;
    
    point(Big<256, 256> x, Big<256, 256> y) {
        this->x = x;
        this->y = y;
    }
    
    point operator+(const point& p2) const {
        point result = point(0, 0);
        
        Big<256, 256> k = 0;
        if (this->x != p2.x) {
            k = (this->y - p2.y) / (this->x - p2.x);
        } else if (this->x == p2.x && this->y == p2.y && p2.y != 0){
            // k = (3 * this->x * this->x+a) / (2 * this->y);
        } else {
            k = 0;
        }
        
        result.x = k * k - this->x - p2.x;
        result.y = k * (this->x - result.x) - this->y;
        
        return result;
    }
    
    point mult(Big<256, 256> k) {
        point result = *this;
        
        for(Big<256, 256> i = 1; i < k; i = i + 1) {
            result = result + *this;
        }
        
        return result;
    }
};

Big<256, 256> hastToInt(bitset<256> set) {
    Big<256, 256> result = 0;
    
    for(int i = 0; i < 256; i++) {
        if (set[i] == 1) {
            Big<256, 256> val = 1;
            for(int i = 0; i < 256 - i; i++) {
                val *= 2;
            }
            result += val;
        }
    }
    
    return result;
}


int main(int argc, const char * argv[]) {
    Big<256, 256> r = 0;
    Big<256, 256> s = 0;
    cout << "start" << endl;
    
    while(r == 0 || s == 0) {

        Big<256, 256> d = 228;
        Big<256, 256> a = hastToInt(bitset<256>(rand()));
        Big<256, 256> q = 13;
        
        Big<256, 256> k = Big<256, 256>(rand());
        Big<256, 256> sk = k / q;
        k -= Big<256, 256>(Floor(sk)) * q;
        
        Big<256, 256> e = a;
        Big<256, 256> se = e / q;
        e -= Big<256, 256>(Floor(se)) * q;

        if (e == 0) { e = 1; }
                
        point p = point(Big<256,256>(13), Big<256,256>(11));

        point c = p.mult(k);
        
        r = c.x;
        Big<256, 256> rs = c.x / q;
        r -= Big<256, 256>(Floor(rs)) * q;

        Big<256, 256> s = (r * d + k * e);
        Big<256, 256> ss = s / q;
        ss -= Big<256, 256>(Floor(ss)) * q;
        cout << Floor(s) << " " << Floor(r) << endl;
        cout << (Floor(s) == 0) << " " << (Floor(r) == 0) << endl;
    }
    
    cout << Floor(r) << endl;
    cout << r << s << endl;
    return 0;
}
