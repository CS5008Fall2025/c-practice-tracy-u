/**
 * Student Name: Tracy Urquhart
 * Semester: Fall 2025
 * 
 * 
 * This file is to test the functions in cpractice.h. You are to write at least *TWO* (maybe more) tests for every function. 
 * Some sample ones have been provided for you.
*/

#include <stdio.h>  // basic input and output
#include <stdlib.h> // standard library

#include "cpractice.h" // header file for cpractice.c


// this may help with some tests, as the array numbers match their index
int * create_simple_array(int size) {
    int * arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr;
}

/**
 * Tests a basic swap
*/
int test_swap_one() {
    printf("1. test_swap_one()\n");
    int a = 5;
    int b = 10;
    swap(&a, &b);
    if (a == 10 && b == 5) {
        return 1;
    }
    return 0;
}

/**
 * Tests the create_array_of_ints_fib function
*/
int test_create_array_of_ints_fib() {
    printf("2. test_create_array_of_ints_fib()\n");
    int* arr = create_array_of_ints_fib(5);
    int expected[] = {1, 1, 2, 3, 5};
    for (int i = 0; i < 5; i++) {
        if (arr[i] != expected[i]) {
            free(arr);
            return 0;
        }
    }
    free(arr); // note expected does not need freed.. why is that?
    // everything matched
    return 1;
}

int test_reverse_array() {
    printf("3. test_reverse_array()\n");
    int* arr = create_simple_array(5);
    reverse_array(arr, 5);
    int expected[] = {4, 3, 2, 1, 0};
    for (int i = 0; i < 5; i++) {
        if (arr[i] != expected[i]) {
            return 0;
        }
    }
    // everything matched
    return 1;
}


int test_double_array_size() {
    printf("4. test_double_array_size()\n");
    int* arr = create_simple_array(5);
    int* doubled = double_array_size(arr, 5);
    int expected[] = {0, 1, 2, 3, 4, 0, 0, 0, 0, 0};
    // check values
    for (int i = 0; i < 10; i++) {
        if (doubled[i] != expected[i]) {
            return 0;
        }
    }
    // everything passed
    return 1;
}

int test_copy_array_start_end_loop(){
    printf("5. test_copy_array_start_end_loop()\n");
    int arr[] = {1, 2, 3, 4, 5};

    // test 1: invalid
    int new_size = 3;
    int* invalid1 = copy_array_start_end_loop(arr, 5, -1, 3, &new_size); // start less than 0
    int* invalid2 = copy_array_start_end_loop(arr, 5, 5, 3, &new_size); // start equal to size
    int* invalid3 = copy_array_start_end_loop(arr, 5, 6, 3, &new_size); // start > size
    int* invalid4 = copy_array_start_end_loop(arr, 5, 1, 5, &new_size); // end equal to size
    int* invalid5 = copy_array_start_end_loop(arr, 5, 1, 6, &new_size); // end > size
    if(invalid1 != NULL | invalid2 != NULL | invalid3 != NULL | invalid4 != NULL | invalid5 != NULL) {
        return 0;
    }

    // test 2: valid
    int expected1[] = {2, 3, 4};
    int *looped1 = copy_array_start_end_loop(arr, 5, 1, 3, &new_size);
    for (int i = 0; i < 3; i++) {
        if (looped1[i] != expected1[i]) {
            return 0;
        }
    }

    // test 3: valid
    int new_size2 = 4;
    int expected2[] = {4, 5, 1, 2};
    int *looped2 = copy_array_start_end_loop(arr, 5, 3, 1, &new_size2);
    for (int i = 0; i < 4; i++) {
        if (looped2[i] != expected2[i]) {
            return 0;
        }
    }
    return 1;
}


// this is a list of all the unit tests
int (*unitTests[])() = {
        test_swap_one,
        test_create_array_of_ints_fib,
        test_reverse_array, 
        test_double_array_size,
        test_copy_array_start_end_loop,
        // add more test function names here
};

int main(int argc, char const *argv[])
{
    int numTests = sizeof(unitTests) / sizeof(unitTests[0]);
    int numPassed = 0;

    for (int i = 0; i < numTests; i++) {
        if (unitTests[i]()) {
            numPassed++;
        } else {
            printf("Test %d failed\n", i + 1);
        }
    }

    printf("Passed %d out of %d tests\n", numPassed, numTests);
    return 0;
}
