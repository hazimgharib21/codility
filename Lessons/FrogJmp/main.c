#include <stdio.h>
#include <assert.h>

int solution(int X, int Y, int D)
{
    int distance = Y - X;
    int jumps = distance / D;
    if(distance % D != 0)
    {
        jumps++;
    }
    return jumps;
}

int main(){

    // Test cases
    assert(solution(10, 85, 30) == 3);    // Regular case
    assert(solution(10, 10, 30) == 0);    // No jump needed
    assert(solution(10, 40, 30) == 1);    // Exactly one jump needed
    assert(solution(10, 70, 30) == 2);    // Exactly two jumps needed
    assert(solution(10, 100, 30) == 3);   // Target reached exactly
    assert(solution(1, 1000000000, 1000000000) == 1); // Large numbers, one jump needed

    printf("All test cases passed!\n");

    return 0;
}
