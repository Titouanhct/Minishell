/*
** EPITECH PROJECT, 2024
** my_is_prime.c
** File description:
** ..
*/

#include "my.h"

int my_is_prime(int nb)
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
