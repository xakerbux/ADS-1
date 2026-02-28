// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <cmath>
#include <vector>


bool checkPrime(uint64_t value) {
  // вставьте код функции

    if (value <= 1) return false;
    if (value == 2) return true;
    
    uint64_t sd = 1; 
    
  
    for (uint64_t i = 2; i < value; ++i) {
        if (value % i == 0) {
            sd += i;
        }
    }
    return sd == 1;
  return true;
}

uint64_t nPrime(uint64_t n) {
  // вставьте код функции

  if (n == 0) return 0;
    if (n == 1) return 2;
    
    uint64_t count = 1;
    uint64_t c = 3;
    
    while (count < n) {
        if (checkPrime(c)) {
            count++;
        }
        c += 2;
    }
    
    return c - 2;
  return 2;
}

uint64_t nextPrime(uint64_t value) {
  // вставьте код функции

  uint64_t cdt = value + 1;
    
    
    if (cdt % 2 == 0 && cdt > 2) {
        cdt++;
    }
    
    while (!checkPrime(cdt)) {
        cdt += 2; 
    }
    
    return cdt;
  return 2;
}

uint64_t sumPrime(uint64_t hbound) {
  // вставьте код функции

  uint64_t sum = 0;
    
    for (uint64_t i = 2; i < hbound; ++i) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    
    return sum;
  
  return 2;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  // вставьте код функции

  uint64_t count = 0;
    
    for (uint64_t i = lbound; i < hbound - 2; ++i) {
        if (checkPrime(i) && checkPrime(i + 2)) { 
            if (i + 2 < hbound) {
                count++;
            }
        }
    }
    
    return count;
  
  return 1;
}
