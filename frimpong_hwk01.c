#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 30

int main() {
    int array[SIZE] = {0, 15, 20, 1, 100, 0, 60, 1, 75, 29, 1, 69, 100, 91, 56, 1, 89, 0, 98, 1, 
                       45, 100, 0, 78, 59, 11, 0, 0, 1, 100}; 
    
    int n = SIZE; // Total number of elements

    // Mode Calculation (Assuming exactly one mode)
    int mat[SIZE][2];  // To store values and their frequencies
    int b, j, counter;
    int counted[SIZE] = {0};  // Mark counted elements

    // Populate mat with values and their frequencies
    for (b = 0; b < n; ++b) {
        if (counted[b]) continue;
        mat[b][0] = array[b];
        counter = 1;

        for (j = b + 1; j < n; ++j) {
            if (array[j] == array[b]) {
                counter++;
                counted[j] = 1;
            }
        }
        mat[b][1] = counter;
        counted[b] = 1;
    }

    // Find the mode (the element with the highest frequency)
    int max = mat[0][1];
    for (b = 1; b < n; ++b) {
        if (mat[b][1] > max) {
            max = mat[b][1];
        }
    }

    // Print all modes
    printf("Modes with frequency %d: ", max);
    for (b = 0; b < n; ++b) {
        if (mat[b][1] == max) {
            printf("%d ", mat[b][0]);
        }
    }
    printf("\n");

    // Calculate the mean
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += array[i];
    }
    double mean = sum / n;
    printf("Mean = %lf\n", mean);

    // Calculate the standard deviation
    double variance = 0.0;
    for (int i = 0; i < n; ++i) {
        variance += pow(array[i] - mean, 2);
    }
    variance /= n;
    double std_dev = sqrt(variance);
    printf("Standard Deviation = %lf\n", std_dev);

    return 0;
}

