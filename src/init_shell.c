/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** init_shell
*/

#include "sh.h"

static void set_cmd_path(shell_t *shell)
{
    char *line = NULL;
    int done = 0;

    for (int i = 0; shell->env[i] != NULL; i++) {
        if (my_strncmp(shell->env[i], "PATH=", 5) == 0) {
            line = my_strdup(shell->env[i]);
            done = 1;
        }
    }
    if (done == 1)
        shell->cmd_path = my_str_to_word_array(line + sizeof(char) * 5, ":");
    else
        shell->cmd_path = NULL;
}

static char **nlspath(char **dup, int i)
{
    dup[i] = my_strcatdup("NLSPATH=", "/usr/share/locale/%L/LC_MESSAGES/%N"
            ".cat:/usr/share/locale/%l/LC_MESSAGES/%N.cat");
        dup[i +1] = NULL;
    return dup;
}

static char **dup_env(char **env_p)
{
    int i = 0;
    char **dup;
    char *tmp = getcwd(NULL, 0);

    if (*env_p == NULL) {
        dup = malloc(sizeof(char *) * 4);
        dup[0] = my_strcatdup("PATH=", "/bin");
        dup[1] = my_strcatdup("PWD=", tmp);
        dup[2] = my_strcatdup("OLDPWD=", tmp);
        dup[3] = NULL;
    } else {
        for (; env_p[i]; i++);
        dup = malloc(sizeof(char *) * (i + 2));
        for (int x = 0; env_p[x]; x++)
            dup[x] = my_strdup(env_p[x]);
        dup = nlspath(dup, i);
    }
    free(tmp);
    return dup;
}

shell_t *init_shell(char **env_p)
{
    shell_t *shell = malloc(sizeof(shell_t));

    if (shell == NULL)
        return NULL;
    shell->cond = true;
    shell->r_value = 0;
    shell->env = dup_env(env_p);
    set_cmd_path(shell);
    return shell;
}
