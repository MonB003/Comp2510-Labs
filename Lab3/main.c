#include <stdio.h>
#include <string.h>

#define SPACE_CHARACTER ' '


/*
 * Takes an input string and prints out each token (not white space)
 */
void printTokenizedString(char* inputString) {
    char newArray[strlen(inputString)];
    strcpy(newArray, inputString);
    size_t strLength = strlen(inputString);

    // Loop through each character in the string parameter
    for (int i = 0; i < strLength; i++) {
        if (newArray[i] != SPACE_CHARACTER) {
            // Prints character if it isn't white space
            printf("%c", newArray[i]);
        }

        if (newArray[i] != SPACE_CHARACTER && newArray[i+1] == SPACE_CHARACTER) {
            // When it's at the end of a word, print a newline character
            printf("\n");
        }
    }
    printf("\n");
}


int main() {
    // 4 Test Cases
    char* test1 = "     Are you enjoying   coding ?  ";
    printf("Test case 1:\n");
    printTokenizedString(test1);
    char* test2 = "This is a normal string with no trailing and leading spaces";
    printf("Test case 2:\n");
    printTokenizedString(test2);
    char* test3 = "   ";
    printf("\nTest case 3:\n");
    printTokenizedString(test3);
    char* test4 = "     Hello!";
    printf("Test case 4:\n");
    printTokenizedString(test4);

    return 0;
}
