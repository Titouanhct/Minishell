/*
** EPITECH PROJECT, 2024
** my_strcapitalize.c
** File description:
** ..
*/

#include "my.h"

static int checkchar(char *str, int i)
{
    if (i == 0) {
        return (str[i] <= 'z' && str[i] >= 'a');
    }
    if ((str[i - 1] < 65 && str[i -1] > 57)
        && (str[i] < 123 && str[i] > 96)) {
        return 1;
    }
    if (str[i - 1] < 48 && (str[i] <= 'z' && str[i] >= 'a')) {
        return 1;
    }
    if ((str[i - 1] < 90 && str[i - 1] > 97)
        && (str[i] < 123 && str[i] > 96)) {
        return 1;
    }
    return 0;
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    my_strlowcase(str);
    while (str[i] != '\0') {
        if (checkchar(str, i) == 1) {
            str[i] -= 32;
        }
        i++;
    }
    return str;
}
