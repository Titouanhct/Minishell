/*
** EPITECH PROJECT, 2024
** my_revstr.c
** File description:
** ..
*/

#include "my.h"

char *my_revstr(char *str)
{
    int n = 0;
    int r = my_strlen(str) - 1;
    int tmp;

    while (r >= n) {
        tmp = str[r];
        str[r] = str[n];
        str[n] = tmp;
        n++;
        r--;
    }
    return str;
}
