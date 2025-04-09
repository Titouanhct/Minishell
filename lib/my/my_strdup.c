/*
** EPITECH PROJECT, 2024
** my_strdup.c
** File description:
** ..
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *str)
{
    char *dup;
    int i;

    dup = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (i = 0; i < my_strlen(str); i++) {
        dup[i] = str[i];
    }
    dup[i] = '\0';
    return dup;
}
