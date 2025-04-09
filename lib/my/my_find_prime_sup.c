/*
** EPITECH PROJECT, 2024
** my_find_prime_sup.c
** File description:
** ..
*/

#include "my.h"

static int prime(int nb)
{
    int div = 2;

    if (nb < div) {
        return 0;
    }
    while (div < nb) {
        if (nb % div == 0) {
            return 0;
        }
        div++;
    }
    return 1;
}

int my_find_prime_sup(int nb)
{
    while (prime(nb) != 1) {
        nb++;
    }
    return nb;
}
