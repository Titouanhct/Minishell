/*
** EPITECH PROJECT, 2024
** my_compute_square_root.c
** File description:
** ..
*/

#include "my.h"

static int pwr(int nb, int p)
{
    if (p < 0) {
        return 0;
    }
    if (p == 0){
        return 1;
    }
    if (p == 1) {
        return nb;
    } else {
        return (nb * pwr(nb, p - 1));
    }
}

int my_compute_square_root(int nb)
{
    int sqr = 1;

    while (sqr < nb) {
        if (pwr(sqr, 2) == nb){
            return sqr;
        }
        sqr++;
    }
    return 0;
}
