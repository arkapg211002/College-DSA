#include <stdio.h>

#define MAX 100

// function to sort items in decreasing order of value per unit weight

void sort(int n, float w[], float v[], float ratio[]) {

    int i, j;

    float temp;

    for (i = 0; i < n; i++) {

        ratio[i] = v[i] / w[i];

    }

    for (i = 0; i < n - 1; i++) {

        for (j = i + 1; j < n; j++) {

            if (ratio[i] < ratio[j]) {

                temp = ratio[j];

                ratio[j] = ratio[i];

                ratio[i] = temp;

                temp = w[j];

                w[j] = w[i];

                w[i] = temp;

                temp = v[j];

                v[j] = v[i];

                v[i] = temp;

            }

        }

    }

}

// function to solve fractional knapsack problem

float fractionalKnapsack(int n, float w[], float v[], float c) {

    int i;

    float ratio[MAX], totalValue = 0, totalWeight = 0;

    sort(n, w, v, ratio);

    for (i = 0; i < n; i++) {

        if (totalWeight + w[i] <= c) {

            totalValue += v[i];

            totalWeight += w[i];

        }

        else {

            float remainingWeight = c - totalWeight;

            totalValue += remainingWeight * ratio[i];

            break;

        }

    }

    return totalValue;

}

int main() {

    int n, i;

    float c, w[MAX], v[MAX];

    printf("Enter the number of items: ");

    scanf("%d", &n);

    printf("Enter the capacity of knapsack: ");

    scanf("%f", &c);

    printf("Enter the weights and values of each item:\n");

    for (i = 0; i < n; i++) {

        printf("Item %d: ", i + 1);

        scanf("%f%f", &w[i], &v[i]);

    }

    float maxVal = fractionalKnapsack(n, w, v, c);

    printf("Maximum value in knapsack = %.2f\n", maxVal);

    return 0;

}

