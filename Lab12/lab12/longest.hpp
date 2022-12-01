//
//  Longest.hpp
//  lab12
//
//  Created by Delta Null on 01.12.2022.
//

#ifndef longest_hpp
#define longest_hpp

#include <bitset>
#include <stdio.h>
#include <string>
#include <math.h>

#define LONGEST_SIZE 128

using namespace std;

struct ulongest {
private:
    bitset<LONGEST_SIZE> value;
    
public:
    ulongest(const long long& num) {
        this->value = bitset<LONGEST_SIZE>();
        long long value = num;
        
        int iterator = LONGEST_SIZE - 1;
        
        while(iterator >= 0) {
            this->value[iterator] = value % 2;
            iterator--;
            value /= 2;
        }
    }
    
    int toInt() {
        int result = 0;
        for(int i = LONGEST_SIZE - 1; i >= 0; i--) {
            result += this->value[i] * pow(2, LONGEST_SIZE - 1 - i);
        }
        return result;
    }
    
    bool operator==(const ulongest& num) const {
        return num.value == this->value;
    }
    
    bool operator!=(const ulongest& num) const {
        return !(*this == num);
    }
    
    bool operator<(const ulongest& num) const {
        return !(*this > num) && (*this != num);
    }
    
    bool operator<=(const ulongest& num) const {
        return (*this < num) || (*this == num);
    }
    
    bool operator>=(const ulongest& num) const {
        return (*this > num) || (*this == num);
    }
    
    bool operator>(const ulongest& num) const {
        for(int i = 0; i < LONGEST_SIZE; i++) if (this->value[i] != num.value[i]) return this->value[i] > num.value[i];
        return false;
    }
    
    ulongest operator+(const ulongest& num) const {
        ulongest result = ulongest(0);
        
        bool needAdd = false;
        for(int i = LONGEST_SIZE - 1; i >= 0; i--) {
            if (this->value[i] == 1 && num.value[i] == 1) {
                result.value[i] = needAdd ? 1 : 0;
                needAdd = true;
            } else {
                result.value[i] = this->value[i] + num.value[i];
                
                if (needAdd) {
                    if (result.value[i] == 1) {
                        result.value[i] = 0;
                        needAdd = true;
                    } else {
                        result.value[i] = 1;
                        needAdd = false;
                    }
                }
            }
        }
        
        return result;
    }
    
    ulongest& operator+=(const ulongest& num) {
        *this = *this + num;
        return *this;
    }
    
    
    ulongest& operator++() {
        *this += ulongest(1);
        return *this;
    }
    
    ulongest operator++(int) {
        ulongest temp = *this;
        *this += 1;
        return temp;
    }
    
    ulongest operator-(const ulongest& num) const {
        ulongest result = ulongest(0);
        result.value = this->value;
        
        
        result.value.flip();
        
        result = result + ulongest(1) + num;
        
        result.value.flip();
        
        result = result + ulongest(1);
        
        return result;
    }
    
    ulongest operator*(const ulongest& num) const {
        ulongest result = ulongest(0);
        
        for(int i = LONGEST_SIZE - 1; i >= 0; i--) {
            if (num.value[i] == 1) {
                result = result + (*this << (LONGEST_SIZE - 1 - i));
            }
        }
        
        return result;
    }
    
    ulongest operator<<(const int& num) const {
        ulongest result = ulongest(0);
        result.value = this->value;
        result.value >>= num;
        return result;
    }
    
    ulongest operator>>(const int& num) const {
        ulongest result = ulongest(0);
        result.value = this->value;
        result.value <<= num;
        return result;
    }
    
    ulongest operator%(const ulongest& num) const {
        ulongest result = ulongest(0);
        ulongest div = ulongest(0);
        
        result.value = this->value;
        div.value = num.value;

        while(result >= div) {
            result = result - div;
        }
        
        return result;
    }
};

#endif /* Longest_hpp */
