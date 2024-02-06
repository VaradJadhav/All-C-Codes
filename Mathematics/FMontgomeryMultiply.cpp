#include <iostream>
#include <cstdint>


//Montgomery multiplication is an efficient method for modular multiplication

// Calculate the modular inverse of a with respect to m
uint64_t modInverse(uint64_t a, uint64_t m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now, process same as Euclid's Algorithm
        m = a % m;
        a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Calculate the Montgomery product of two numbers a and b
uint64_t montgomeryMultiply(uint64_t a, uint64_t b, uint64_t n, uint64_t nPrime, uint64_t r) {
    uint64_t t = a * b;
    uint64_t m = (t * nPrime) % r;
    uint64_t u = (t + m * n) / r;
    
    if (u >= n) {
        return u - n;
    } else {
        return u;
    }
}

int main() {
    uint64_t a = 12345678; // Replace with your values
    uint64_t b = 87654321; // Replace with your values
    uint64_t n = 1000000007; // Replace with your modulo value
    uint64_t r = 1ULL << 32; // A power of 2 that's greater than n
    uint64_t nPrime = modInverse(n, r);

    uint64_t result = montgomeryMultiply(a, b, n, nPrime, r);
    
    std::cout << "Montgomery Product of " << a << " and " << b << " modulo " << n << " is: " << result << std::endl;
    
    return 0;
}
