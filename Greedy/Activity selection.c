#include <stdio.h>

#define MAX_ACTIVITIES 100

struct Activity {
    int start;
    int finish;
};

void print_selected_activities(struct Activity activities[], int n) {
    int i, j;
    
    printf("Selected activities:\n");
    i = 0;
    printf("(%d, %d) ", activities[i].start, activities[i].finish);
    for (j = 1; j < n; j++) {
        if (activities[j].start >= activities[i].finish) {
            printf("(%d, %d) ", activities[j].start, activities[j].finish);
            i = j;
        }
    }
    printf("\n");
}

void activity_selection(struct Activity activities[], int n) {
    int i, j, temp;
    
    // Sort the activities by finish time
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (activities[i].finish > activities[j].finish) {
                temp = activities[i].finish;
                activities[i].finish = activities[j].finish;
                activities[j].finish = temp;
                
                temp = activities[i].start;
                activities[i].start = activities[j].start;
                activities[j].start = temp;
            }
        }
    }
    
    print_selected_activities(activities, n);
}

int main() {
    struct Activity activities[MAX_ACTIVITIES];
    int n, i;
    
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    
    printf("Enter the start and finish times of each activity:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }
    
    activity_selection(activities, n);
    
    return 0;
}
