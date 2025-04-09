/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** signal
*/

#include "sh.h"
#include "signal.h"

void signals(int *r_value)
{
    char *sign;

    if (WIFSIGNALED(*r_value)) {
        if (WTERMSIG(*r_value) == SIGFPE)
            sign = my_strdup("Floating exception");
        else
            sign = my_strdup(strsignal(WTERMSIG(*r_value)));
        if (WCOREDUMP(*r_value))
            sign = my_strcatdup(sign, " (core dumped)");
        sign = my_strcatdup(sign, "\n");
        write(STDERR_FILENO, sign, my_strlen(sign));
        free(sign);
        *r_value = WTERMSIG(*r_value) + 128;
    }
    if (WIFEXITED(*r_value))
        *r_value = WEXITSTATUS(*r_value);
}
