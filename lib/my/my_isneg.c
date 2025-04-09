/*
** EPITECH PROJECT, 2024
** my_isneg.c
** File description:
** ..
*/

#include "my.h"

int my_isneg(int n)
{
    if (n * (-1) > n) {
        my_putchar('N');
        return 0;
    } else {
        my_putchar('P');
        return 0;
    }
}
