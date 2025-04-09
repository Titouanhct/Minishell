/*
** EPITECH PROJECT, 2024
** my_put_number.c
** File description:
** ..
*/

#include "my.h"

static int no_sign(int nb)
{
    if (nb <= 9 && nb >= 0){
    my_putchar(nb + 48);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    return 0;
}

int my_put_nbr(int nb)
{
    if (nb < 0){
        my_putchar(45);
        nb = nb * (-1);
        no_sign(nb);
    } else {
        no_sign(nb);
    }
    return 0;
}
