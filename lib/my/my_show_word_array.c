/*
** EPITECH PROJECT, 2024
** my_show_word_array.c
** File description:
** ..
*/

#include "my.h"
#include <stddef.h>

int my_show_word_array(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return 0;
}
