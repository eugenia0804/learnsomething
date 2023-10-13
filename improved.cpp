#include <iostream>
#include <vector>
#include <chrono>

std::vector<int> sieveOfEratosthenes(int n) {
    std::vector<bool> isPrime(n + 1, true);
    std::vector<int> primes;
    
    isPrime[0] = isPrime[1] = false;
    
    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
    
    for (int p = 2; p <= n; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }
    
    return primes;
}

std::vector<int> primeFactors(int n, const std::vector<int>& primes) {
    std::vector<int> uniquePrimes;

    for (int prime : primes) {
        while (n % prime == 0) {
            uniquePrimes.push_back(prime);
            n /= prime;
        }
    }

    if (n > 1) {
        uniquePrimes.push_back(n);
    }

    return uniquePrimes;
}

int main() {
    const int MAX = 2500;

    auto start = std::chrono::high_resolution_clock::now(); // Start the timer
    std::vector<int> primes = sieveOfEratosthenes(MAX);
    auto end = std::chrono::high_resolution_clock::now(); // End the timer
    std::chrono::duration<double> duration = end - start;
    
    std::cout << "Prime number generation took " << duration.count() << " seconds." << std::endl;

    start = std::chrono::high_resolution_clock::now(); // Start the timer
    for (int i = 2; i <= MAX; i++) {
        std::vector<int> factors = primeFactors(i, primes);
        
        if (factors.size() == 1 && factors[0] == i) {
            std::cout << i << " is prime." << std::endl;
        }
    }
    end = std::chrono::high_resolution_clock::now(); // End the timer
    duration = end - start;
    
    std::cout << "Prime factorization took " << duration.count() << " seconds." << std::endl;

    return 0;
}
