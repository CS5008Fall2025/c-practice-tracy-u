/**
 * Student Name: Tracy Urquhart
 * Semester: Fall 2025
 * 
 * Coding Practice Repository: Pointers in C - HackerRank
 * 
 * Solution to [Pointers in C exercise](https://www.hackerrank.com/challenges/pointer-in-c/problem?isFullScreen=true)
 * 
*/


#include <stdio.h>

void update(int *a,int *b) {
    int sum = *a + *b;
    int diff = abs(*a - *b);
    *a = sum;
    *b = diff;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}