#include <stdio.h>

long long int sum_array(int arr[], int arr_size) {

    long long int sum = 0;

    for (int i=0; i<arr_size; i++) {
        sum += arr[i];
    }

    return sum;
}


#define MAX_ITEMS (100)

int main(void)
{
    int items[MAX_ITEMS];
    int array_size;

    // Get number of items.
    printf("Please enter number of items (up to %d) that will be processed: ", MAX_ITEMS);
    scanf("%d", &array_size);

    // if number of items exceeds array size, restrict it to that value.
    if (array_size > MAX_ITEMS)
    {
        array_size = MAX_ITEMS;
    }

    for (int i = 0; i < array_size; i++)
    {
        printf("Please enter item %d of %d: ", (i+1), array_size);
        scanf("%d", &items[i]);
    }

    long long int result = sum_array(items, array_size);

    printf("The sum of the items you entered is %lld.\n", result);

    return 0;
}