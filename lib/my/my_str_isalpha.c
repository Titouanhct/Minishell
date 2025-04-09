/*
** EPITECH PROJECT, 2024
** my_str_isalpha.c
** File description:
** ..
*/

#include "my.h"
#include <ctype.h>

int my_str_isalpha(char const *str)
{
    for (; *str != '\0'; str++) {
        if (!isalnum(*str))
            return 1;
    }
    return 0;
}
