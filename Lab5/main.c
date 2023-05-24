#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEN 100
#define TWO 2
#define ONE 1
#define ZERO 0


/*
 * Scans all the numbers in a line and stores it in a char array.
 * Converts each line of binary numbers to decimal.
 */
void convertToDecimal(char *fileName, FILE *filePtr, char *line, int rows, int col) {
    // Check if file is empty
    if (filePtr == NULL) {
        printf("Unable to open the file: %s", fileName);
    } else {
        while (fgets(line, rows, filePtr) ) {
            char number[TWO];
            char numberStr[MAX_LINE_LEN];

            for (int i = ZERO; i < col; i++) {
                fscanf(filePtr, "%s", number);
                numberStr[i] = number[ZERO];
            }
            numberStr[col] = '\0';

            long decimal = strtol(numberStr, NULL, TWO);
            printf("%ld\n", decimal);
        }
    }

    fclose(filePtr);
}


/*
 * Opens the file and gets the number of rows and columns.
 */
void openFile(char *fileName) {
    FILE *filePtr = fopen(fileName, "r");
    char line[MAX_LINE_LEN];

    // Stores number of rows and columns
    int rows, col;
    fscanf(filePtr, "%d %d", &rows, &col);

    convertToDecimal(fileName, filePtr, line, rows, col);
}


/*
 * Checks the number of arguments passed and stores the filename argument.
 */
void checkArguments(int argc, char* argv[]) {
    // If number of arguments is 2, it's valid (1 for the current directory and 1 for the file being read)
    if(argc == TWO) {
        char *fileName = argv[ONE];

        openFile(fileName);
    } else {
        printf("\nNumber of arguments passed must be 2. Number of arguments you passed: %d.\n", argc);
    }
}


int main(int argc, char* argv[]) {
    checkArguments(argc, argv);

    return 0;
}
