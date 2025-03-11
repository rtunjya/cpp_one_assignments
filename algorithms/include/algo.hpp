#ifndef ALGO_H_
#define ALGO_H_

#include "types.hpp"

inline long fibonacci(const int n)
{
    if (n <= 1) {
        return n;
    }
    long a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        long temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

inline int linear_search(const Array * a, const int target)
{
    for (size_t i = 0; i < a->len; i++) {
        if (a->data[i] == target) {
            return i;
        }
    }
    return -1;
}

inline long factorial(const int n)
{
    if (n == 0 || n == 1) {
        return 1;
    }
    long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

#endif // ALGO_H_
