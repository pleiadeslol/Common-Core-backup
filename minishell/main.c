#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int ac, char **av, char **envp)
{
    int i;
    char **envp_copy;
    char *new_prompt = "PS1=minishell$ ";

    for (i = 0; envp[i] != NULL; i++);

    envp_copy = (char **)malloc(sizeof(char *) * (i + 2));
    if (envp_copy == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    int envp_copy_index = 0;
    for (int j = 0; envp[j] != NULL; j++)
    {
        if (strncmp("PS1=", envp[j], 4) != 0)
        {
            envp_copy[envp_copy_index] = strdup(envp[j]);
            if (envp_copy[envp_copy_index] == NULL)
            {
                perror("strdup");
                exit(EXIT_FAILURE);
            }
            envp_copy_index++;
        }
    }

    envp_copy[envp_copy_index] = strdup(new_prompt);
    if (envp_copy[envp_copy_index] == NULL)
    {
        perror("strdup");
        exit(EXIT_FAILURE);
    }
    envp_copy[++envp_copy_index] = NULL;

    char *cmds[] = { "bash", "--norc", "-i", NULL };

    execve("/bin/bash", cmds, envp_copy);

    perror("execve");

    for (int k = 0; envp_copy[k] != NULL; k++)
        free(envp_copy[k]);
    free(envp_copy);

    return EXIT_FAILURE;
}