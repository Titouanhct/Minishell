/*
** EPITECH PROJECT, 2024
** my_strcpy.c
** File description:
** ..
*/

#include "my.h"
#include <stddef.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (src == NULL) {
        return NULL;
    } else {
        for (i = 0; src[i] != '\0'; i++) {
            dest[i] = src[i];
        }
        dest[i] = src[i];
    return dest;
    }
}
