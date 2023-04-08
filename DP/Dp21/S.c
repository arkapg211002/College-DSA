#include <stdio.h>

#define mod 1000000007

int findWays(int num[], int n, int tar) {
    int prev[tar+1];
    
    if(num[0] == 0) prev[0] = 2;
    else prev[0] = 1;
    
    if(num[0]!=0 && num[0]<=tar) prev[num[0]] = 1;
    
    for(int ind = 1; ind<n; ind++) {
        int cur[tar+1];
        for(int target= 0; target<=tar; target++) {
            int notTaken = prev[target];
    
            int taken = 0;
            if(num[ind]<=target)
                taken = prev[target-num[ind]];
        
            cur[target]= (notTaken + taken)%mod;
        }
        for(int i = 0; i <= tar; i++)
            prev[i] = cur[i];
    }
    return prev[tar];
}

int targetSum(int n, int target, int arr[]) {
    int totSum = 0;
    for(int i=0; i<n; i++){
        totSum += arr[i];
    }
    
    if(totSum-target <0 || (totSum-target)%2==1) return 0;
    
    return findWays(arr, n, (totSum-target)/2);
}

int main() {
    int arr[] = {1, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 3;
                     
    printf("The number of ways found is %d", targetSum(n, target, arr));
    return 0;
}
