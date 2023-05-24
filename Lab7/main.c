#include <stdio.h>
#include <stdbool.h>

// Returns true (1) if parameter number is a power of 2, otherwise it returns false (0)
bool isPowerOfTwo(int x) {
    if (x < 1) {
        return 0;
    }

    return ((x-1) & x) == 0;
}

int main() {
    bool test1 = isPowerOfTwo(2);   // True (1)
    bool test2 = isPowerOfTwo(5);   // False (0)
    bool test3 = isPowerOfTwo(32);  // True
    bool test4 = isPowerOfTwo(64);  // True
    bool test5 = isPowerOfTwo(125); // False
    bool test6 = isPowerOfTwo(1);   // True (2^0=1)
    printf("Test 1: %d\n", test1);
    printf("Test 2: %d\n", test2);
    printf("Test 3: %d\n", test3);
    printf("Test 4: %d\n", test4);
    printf("Test 5: %d\n", test5);
    printf("Test 6: %d\n", test6);
    return 0;
}
