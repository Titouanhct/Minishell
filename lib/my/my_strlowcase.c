/*
** EPITECH PROJECT, 2024
** my_strlowcase.c
** File description:
** ..
*/

#include "my.h"

char *my_strlowcase(const char *str)
{
    int i = 0;
    char *cpy = my_strdup(str);

    while (cpy[i] != '\0') {
        if (cpy[i] >= 'A' && cpy[i] <= 'Z') {
            cpy[i] += 32;
        }
        i++;
    }
    return cpy;
}
