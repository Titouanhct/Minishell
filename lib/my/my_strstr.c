/*
** EPITECH PROJECT, 2024
** my_strstr.c
** File description:
** ..
*/

#include "my.h"
#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    int a = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == to_find[a] && a == my_strlen(to_find)-1) {
            return &str[i - a];
        }
        if (str[i] == to_find[a] && a < my_strlen(to_find)-1){
            a++;
        }
        i++;
    }
    return NULL;
}
