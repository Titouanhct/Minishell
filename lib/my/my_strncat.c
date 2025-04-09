/*
** EPITECH PROJECT, 2024
** my_strncat.c
** File description:
** ..
*/

#include "my.h"
#include <stddef.h>

char *my_strncat(char *dest, char const *src, int nb)
{
    int l = my_strlen(dest);
    int i = 0;

    if (src == NULL) {
        return NULL;
    } else {
        while (i < nb) {
            dest[l + i] = src[i];
            i++;
        }
        dest[l + i] = '\0';
    }
    return dest;
}
