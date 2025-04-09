/*
** EPITECH PROJECT, 2024
** my_strisnum.c
** File description:
** ..
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 48) {
            return 0;
        }
        if (str[i] > 57) {
            return 0;
        }
        i++;
    }
    return 1;
}
