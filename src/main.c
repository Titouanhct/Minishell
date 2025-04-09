/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** main
*/

#include "sh.h"

int flag_h(void)
{
    my_cat("shell/flag_h.txt");
    return 0;
}

int main(int ac, char **av, char **env_p)
{
    shell_t *shell;
    int r = 0;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return flag_h();
    shell = init_shell(env_p);
    if (shell == NULL) {
        write(2, "error when initializing the shell\n", 35);
        return 84;
    }
    exec_loop(shell);
    r = shell->r_value;
    destroy_all(shell);
    return r;
}
