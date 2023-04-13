#include <stdio.h>
#include <stdlib.h>

int longestIncreasingSubsequence(int arr[], int n){
    int dp[n];
    int hash[n];
    int i, j, ans = -1, lastIndex = -1;
    for(i = 0; i < n; i++){
        dp[i] = 1;
        hash[i] = i;
        for(j = 0; j < i; j++){
            if(arr[j] < arr[i] && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }
    }

    for(i = 0; i < n; i++){
        if(dp[i] > ans){
            ans = dp[i];
            lastIndex = i;
        }
    }

    int *temp = (int*)malloc(sizeof(int) * ans);
    int k = ans - 1;
    temp[k--] = arr[lastIndex];

    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        temp[k--] = arr[lastIndex];
    }

    printf("The subsequence elements are ");
    for(i = 0; i < ans; i++){
        printf("%d ", temp[i]);
    }
    printf("\nThe length of the longest increasing subsequence is %d\n", ans);
    
    free(temp);
    return ans;
}

int main(){
    int arr[] = {10,9,2,5,3,7,101,18};
    int n = sizeof(arr) / sizeof(arr[0]);
    longestIncreasingSubsequence(arr, n);
    return 0;
}
