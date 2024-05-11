/*
** EPITECH PROJECT, 2023
** Pool day 04 : Task 06
** File description:
** A function that sorts an integer array in ascending order,
** given a pointer to the first element of the array and its size.
*/

static void check(int *array, int first, int current, int *min)
{
    int temp;

    if (array[current] < *min) {
        *min = array[current];
        temp = array[first];
        array[first] = array[current];
        array[current] = temp;
    }
}

void my_sort_int_array(int *array, int size)
{
    int min;

    if (size == 0)
        return;
    for (int i = 0; i < size; i++) {
        min = array[i];
        for (int y = i; y < size; y++) {
            check(array, i, y, &min);
        }
    }
}
