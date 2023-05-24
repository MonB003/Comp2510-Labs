#include <stdio.h>
#include <stdbool.h>

/*
 * Checks and prints out whether the parameter integer is
 * positive or negative, and even or odd
 */
void checkInteger(int x) {
    // If parameter x is greater than 0, it's positive
    if (x > 0) {
        printf("%d is positive", x);

        // When dividing x by 2, if the remainder is 0, it's even
        if (x % 2 == 0) {
            printf(" even\n");
        } else {
            // If the remainder is not 0, it's odd
            printf(" odd\n");
        }

        // If parameter x is less than 0, it's negative
    } else if (x < 0) {
        printf("%d is negative", x);

        // When dividing x by 2, if the remainder is 0, it's even
        if (x % 2 == 0) {
            printf(" even\n");
        } else {
            // If the remainder is not 0, it's odd
            printf(" odd\n");
        }

    } else {
        // X is not less or greater than 0, this means it's 0
        printf("Number is zero\n");
    }
}


/*
 * Takes an array of integers and checks if the array is a palindrome
 */
bool isPalindrome(int elements[], int size) {
    // Stores true or false depending on if array is palindrome
    bool palindrome = true;

    // Current left and right positions in array
    int leftPos = 0;
    int rightPos = size - 1;

    do {
        // Compare left and right values in the array
        // If the values at those indexes don't match, the array isn't a palindrome
        if (elements[leftPos] != elements[rightPos]) {
            palindrome = false;
        }

        // Increment left index and decrement right index
        leftPos++;
        rightPos--;

        // Loop runs while the left index is less than or equal to the right index value
    } while (leftPos <= rightPos);


    // Print array elements
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", elements[i]);
    }

    // Print if array is a palindrome or not
    if (palindrome == true) {
        printf("\nArray is a palindrome\n\n");
    } else {
        printf("\nArray is not a palindrome\n\n");
    }

    return palindrome;
}


int main() {
    printf("Check Integer Method:\n");

    // 5 test cases for checkInteger() method
    checkInteger(3);
    checkInteger(-3);
    checkInteger(4);
    checkInteger(-4);
    checkInteger(0);

    printf("\nPalindrome Method:\n");

    // 3 test cases for isPalindrome() method

    int boolArray1[] = {7, 5, 3, 1, 3, 5, 7};
    bool boolTest1 = isPalindrome(boolArray1, 7);

    int boolArray2[] = {1, 2, 3, 4, 5, 6};
    bool boolTest2 = isPalindrome(boolArray2, 6);

    int boolArray3[] = {1};
    bool boolTest3 = isPalindrome(boolArray3, 1);

    return 0;
}
