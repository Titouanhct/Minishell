/*
** EPITECH PROJECT, 2024
** my_sort_int_array.c
** File description:
** ..
*/

#include "my.h"

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int imin = i;
    int tmp;

    for (int j = i + 1; j < size; j++) {
        if (array[i] < array[imin]) {
            imin = i;
        }
    tmp = array[i];
    array[i] = array[imin];
    array[imin] = tmp;
    i++;
    }
}
