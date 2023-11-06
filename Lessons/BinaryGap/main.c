#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

int solution(int N){
    int zeros = 0;
    int max_zeros = 0;
    bool gaps = false;
    while(N > 0)
    {
        if(N%2 == 0){
            if(gaps) zeros++;
        }
        if(N%2 == 1){
            if(gaps) max_zeros = zeros;
            zeros = 0;
            gaps = true;
        }
        N = N/2;
    }
    return max_zeros;
}

int main(){
    assert(2 == solution(9));
    assert(4 == solution(529));
    assert(1 == solution(20));
    assert(0 == solution(15));
    assert(0 == solution(32));
    return 0;
}
