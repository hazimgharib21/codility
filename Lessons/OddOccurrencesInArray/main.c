#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

int solution(int A[], int N)
{
    int result = 0;
    for (int i = 0; i < N; i++) {
        result ^= A[i];
    }
    return result;
}

int main(){

    // Test cases
    assert(solution((int[]){9, 3, 9, 3, 9, 7, 9}, 7) == 7);
    assert(solution((int[]){4, 2, 4, 5, 2}, 5) == 5);
    assert(solution((int[]){100, 200, 300, 400, 500, 200, 400, 500, 100}, 9) == 300);
    assert(solution((int[]){-1, 2, -1, 3, 2}, 5) == 3);

    // Additional test cases
    assert(solution((int[]){1, 2, 3, 4, 5, 4, 3, 2, 1, 6, 6, 7, 7, 8, 8}, 15) == 5);
    assert(solution((int[]){1, 2, 1, 2, 3, 4, 3, 5, 4, 6, 5, 6, 7}, 13) == 7);
    printf("All test cases passed!\n");
    return 0;
}
