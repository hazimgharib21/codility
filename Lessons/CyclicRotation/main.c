#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Results {
  int * A;
  int N; // Length of the array
};

struct Results solution(int A[], int N, int K)
{
    // Create a struct to hold the results
    struct Results result;
    result.N = N;
    result.A = (int *)malloc(N * sizeof(int));

    // Edge case: if N is 0, return an empty array
    if (N == 0)
    {
        result.A = NULL;
        return result;
    }

    // Adjust K to be within the range of 0 to N-1
    K = K % N;

    // Rotate the array
    for (int i = 0; i < N; i++)
    {
        result.A[(i + K) % N] = A[i];
    }

    return result;
}

int main()
{
    // Test cases
    int A1[] = {3, 8, 9, 7, 6};
    int N1 = 5;
    int K1 = 3;
    struct Results res1 = solution(A1, N1, K1);
    int expected1[] = {9, 7, 6, 3, 8};
    for (int i = 0; i < N1; i++) {
        assert(res1.A[i] == expected1[i]);
    }

    int A2[] = {0, 0, 0};
    int N2 = 3;
    int K2 = 1;
    struct Results res2 = solution(A2, N2, K2);
    int expected2[] = {0, 0, 0};
    for (int i = 0; i < N2; i++) {
        assert(res2.A[i] == expected2[i]);
    }

    int A3[] = {1, 2, 3, 4};
    int N3 = 4;
    int K3 = 4;
    struct Results res3 = solution(A3, N3, K3);
    int expected3[] = {1, 2, 3, 4};
    for (int i = 0; i < N3; i++) {
        assert(res3.A[i] == expected3[i]);
    }

    // Additional test cases
    int A4[] = {1, 2, 3, 4, 5};
    int N4 = 5;
    int K4 = 6;
    struct Results res4 = solution(A4, N4, K4);
    int expected4[] = {5, 1, 2, 3, 4};
    for (int i = 0; i < N4; i++) {
        assert(res4.A[i] == expected4[i]);
    }

    int A5[] = {1, 2, 3, 4, 5};
    int N5 = 5;
    int K5 = 0;
    struct Results res5 = solution(A5, N5, K5);
    int expected5[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < N5; i++) {
        assert(res5.A[i] == expected5[i]);
    }

    int A6[] = {1, 2, 3, 4, 5};
    int N6 = 5;
    int K6 = 10;
    struct Results res6 = solution(A6, N6, K6);
    int expected6[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < N6; i++) {
        assert(res6.A[i] == expected6[i]);
    }

    int A7[] = {1, 2, 3, 4, 5};
    int N7 = 5;
    int K7 = 7;
    struct Results res7 = solution(A7, N7, K7);
    int expected7[] = {4, 5, 1, 2, 3};
    for (int i = 0; i < N7; i++) {
        assert(res7.A[i] == expected7[i]);
    }

    // Free allocated memory
    free(res1.A);
    free(res2.A);
    free(res3.A);
    free(res4.A);
    free(res5.A);
    free(res6.A);
    free(res7.A);

    printf("All test cases passed!\n");
    return 0;
}
