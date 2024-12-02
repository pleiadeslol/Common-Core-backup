/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper23.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalabdal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 05:53:09 by nalabdal          #+#    #+#             */
/*   Updated: 2024/10/19 05:53:10 by nalabdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	initialize_p_env(t_pathAndEnv **p_env, char **env)
{
	t_env	*v;	
	char	**envp;

	v = struct_env(env);
	envp = get_env(v);
	(*p_env) = (t_pathAndEnv *)ft_calloc(sizeof(t_pathAndEnv), 1);
	(*p_env)->envp = envp;
	if (!*env)
		(*p_env)->path = false;
	else
		(*p_env)->path = true;
	ft_envclear(&v);
}

void	main_helper1(char **line, t_node **node)
{
	char	**s;

	s = NULL;
	fill_the_blanks(line, '\"');
	fill_the_blanks(line, '\'');
	replace_tab_space(line);
	s = ft_split(*line, ' ');
	s = rev_split(s);
	*node = lexer_mini(s);
	free_tab(s);
}

void	ft_reverse_line(char **line)
{
	reverse_fill_the_blanks(line, '\"');
	reverse_fill_the_blanks(line, '\'');
}

int	ft_check_args_main(int *argc, char ***argv,
		t_pathAndEnv **p_env, char **env)
{
	if (*argc != 1)
		return (printf("argument input error\n"), 1);
	(void)(*argc);
	(void)(*argv);
	initialize_p_env(p_env, env);
	g_global = malloc(sizeof(t_global));
	if (!g_global)
		exit(EXIT_FAILURE);
	ft_bzero(g_global, sizeof(t_global));
	g_global->running = 0;
	g_global->here_doc = false;
	g_global->pid = get_pid();
	set_status(0);
	return (0);
}

void	main_helper3(t_node **node, t_pathAndEnv *p_env, char **line)
{
	int	p;

	main_helper1(line, node);
	p = parse(*node);
	if (p == 0)
		main_helper2(p_env, *node);
	else if (*node)
		ft_lstclear(node);
	ft_reverse_line(line);
}
