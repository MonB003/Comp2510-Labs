#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100


/*
 * Stores each character in the str parameter into the temp array reversed,
 * Returns the temp array once all the characters have been stored
 */
char* reverse(char str[], char temp[], size_t strPos, int tempPos) {

    if (strPos != -1) {
        temp[tempPos] = str[strPos];
        tempPos++;
        strPos--;
        return reverse(str, temp, strPos, tempPos);
    } else {
        return temp;
    }
}


/*
 * Takes the user's input string, creates a temp array to store the characters backwards,
 * and calls the reverse method if the str passed is not empty
 */
char* reverseOfString(char str[]) {
    // Stores str parameter position, starting from the last character and decrementing until 0
    size_t strPos = strlen(str) - 1;

    // Stores temp array position starting from 0 and incrementing until the length of str
    int tempPos = 0;

    static char temp[MAX_SIZE];

    if (str != NULL) {
        // Call helper function to reverse characters
        reverse(str, temp, strPos, tempPos);
        return temp;

    } else {
        return "";
    }
}


int main() {
    char string[MAX_SIZE];

    printf("Enter a string: ");
    scanf("%s", string);

    char *backwardsString = reverseOfString(string);
    printf("Backwards: %s", backwardsString);

    return 0;
}
