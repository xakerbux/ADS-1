
// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <cmath>
#include <vector>


bool checkPrime(uint64_t value) {
  if (value < 2) return false;
    if (value == 2) return true;
    if (value % 2 == 0) return false;
    
    uint64_t limit = static_cast<uint64_t>(std::sqrt(value));
    for (uint64_t i = 3; i <= limit; i += 2) {
        if (value % i == 0) return false;
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) return 0;
    if (n == 1) return 2;
    
    uint64_t count = 1; 
    uint64_t candidate = 3;
    
    while (count < n) {
        if (checkPrime(candidate)) {
            count++;
        }
        if (count < n) {
            candidate += 2;
        }
    }
    return candidate;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t candidate = value + 1;
    while (!checkPrime(candidate)) {
        candidate++;
    }
    return candidate;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; i++) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
    
    for (uint64_t i = lbound; i < hbound - 2; i++) {
        if (checkPrime(i) && checkPrime(i + 2)) {
            if (i >= lbound && (i + 2) < hbound) {
                count++;
            }
        }
    }
    return count;
}
