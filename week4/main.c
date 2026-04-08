#include <stdio.h>
#include <time.h>

/*
    this is kit205 timing code experiment
    Rewritten  new type  of the original program:
    - functionality of program is same 
    - crystal clean structure 
    - All comments are written by me 
      student name : Azan Sikandar
      ID : 757964
*/

long square_count(long n) {
    long counter = 0;

    for (long row = 0; row < n; row++) {
        for (long col = 0; col < n; col++) {
            counter++;
        }
    }

    return counter;
}

void triangular_plus_constant(long n) {
    long counter = 0;

    for (long i = 0; i < n; i++) {
        for (long j = 0; j < i; j++) {
            counter++;
        }

        for (long t = 0; t < 10000; t++) {
            counter++;
        }
    }
}

void binary_recursive(long n) {
    if (n <= 0) {
        return;
    }

    binary_recursive(n / 2);
    binary_recursive(n / 2);
}

void binary_recursive_with_quadratic(long n) {
    if (n <= 0) {
        return;
    }

    binary_recursive_with_quadratic(n / 2);
    binary_recursive_with_quadratic(n / 2);
    triangular_plus_constant(n);
}

void logarithmic_driver(long n) {
    long counter = 0;

    for (long repeat = 0; repeat < 10; repeat++) {
        long value = n;

        while (value > 0) {
            square_count(1000);
            counter++;
            value /= 2;
        }
    }
}

void combined_work(long n) {
    triangular_plus_constant(n);
    binary_recursive(n);
    logarithmic_driver(n);
}

void loop_using_square_count(long n) {
    long counter = 0;
    long limit = square_count(n);

    for (long i = 0; i < limit; i++) {
        counter++;
    }

    for (long j = 0; j < n; j++) {
        counter++;
    }
}

void print_time_result(long n, clock_t start_time) {
    clock_t elapsed = clock() - start_time;
    long milliseconds = elapsed * 1000 / CLOCKS_PER_SEC;
    printf("%ld\t\t%ld\n", n, milliseconds);
}

int main(void) {
    long n;

    printf("n\t\ttime(ms)\n");

    /*
        Complexity expectations used before testing:
        square_count                -> O(n^2)
        triangular_plus_constant    -> O(n^2)
        binary_recursive            -> O(n)
        binary_recursive_with_quadratic -> O(n^2)
        logarithmic_driver          -> O(log n)
        combined_work               -> O(n^2)
        loop_using_square_count     -> O(n^2)
    */

    printf("\nsquare_count - expected O(n^2)\n");
    long set1[] = {1000, 2000, 4000, 8000, 16000, 32000};
    int set1_len = 6;

    for (int i = 0; i < set1_len; i++) {
        n = set1[i];
        clock_t start = clock();
        square_count(n);
        print_time_result(n, start);
    }

    printf("\ntriangular_plus_constant - expected O(n^2)\n");
    for (int i = 0; i < set1_len; i++) {
        n = set1[i];
        clock_t start = clock();
        triangular_plus_constant(n);
        print_time_result(n, start);
    }

    printf("\nbinary_recursive - expected O(n)\n");
    long set3[] = {100, 200, 400, 800, 1600, 3200, 6400};
    int set3_len = 7;

    for (int i = 0; i < set3_len; i++) {
        n = set3[i];
        clock_t start = clock();
        binary_recursive(n);
        print_time_result(n, start);
    }

    printf("\nbinary_recursive_with_quadratic - expected O(n^2)\n");
    long set4[] = {50, 100, 200, 400, 800};
    int set4_len = 5;

    for (int i = 0; i < set4_len; i++) {
        n = set4[i];
        clock_t start = clock();
        binary_recursive_with_quadratic(n);
        print_time_result(n, start);
    }

    printf("\nlogarithmic_driver - expected O(log n)\n");
    long set5[] = {100, 1000, 10000, 100000, 1000000};
    int set5_len = 5;

    for (int i = 0; i < set5_len; i++) {
        n = set5[i];
        clock_t start = clock();
        logarithmic_driver(n);
        print_time_result(n, start);
    }

    printf("\ncombined_work - expected O(n^2)\n");
    long set6[] = {1000, 2000, 4000, 8000, 16000};
    int set6_len = 5;

    for (int i = 0; i < set6_len; i++) {
        n = set6[i];
        clock_t start = clock();
        combined_work(n);
        print_time_result(n, start);
    }

    printf("\nloop_using_square_count - expected O(n^2)\n");
    long set7[] = {10, 20, 40, 80};
    int set7_len = 4;

    for (int i = 0; i < set7_len; i++) {
        n = set7[i];
        clock_t start = clock();
        loop_using_square_count(n);
        print_time_result(n, start);
    }

    /*
        Notes:
        - very  first 2 functions should  illustrate quadratic growth.
        - binary_recursive should have  growen  nearly  linearly.
        - binary_recursive_with_quadratic can become very costly  quickly.
        - logarithmic_driver will change  slowly as n increases. u know 
        - combined_work is dominated by the quadratic component.
        - loop_using_square_count is O(n^2), because square_count(n) is
          evaluated only once to produce the loop bound output , then the loop itself will 
          runs O(n^2) time and perform the task 
    */

    return 0;
}