#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
#define THIRTY 30
#define ONE 1
#define NEG_ONE -1
#define ZERO 0

char queueArray[MAX_SIZE], front = NEG_ONE, rear = NEG_ONE;

void enQueue(char value) {
    if(rear == MAX_SIZE-ONE)
        printf("\nQueue is Full. Insertion is not possible.");
    else {
        if(front == NEG_ONE)
            front = ZERO;
        rear++;
        queueArray[rear] = value;
    }
}

void deQueue() {
    if (front == rear && rear != NEG_ONE) {
        printf("\n");
    } else {
        front++;
        if(front == rear) {
            front = rear = NEG_ONE;
        }
    }
}


void encodeString(size_t arraySize) {
    printf("\nEncoded string: ");

    for (int index = ZERO; index < arraySize; index++) {
        int asciiValue = (int) queueArray[index];
        char encodedLetter = (char) (asciiValue - THIRTY);
        printf("%c", encodedLetter);
        deQueue();
    }
    printf("\n");
}

void decodeString(size_t arraySize) {
    printf("\nDecoded string: \n");

    for (int index = ZERO; index < arraySize; index++) {
        int asciiValue = (int) queueArray[index];
        char decodedLetter = (char) (asciiValue + THIRTY);
        printf("%c", decodedLetter);
        deQueue();
    }
    printf("\n");
}


int main() {
    // ENCODE
    char encodedStr[MAX_SIZE];
    printf("Enter the string to encode: \n");
    scanf("%s", encodedStr);
    size_t strEncodeLength = strlen(encodedStr);

    for (int letter = ZERO; letter < strEncodeLength; letter++) {
        enQueue(encodedStr[letter]);
    }
    encodeString(strEncodeLength);


    // DECODE
    char decodedStr[MAX_SIZE];
    printf("\nEnter the string to decode: \n");
    scanf("%s", decodedStr);
    size_t strDecodeLength = strlen(decodedStr);

    for (int letter = ZERO; letter < strDecodeLength; letter++) {
        enQueue(decodedStr[letter]);
    }
    decodeString(strDecodeLength);

    return 0;
}
