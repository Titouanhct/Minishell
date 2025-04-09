/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** ..
*/

#include "my.h"
#include <stddef.h>

char *my_strcat(char *dest, char const *src)
{
    int l = my_strlen(dest);
    int i = 0;

    if (src == NULL) {
        return NULL;
    } else {
        while (src[i] != '\0') {
            dest[l + i] = src[i];
            i++;
        }
        dest[l + i] = '\0';
    }
    return dest;
}
