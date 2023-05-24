#include <stdio.h>

#define CITY 2
#define DAYS 7
#define ONE 1

void resetTemperature(int temperature[CITY][DAYS]);
void printTemperature(int temperature[CITY][DAYS]);


// Prompt for user input and stores temperatures in a 2D array
void getTemperature(int temperature[CITY][DAYS]) {
    for (int city = 0; city < CITY; city++) {
        for (int day = 0; day < DAYS; day++) {
            int temp;
            printf("Enter temperature for city %d, day %d:\n", city+ONE, day+ONE);
            scanf("%d", &temp);
            temperature[city][day] = temp;
        }
    }

    printTemperature(temperature);
    resetTemperature(temperature);
}


// Asks for 2 cities and days, and changes those temperatures
void resetTemperature(int temperature[CITY][DAYS]) {
    printf("\nReset Temperatures\n");
    for (int city = 0; city < CITY; city++) {
        int day;
        int newTemp;
        printf("\nEnter a day:\n");
        scanf("%d", &day);
        printf("Enter new temperature for City %d, Day %d:\n", city+ONE, day);
        scanf("%d", &newTemp);
        temperature[city][day-ONE] = newTemp;
    }
    printf("\nUpdated Temperatures:");
    printTemperature(temperature);
}


// Prints each city and day's temperatures
void printTemperature(int temperature[CITY][DAYS]) {
    for (int city = 0; city < CITY; city++) {
        printf("\nCity %d Temperature over 7 days: ", city+ONE);
        for (int day = 0; day < DAYS; day++) {
            printf("%d  ", temperature[city][day]);
        }
    }
    printf("\n");
}


int main() {
    int temperatureArray[CITY][DAYS];
    getTemperature(temperatureArray);

    return 0;
}
