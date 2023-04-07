#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 5;
    int prev2 = 0;
    int prev = 1;
    
    for(int i = 2; i <= n; i++){
        int cur_i = prev2 + prev;
        prev2 = prev;
        prev = cur_i;
    }
    printf("%d\n", prev);

    return 0;
}
