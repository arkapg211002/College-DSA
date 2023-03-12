#include <stdio.h>

#include <stdlib.h>

typedef struct meeting {

    int start;

    int end;

    int pos;

} Meeting;

int compare(const void* a, const void* b) {

    Meeting* m1 = (Meeting*) a;

    Meeting* m2 = (Meeting*) b;

    if (m1->end < m2->end)

        return -1;

    else if (m1->end > m2->end)

        return 1;

    else if (m1->pos < m2->pos)

        return -1;

    return 1;

}

void swap(Meeting* a, Meeting* b) {

    Meeting temp = *a;

    *a = *b;

    *b = temp;

}

void sort(Meeting meet[], int n) {

    int i, j;

    for (i = 0; i < n-1; i++) {

        for (j = 0; j < n-i-1; j++) {

            if (meet[j].end > meet[j+1].end) {

                swap(&meet[j], &meet[j+1]);

            }

        }

    }

}

void maxMeetings(int start[], int end[], int n) {

    Meeting meet[n];

    int i, limit = -1;

    for (i = 0; i < n; i++) {

        meet[i].start = start[i];

        meet[i].end = end[i];

        meet[i].pos = i+1;

    }

    sort(meet, n);

    printf("The order in which the meetings will be performed is: ");

    for (i = 0; i < n; i++) {

        if (meet[i].start > limit) {

            limit = meet[i].end;

            printf("%d ", meet[i].pos);

        }

    }

}

int main() {

    int n = 6;

    int start[] = {1,3,0,5,8,5};

    int end[] = {2,4,5,7,9,9};

    maxMeetings(start, end, n);

    return 0;

}

