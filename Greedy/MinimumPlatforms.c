#include <stdio.h>

// Function to find the minimum number of platforms needed

int findMinPlatforms(int arr[], int dep[], int n) {

    // Sort the arrival and departure arrays in non-decreasing order

    int i, j, minPlatforms = 0, platforms = 0;

    for (i = 0; i < n - 1; i++) {

        for (j = i + 1; j < n; j++) {

            if (arr[i] > arr[j]) {

                int temp = arr[i];

                arr[i] = arr[j];

                arr[j] = temp;

                temp = dep[i];

                dep[i] = dep[j];

                dep[j] = temp;

            }

        }

    }

    // Traverse the arrival and departure arrays

    i = 0, j = 0;

    while (i < n && j < n) {

        if (arr[i] <= dep[j]) {

            platforms++;

            i++;

        }

        else {

            platforms--;

            j++;

        }

        // Update the minimum platforms needed

        if (platforms > minPlatforms) {

            minPlatforms = platforms;

        }

    }

    return minPlatforms;

}

int main() {

    int arr[] = {900, 945, 955, 1100, 1500, 1800};

    int dep[] = {920, 1200, 1130, 1150, 1900, 2000};

    int n = sizeof(arr) / sizeof(arr[0]);

    int minPlatforms = findMinPlatforms(arr, dep, n);

    printf("Minimum number of platforms required: %d\n", minPlatforms);

    return 0;

}

