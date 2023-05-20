
#include <stdio.h>

int subset_count = 0;

void subset_sum(int list[], int sum, int starting_index, int target_sum)
{
    if (target_sum == sum)
    {
        subset_count++;
        if (starting_index < sizeof(list) / sizeof(list[0]))
            subset_sum(list, sum - list[starting_index - 1], starting_index, target_sum);
    }
    else
    {
        int i;
        for (i = starting_index; i < sizeof(list) / sizeof(list[0]); i++)
        {
            subset_sum(list, sum + list[i], i + 1, target_sum);
        }
    }
}

int main()
{
    int list[] = {1, 3, 5, 2};
    subset_sum(list, 0, 0, 6);
    printf("%d\n", subset_count);

    return 0;
}
