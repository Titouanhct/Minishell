/*
** EPITECH PROJECT, 2024
** my_strncmp.c
** File description:
** ..
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (i < n) {
        if (s1[i] < s2[i]) {
            return -1;
        }
        if (s1[i] > s2[i]) {
            return 1;
        }
        i++;
    }
    return 0;
}
