#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct arithmeticOperation arithOp;

// Structure
struct arithmeticOperation {
    float iResult;
    float (*one_operand_operation) (float);
    float (*two_operand_operation) (float,float);
};


// Functions
float modulus(float a, float b) {
    return fmod(a, b);
}

float power(float a, float b) {
    return pow(a, b);
}

float inverse(float a) {
    if (a == 0) {
        return 0;
    } else {
        return 1/a;
    }
}

float square(float a) {
    return a * a;
}


// Performs operations with one number
void performOneOperandCalculation(float x, struct arithmeticOperation *funPtr, const char *op) {
    if (strcmp(op, "square") == 0) {
        funPtr->one_operand_operation = square;
        funPtr->iResult = funPtr->one_operand_operation(x);

        printf("Square of %.2f = %.2f\n", x, funPtr->iResult);

    } else if (strcmp(op, "inverse") == 0) {
        funPtr->one_operand_operation = inverse;
        funPtr->iResult = funPtr->one_operand_operation(x);

        printf("Inverse of %.2f = %.2f\n", x, funPtr->iResult);
    }
}

// Performs operations with two numbers
void performTwoOperandCalculation(float x, float y, struct arithmeticOperation *funPtr, const char *op) {
    if (strcmp(op, "modulus") == 0) {
        funPtr->two_operand_operation = modulus;
        funPtr->iResult = funPtr->two_operand_operation(x, y);

        printf("Modulus of %.2f and %.2f = %.2f\n", x, y, funPtr->iResult);

    } else if (strcmp(op, "power") == 0) {
        funPtr->two_operand_operation = power;
        funPtr->iResult = funPtr->two_operand_operation(x, y);

        printf("%.2f to the power of %.2f = %.2f\n", x, y, funPtr->iResult);
    }
}


int main() {
    arithOp *calculator = (arithOp *) malloc(sizeof(arithOp));
    if (calculator == NULL) {
        printf("Memory allocation failed.\n");
        exit(0);
    }

    char operation[MAX_SIZE];
    printf("Enter an operation: \n");
    scanf("%s", operation);

    char numInput1[MAX_SIZE], numInput2[MAX_SIZE];

    // Check operation input and prompt for the appropriate amount of numbers
    if (strcmp(operation, "square") == 0 || strcmp(operation, "inverse") == 0) {
        printf("Enter one number: \n");
        scanf("%s", numInput1);
        float number = strtof(numInput1, NULL);

        performOneOperandCalculation(number, calculator, operation);

    } else if (strcmp(operation, "modulus") == 0 || strcmp(operation, "power") == 0) {
        printf("Enter two numbers: \n");
        scanf("%s %s", numInput1, numInput2);
        float number1 = strtof(numInput1, NULL);
        float number2 = strtof(numInput2, NULL);

        performTwoOperandCalculation(number1, number2, calculator, operation);

    } else {
        printf("Invalid operation.\n");
    }

    free(calculator);

    return 0;
}
