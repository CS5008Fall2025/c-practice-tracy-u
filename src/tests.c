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
    // test values match
    for (int i = 0; i < 5; i++) {
        if (arr[i] != expected[i]) {
            return 0;
        }
    }
    free(arr);
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
    free(arr);
    free(doubled);
    return 1;
}

int test_copy_array_start_end_loop(){
    printf("5. test_copy_array_start_end_loop()\n");
    int arr[] = {1, 2, 3, 4, 5};

    // test 1: invalid cases
    int new_size;
    int* invalid1 = copy_array_start_end_loop(arr, 5, -1, 3, &new_size); // start less than 0
    int* invalid2 = copy_array_start_end_loop(arr, 5, 5, 3, &new_size); // start equal to size
    int* invalid3 = copy_array_start_end_loop(arr, 5, 6, 3, &new_size); // start > size
    int* invalid4 = copy_array_start_end_loop(arr, 5, 1, 5, &new_size); // end equal to size
    int* invalid5 = copy_array_start_end_loop(arr, 5, 1, 6, &new_size); // end > size
    if(invalid1 != NULL | invalid2 != NULL | invalid3 != NULL | invalid4 != NULL | invalid5 != NULL) {
        return 0;
    }

    free(invalid1);
    free(invalid2);
    free(invalid3);
    free(invalid4);
    free(invalid5);

    // test 2: valid case where start < end
    int expected1[] = {2, 3, 4};
    int *looped1 = copy_array_start_end_loop(arr, 5, 1, 3, &new_size);
    // calculated size should be 3
    if (new_size != 3) {
        return 0;
    }
    // ensure values match
    for (int i = 0; i < new_size; i++) {
        if (looped1[i] != expected1[i]) {
            return 0;
        }
    }
    free(looped1); 

    // test 3: valid case with wrap around
    int new_size2;
    int expected2[] = {4, 5, 1, 2};
    int *looped2 = copy_array_start_end_loop(arr, 5, 3, 1, &new_size2);
    // calculated size should be 4
    if (new_size2 != 4) {
        return 0;
    }
    // ensure values match
    for (int i = 0; i < new_size2; i++) {
        if (looped2[i] != expected2[i]) {
            return 0;
        }
    }
    free(looped2);
    return 1;
}

int test_create_point() {
    printf("6. test_create_point()\n");

    Point expected;
    expected.x = 20;
    expected.y = -10;
    Point *actual = create_point(20, -10);
    // ensure x and y values match
    if(expected.x != actual->x || expected.y != actual->y) {
        return 0;
    }
    free(actual);
    return 1;
}

int test_create_polygon() {
    printf("7. test_create_polygon()\n");
    int size = 5;
    Polygon *actual = create_polygon(size);
    Point** points = malloc(sizeof(Point) * size);

    // ensure size of sizes match
    if(actual->size != size) {
        return 0;
    }
    if(sizeof(actual->points) != sizeof(points)) {
        return 0;
    } 

    free(points);
    free(actual);
    return 1;
}


int test_create_rectangle() {
    printf("8. test_create_rectangle()\n");

    int width = 10; 
    int height = 5;
    Polygon* actual = create_rectangle(width, height);

    Point point0 = {0,0};
    Point point1 = {width,0};
    Point point2 = {width,height};
    Point point3 = {0,height};

    Point* actualPoint0 = actual->points[0]; 
    Point* actualPoint1 = actual->points[1]; 
    Point* actualPoint2 = actual->points[2]; 
    Point* actualPoint3 = actual->points[3]; 

    if( actualPoint0->x != point0.x || actualPoint0->y != point0.y) {
        printf("Failed on point 0");
        return 0;
    }
    if( actualPoint1->x != point1.x || actualPoint1->y != point1.y) {
        printf("Failed on point 1");
        return 0;
    }
    if(actualPoint2->x != point2.x || actualPoint2->y != point2.y) {
        printf("Failed on point 2");
        return 0;
    }

    if(actualPoint3->x != point3.x || actualPoint3->y != point3.y) {
        printf("Failed on point 3");
        return 0;
    }
    free_polygon(actual);
    return 1;
} 


int test_create_triangle() {
    printf("9. test_create_triangle()\n");

    int width = 10; 
    int height = 5;
    Polygon* actual = create_triangle(width, height);

    Point point0 = {0,0};
    Point point1 = {width,0};
    Point point2 = {width,height};

    Point* actualPoint0 = actual->points[0]; 
    Point* actualPoint1 = actual->points[1]; 
    Point* actualPoint2 = actual->points[2]; 

    if( actualPoint0->x != point0.x || actualPoint0->y != point0.y) {
        printf("Failed on point 0");
        return 0;
    }
    if( actualPoint1->x != point1.x || actualPoint1->y != point1.y) {
        printf("Failed on point 1");
        return 0;
    }
    if(actualPoint2->x != point2.x || actualPoint2->y != point2.y) {
        printf("Failed on point 2");
        return 0;
    }
    free_polygon(actual);
    return 1;
} 

int test_calculate_polygon_area() {
    printf("10. test_calculate_polygon_area()\n");
    int width = 10; 
    int height = 5;

    // Test for triangle
    Polygon* triangle = create_triangle(width, height);
    double expected1 = 25.0; // manually calculated expected area
    double area1 = calculate_polygon_area(triangle);
    if (area1 != expected1) {
        return 0;
    }
    free(triangle);

    // Test for rectangle
    Polygon* rectangle = create_rectangle(width, height);
    double expected2 = 50.0; // manually calculated expected area
    double area2 = calculate_polygon_area(rectangle);
    if (area2 != expected2) {
        return 0;
    }
    free(rectangle);

    return 1;
}

// this is a list of all the unit tests
int (*unitTests[])() = {
        test_swap_one,
        test_create_array_of_ints_fib,
        test_reverse_array, 
        test_double_array_size,
        test_copy_array_start_end_loop,
        test_create_point,
        test_create_polygon,
        test_create_rectangle,
        test_create_triangle,
        test_calculate_polygon_area,
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
