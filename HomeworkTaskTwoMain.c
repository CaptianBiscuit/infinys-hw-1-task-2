#include <stdio.h>

int fibonacci(int number);
void getClosestFibonacciNumber(int number, int *outFibonacciNumber, int *outSequenceCounter);

int main() {

    int inputNumber = 0;
    int sequenceCounter = 0;
    int fibonacciNumber = 0;

    printf("Input number:");
    scanf("%d", &inputNumber);

    getClosestFibonacciNumber(inputNumber, &fibonacciNumber, &sequenceCounter);

    printf("%d - %d, %d\n", inputNumber, fibonacciNumber, sequenceCounter);

    return 0;
}

int fibonacci(int number) {
    if (number <= 1) {
        return number;
    } else {
        return fibonacci(number - 1) + fibonacci(number - 2);
    }
}

void getClosestFibonacciNumber(int number, int *outFibonacciNumber, int *outSequenceCounter) {

    int sequenceCounter = 0;
    int fibonacciNumber = 0;

    if (number <= 1) {
        *outFibonacciNumber = 1;
        *outSequenceCounter = 1;
    } else {

        while (fibonacciNumber <= number) {
            fibonacciNumber = fibonacci(sequenceCounter);
            sequenceCounter++;
        }

        int minLimit = fibonacci(sequenceCounter - 2);
        int maxLimit = fibonacci(sequenceCounter - 1);

        float mean = (minLimit + maxLimit) / 2.00f;

        if (mean >= number) {
            *outFibonacciNumber = minLimit;
            *outSequenceCounter = sequenceCounter - 2;
        } else if (mean < number) {
            *outFibonacciNumber = maxLimit;
            *outSequenceCounter = sequenceCounter - 1;
        }
    }
}