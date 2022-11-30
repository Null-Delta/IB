//
//  main.cpp
//  lab12
//
//  Created by Delta Null on 30.11.2022.
//

#include <iostream>
#include <string>
#include <vector>
#include "BigInt.hpp"
#include <set>
#include "functions.hpp"

using namespace std;

struct RsaEncrypter {
private:
    BigInt e, n;

public:
    RsaEncrypter(BigInt e, BigInt n) {
        this->e = e;
        this->n = n;
    }
    
    BigInt encrypt(BigInt message) {
        return pow(message, n, e);
    }
};

struct RsaDecrypter {
private:
    BigInt d, n;
    
public:
    RsaDecrypter(BigInt d, BigInt n) {
        this->d = d;
        this->n = n;
    }
    
    BigInt decrypt(BigInt message) {
        return pow(message, n, d);
    }
};

struct ElGamalEncrypter {
private:
    BigInt y, g, p;
    
public:
    ElGamalEncrypter(BigInt y, BigInt g, BigInt p) {
        this->y = y;
        this->g = g;
        this->p = p;
    }
    
    pair<BigInt, BigInt> encrypt(BigInt message) {
        BigInt k = getEasy(p - 1);
        return pair<BigInt, BigInt>(pow(g, p, k), (pow(y, p, k) * message) % p);
    }
};

struct ElGamalDecrypter {
private:
    BigInt x, p;
    
public:
    ElGamalDecrypter(BigInt x, BigInt p) {
        this->x = x;
        this->p = p;
    }
    
    BigInt decrypt(pair<BigInt, BigInt> message) {
        return (message.second * pow(message.first, p, p - 1 - x)) % p;
    }
};

pair<RsaEncrypter, RsaDecrypter> RsaGenerate(BigInt p, BigInt q) {
    BigInt n = p * q;
    BigInt nEiler = (p - 1) * (q - 1);
    BigInt e = getEasy(nEiler);
    BigInt d = getD(e, nEiler);

    return pair<RsaEncrypter, RsaDecrypter>(RsaEncrypter(e, n), RsaDecrypter(d, n));
}

pair<ElGamalEncrypter, ElGamalDecrypter> ElGamalGenerate(BigInt p) {
    BigInt g = getG(p);
    BigInt x = rand() % (p - 1) + 1;
    BigInt y = pow(g, p, x);

    return pair<ElGamalEncrypter, ElGamalDecrypter>(ElGamalEncrypter(y, g, p), ElGamalDecrypter(x, p));
}

void RsaExample() {
    BigInt p = 5, q = 7;
    
    pair<RsaEncrypter, RsaDecrypter> rsa = RsaGenerate(p, q);
    
    BigInt message = 24;
    cout << "Message: " << message << endl;
    
    BigInt encryptedMessage = rsa.first.encrypt(message);
    cout << "Encrypted message: " << encryptedMessage << endl;
    
    BigInt dectyptedMessage = rsa.second.decrypt(encryptedMessage);
    cout << "Decrypted message: " << dectyptedMessage << endl;
}

void ElGamalExample() {
    BigInt p = 997;
    
    pair<ElGamalEncrypter, ElGamalDecrypter> elGamal = ElGamalGenerate(p);
    
    BigInt message = 228;
    cout << "Message: " << message << endl;

    pair<BigInt, BigInt> encryptedMessage = elGamal.first.encrypt(message);
    cout << "Encrypted message: (" << encryptedMessage.first << ", " << encryptedMessage.second << ")" << endl;
    
    BigInt decryptedMessage = elGamal.second.decrypt(encryptedMessage);
    cout << "Decrypted message: " << decryptedMessage << endl;
}
int main() {
    RsaExample();
    ElGamalExample();
}
