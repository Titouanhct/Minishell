/*
** EPITECH PROJECT, 2024
** my_put_bignbr.c
** File description:
** my_put_nbr for long long int
*/
#include "my.h"

static int no_sign(long long int nb)
{
    if (nb <= 9 && nb >= 0){
    my_putchar(nb + 48);
    }
    if (nb > 9) {
        no_sign(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    return 0;
}

int my_put_bignbr(long long int nb)
{
    if (nb < 0){
        my_putchar(45);
        nb = nb * (-1);
    }
    no_sign(nb);
    return 0;
}
