#include <stdio.h>

#define MAX_JOBS 100

typedef struct {

    int id;

    int profit;

    int deadline;

} job_t;

void job_sequence(job_t jobs[], int n);

int main(void)

{

    job_t jobs[MAX_JOBS];

    int n, i;

    printf("Enter the number of jobs: ");

    scanf("%d", &n);

    for (i = 0; i < n; i++) {

        printf("Enter the profit and deadline of job %d: ", i + 1);

        scanf("%d%d", &jobs[i].profit, &jobs[i].deadline);

        jobs[i].id = i + 1;

    }

    job_sequence(jobs, n);

    return 0;

}

void job_sequence(job_t jobs[], int n)

{

    int i, j, max_deadline = 0, max_profit = 0, max_index = 0, profit = 0;

    int is_scheduled[MAX_JOBS] = { 0 };

    for (i = 0; i < n; i++) {

        if (jobs[i].deadline > max_deadline) {

            max_deadline = jobs[i].deadline;

        }

    }

    for (i = 1; i <= max_deadline; i++) {

        max_profit = 0;

        max_index = -1;

        for (j = 0; j < n; j++) {

            if (!is_scheduled[j] && jobs[j].deadline >= i) {

                if (jobs[j].profit > max_profit) {

                    max_profit = jobs[j].profit;

                    max_index = j;

                }

            }

        }

        if (max_index != -1) {

            is_scheduled[max_index] = 1;

            profit += max_profit;

            printf("Job %d with profit %d scheduled at time %d\n",

                jobs[max_index].id, jobs[max_index].profit, i);

        }

    }

    printf("Total profit = %d\n", profit);

}

