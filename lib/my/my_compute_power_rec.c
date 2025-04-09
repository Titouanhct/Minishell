/*
** EPITECH PROJECT, 2024
** my_compute_power_rec.c
** File description:
** ..
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    if (nb > 2147483646 || nb < -214748364) {
        return 0;
    }
    if (p < 0) {
        return 0;
    }
    if (p == 0){
        return 1;
    }
    if (p == 1) {
        return nb;
    } else {
        return nb * my_compute_power_rec(nb, p - 1);
    }
}
