/**
 * Student Name: Tracy Urquhart
 * Semester: Fall 2025
 * 
 * Coding Practice Repository: Pointers in C - HackerRank
 * 
 * Solution to [Pointers in C exercise](https://www.hackerrank.com/challenges/pointer-in-c/problem?isFullScreen=true)
 * 
 * What I learned: 
 * I learned how to caluclate an absolute value in C. I also got additional practice with pointers, 
 * which are still not intuitive to me. In this exercise, though, something clicked about the 
 * memory space that is allocated for a pointer vs. for a value. 
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