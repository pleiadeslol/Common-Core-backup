/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarhoun <rzarhoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:56:32 by rzarhoun          #+#    #+#             */
/*   Updated: 2024/11/30 20:45:37 by rzarhoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <errno.h>
# include <signal.h>
# include <termios.h>
# include "../src/get_next_line/get_next_line.h"

enum e_symbol
{
	p = 1,
	great = 2,
	less = 3,
	Ggreat = 4,
	Lless = 5,
	var = 6,
	opt = 7,
	file = 8,
	CMD = 9,
	builtin = 10,
	stop = 11,
	infile = 12,
	outfile = 13,
	arg = 14,
};

typedef struct s_args
{
	char			*word;
	enum e_symbol	type;
	int				empty_arg;
	struct s_args	*next;
}			t_args;

typedef struct s_redir
{
	enum e_symbol	type;
	int				fd;
	int				expansion;
	int				in_copy;
	int				out_copy;
	char			*file;
	char			*heredoc;
	struct s_redir	*next;
}			t_redir;

typedef struct s_cmd
{
	char			*cmd;
	char			*args;
	t_args			*args_node;
	int				isbuiltin;
	t_redir			*redir;
	struct s_cmd	*next;
	bool			wrong_cmd;
	int				empty_arg;
}			t_cmd;

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	char			*word;
	int				var;
	int				sq;
	int				dq;
	enum e_symbol	type;
}			t_node;

typedef struct s_env
{
	char			*var;
	char			*value;
	struct s_env	*next;
}			t_env;

typedef struct s_global
{
	char			*status;
	char			*pid;
	bool			here_doc;
	int				running;
}	t_global;

extern t_global	*g_global;

typedef struct s_pathAndEnv
{
	char		**envp;
	bool		path;
}	t_pathAndEnv;

typedef struct s_data
{
	char	**path;
	char	***cmds;
	int		**pipe_fd;
	pid_t	*pid;
	int		count;
}	t_data;

t_node	*ft_nodenew(char *word);
void	ft_nodeadd_back(t_node **lst, t_node *new);
char	*ft_strdup(char *s);
size_t	ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
t_node	*lexer_mini(char **s);
char	*add_space(char *s);
char	*ft_strtrim(char *s1, char *set);
int		double_quote_cmd(char *s);
int		single_quote_cmd(char *s);
void	fill_the_blanks(char **s, char c);
void	reverse_fill_the_blanks(char **s, char c);
char	**rev_split(char **s);
void	*free_split(char **split, int i);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		find_space(char *s);
void	ft_bzero(void *s, size_t n);
void	ft_lstclear(t_node **lst);
void	free_tab(char **s);
void	replace_pipe(t_node **node);
int		find_char(char *s);
int		is_builtin(char *s);
int		parse(t_node *node);
int		has_dollar(char *s);
int		has_sq(char *s);
int		has_dq(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);
t_cmd	*ft_cmdnew(char *cmd);
void	ft_cmdadd_back(t_cmd **lst, t_cmd *new);
int		var_lenth(char *s, char c);
t_redir	*ft_rednew(enum e_symbol type);
void	ft_redadd_back(t_redir **lst, t_redir *new);
void	ft_cd(t_args *args, char ***env, t_pathAndEnv **pEnv);
void	ft_echo(t_cmd *cmd);
char	*find_env(char **env, char *str);
void	ft_pwd(void);
void	ft_env(char **env);
void	ft_exit(t_cmd *cmd, int flag);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
void	ft_export(t_pathAndEnv **pEnv, t_args *args);
void	ft_unset(t_args *args, char	***env);
void	exec_builtins(t_cmd *cmd, t_pathAndEnv *pEnv, int flag);
void	exec_cmd(t_cmd *cmd, t_pathAndEnv **pEnv);
int		check_path(char *cmd, char **p, t_pathAndEnv *env);
char	*ft_itoa(int n);
t_env	*ft_envnew(char *var, char *value);
void	ft_envadd_back(t_env **lst, t_env *new);
int		ft_envsize(t_env *lst);
t_env	*struct_env(char **envp);
char	**get_env(t_env *envp);
void	set_env(t_env **envp, char *var, char *value);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
void	handle_signals(void);
void	handle_exit(char **line, t_pathAndEnv	**p_env);
char	*ft_strcpy(char *s1, char *s2);
int		ft_lstsize(t_cmd *lst);
void	ft_envdelone(t_env *lst);
void	ft_envclear(t_env **lst);
void	ft_clear_path_env(t_pathAndEnv **lst);
void	ft_redirdelone(t_redir *lst);
void	ft_clear_redir(t_redir **lst);
char	*ft_strjoin_2(char *s1, char *s2);
int		find_emptycmd(char *s);
char	*ft_strndup(char *s, size_t len);
int		empty_string(char *s);
void	ft_skip_quotes(char *s, int *i, char c);
void	ft_fill_rest(char *s2, char *join, size_t i);
void	check_quotes_line_before(t_node **first, char **s);
void	check_pipe_char_line(t_node **first, char **s);
void	ft_start_while(t_node **node, int *len, char **dup);
int		ft_condition1(t_node *node);
int		ft_condition2(t_node *node, char *dup);
int		ft_condition3(t_node *node);
int		ft_condition4(t_node *node);
t_node	*initialize_node(char **s);
int		ft_isalnum(int c);
int		find(char *s, char c);
int		find1(char *s, char c);
int		len_env_var(char *s);
int		ft_parse_line1(char *line);
int		ft_parse_line2(char *line, int i);
int		parse_line(char *line);
void	expand_2(char **s, char **env);
void	expand_var(char **s, char **env);
int		handle_redirections(t_cmd **cmd, char **env);
void	ft_get_struct_helper2(t_redir **red0, t_node *node);
void	ft_get_struct_helper1(char **c, t_node *node, int *b);
void	handle_quotes_vars(t_cmd **cmds, char **env);
void	ft_handle_quotes_helper2(char *s, char **rslt, char **env);
void	expand_files(t_cmd **cmds, char **env);
void	initialize_p_env(t_pathAndEnv **p_env, char **env);
void	main_helper1(char **line, t_node **node);
void	main_helper2(t_pathAndEnv *p_env, t_node *node);
void	ft_reverse_line(char **line);
void	main_helper3(t_node **node, t_pathAndEnv *p_env, char **line);
int		ft_check_args_main(int *argc, char ***argv,
			t_pathAndEnv **p_env, char **env);
int		ft_space_string(char *s);
void	ft_trim_space(char **rslt);
void	replace_tab_space(char **line);
int		here_doc(t_redir *cmd, char **env);
void	redirect_fd(t_cmd *cmd);
void	reset_signals(void);
void	ft_env_ro(t_pathAndEnv **lst);
int		ft_putendl_fd(char *s, int fd);
void	set_status(int status_code);
t_data	*init_execdata(t_cmd *cmd);
int		init_pipes(t_data **data);
int		cleanup_exec_data(t_data *data, int status_code);
void	close_pipes(t_data *data);
void	cleanup_exec(t_data *data);
void	update_env(t_pathAndEnv **pEnv, char *key, char *value);
void	update_shlvl(t_pathAndEnv **pEnv);
void	exec_simplebuiltin(t_cmd *cmd, t_pathAndEnv **pEnv, t_data *data);
void	exec_pipebuiltin(t_cmd *cmd, t_data *data, t_pathAndEnv **pEnv, int i);
void	redirect_pipe(int i, t_data *data);
void	exec_simplecmd(t_cmd *cmd, t_data *data, t_pathAndEnv **pEnv, int i);
void	exec_pipe(t_cmd *cmd, t_data *data, t_pathAndEnv **pEnv, int i);
int		check_execpath(t_cmd *cmd, t_data **data, t_pathAndEnv *pEnv);
char	**get_cmd(t_cmd *cmd);
void	check_str(char *str);
void	ft_heredoc_no_quotes(char *s, char **rslt);
void	expand_args1(t_cmd **cmds, char **env);
t_cmd	*get_structure1(t_node *node);
void	ft_cmdclear1(t_cmd **lst);
void	ft_cmddelone1(t_cmd *lst);
void	ft_argsdelone(t_args *lst);
void	ft_clear_args(t_args **lst);
t_args	*ft_argnew(char *word, enum e_symbol type);
void	ft_argadd_back(t_args **lst, t_args *new);
void	ft_helper_args(t_cmd **cmds, char *s, char *rslt);
void	ft_get_struct_args(t_args **args, t_node *node);
t_cmd	*ft_get_struct_helper4_1(char **c, t_args *args, t_redir *red0, int b);
void	ft_get_struct_helper3_1(t_node *node, t_redir **red0, t_args **args);
void	ft_get_struct_helper0_1(t_redir **red0,
			char **c, t_args **args, int *b);
int		ft_help_parse(char *line, int *i, char c);
void	handle_sigint(int sig);
char	*get_key(char *str);
int		is_valid_numeric_arg(char *str);
void	print_exit_error(char *str, int flag);
int		normalize_exit_code(int num);
void	handle_exit_with_status(int flag);
void	handle_single_numeric_arg(t_cmd *cmd, int flag);
int		check_export(char *str);
char	*get_pid(void);
void	handle_sig_quit(void);
int		handle_path1(char *cmd, char **p);
int		handle_path_err(char **p, char *cmd);
int		handle_path_err1(char **p, char *cmd);
char	*ft_replace_char(char *s);

#endif
