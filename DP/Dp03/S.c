#include <stdio.h>
#include <stdlib.h>

int main() {
    int height[] = {30, 10, 60, 10, 60, 50};
    int n = sizeof(height) / sizeof(height[0]);
    int prev = 0;
    int prev2 = 0;
    
    for (int i = 1; i < n; i++) {
        int jumpTwo = __INT_MAX__;
        int jumpOne = prev + abs(height[i] - height[i - 1]);
        if (i > 1) {
            jumpTwo = prev2 + abs(height[i] - height[i - 2]);
        }
        
        int cur_i = jumpOne < jumpTwo ? jumpOne : jumpTwo;
        prev2 = prev;
        prev = cur_i;
    }
    
    printf("%d", prev);
    return 0;
}
