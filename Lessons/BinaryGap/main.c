#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// Function to find the length of the longest sequence of zeros
// surrounded by ones in the binary representation of N
int solution(int N)
{
    int zeros = 0;       // Current count of zeros
    int max_zeros = 0;   // Maximum count of zeros
    bool in_gap = false; // Indicates if we are in a gap of zeros

    while(N > 0)
    {
        if(N % 2 == 0)   // Check if the current bit is zero
        {
            if(in_gap) zeros++;
        }
        else             // Current bit is one
        {
            if(in_gap)
            {
                if(zeros > max_zeros) max_zeros = zeros;
            }
            zeros = 0;
            in_gap = true;
        }
        N = N/2;        // Move to the next bit
    }
    return max_zeros;
}

int main(){

    // Test cases
    assert(solution(9) == 2);    // Binary: 1001, longest gap: 2
    assert(solution(529) == 4);  // Binary: 1000010001, longest gap: 4
    assert(solution(20) == 1);   // Binary: 10100, longest gap: 1
    assert(solution(15) == 0);   // Binary: 1111, no gap
    assert(solution(32) == 0);   // Binary: 100000, no gap

    printf("All test cases passed!\n");
    return 0;
}
