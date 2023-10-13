#include <iostream>
#include <vector>
#include <chrono>
#include <bitset>

const int MAX = 2500;

std::bitset<MAX + 1> isPrime; 

void findPrime() {
    isPrime.set();  
    isPrime[0] = isPrime[1] = 0;

    for (int p = 2; p * p <= MAX; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= MAX; i += p) {
                isPrime[i] = 0;
            }
        }
    }
}

int main() {
    auto start = std::chrono::high_resolution_clock::now(); 
    findPrime();
    auto end = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> duration = end - start;

    std::cout << "Prime number generation took " << duration.count() << " seconds." << std::endl;

    start = std::chrono::high_resolution_clock::now(); 

    std::vector<int> uniquePrimes;

    for (int i = 2; i <= MAX; i++) {
        if (isPrime[i]) {
            uniquePrimes.push_back(i);
        }
    }

    end = std::chrono::high_resolution_clock::now(); 
    duration = end - start;

    std::cout << "Prime factorization took " << duration.count() << " seconds." << std::endl;

    return 0;
}
