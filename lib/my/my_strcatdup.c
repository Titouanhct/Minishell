/*
** EPITECH PROJECT, 2024
** my_ls
** File description:
** my_strcatdup
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

char *my_strcatdup(char *dest, char *src)
{
    int l;
    int i;
    char *r_value = NULL;

    if (!src) {
        r_value = my_strdup(dest);
        return r_value;
    } else {
        l = my_strlen(dest);
        i = my_strlen(src);
        r_value = malloc(sizeof(char)* (i + l + 1));
        my_strcpy(r_value, dest);
        my_strcat(r_value, src);
    }
    return r_value;
}
