#include <iostream>
#include <random>
#include <cmath>

using namespace std;

// Function to perform modular exponentiation
long long modexp(long long x, long long y, long long p) {
    long long res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

// Function to perform the Miller-Rabin primality test
bool isPrime(long long n, int k) {
    // Handle base cases
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;
  
    // Find r such that n = 2^d * r + 1
    long long d = n - 1;
    while (d % 2 == 0)
        d /= 2;
  
    // Repeat the test k times
    for (int i = 0; i < k; i++) {
        // Generate a random number between 2 and n-2
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(2, n-2);
        long long a = dis(gen);
  
        // Compute a^d % n
        long long x = modexp(a, d, n);
  
        if (x == 1 || x == n-1)
            continue;
  
        // Repeat r-1 times
        for (long long j = 1; j <= x-1; j++) {
            x = modexp(x, 2, n);
  
            if (x == 1)
                return false;
            if (x == n-1)
                break;
        }
  
        if (x != n-1)
            return false;
    }
  
    return true;
}

int main() {
    long long n = 541;
    int k = 10;
    if (isPrime(n, k))
        cout << n << " is prime" << endl;
    else
        cout << n << " is not prime" << endl;
    return 0;
}


//time complexity of O(k * log^3(n))
