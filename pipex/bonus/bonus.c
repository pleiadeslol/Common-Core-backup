#include "pipex.h"

size_t ft_strlen(const char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

static int	count_words_str(const char *s, char c)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*fill_words(char const *s, char c)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i] && i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	free_split(char **str, int i)
{
	while (i--)
		free(str[i]);
	free(str);
}

char	**ft_split(char *s, char c)
{
	size_t	i;
	char	**str_f;

	i = 0;
	if (!s)
		return (NULL);
	str_f = (char **)malloc(sizeof(char *) * (count_words_str(s, c) + 1));
	if (str_f == NULL)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		str_f[i] = fill_words(s, c);
		if (!str_f[i])
		{
			free_split(str_f, i);
			return (NULL);
		}
		s += ft_strlen(str_f[i++]);
	}
	str_f[i] = NULL;
	return (str_f);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (str[i] != '\0' && str[i] != (unsigned char)c)
		i++;
	if (str[i] == (unsigned char)c)
	{
		return ((char *)&str[i]);
	}
	return (0);
}

char	*ft_strdup(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (j + 1));
	if (!str)
		return (NULL);
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen((char *)src);
	if (n == 0)
		return (len);
	while (src[i] && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

char	*ft_strtrim(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = 0;
	if (s1 != 0 && s2 != 0)
	{
		i = 0;
		j = ft_strlen((char *)s1);
		while (s1[i] && ft_strchr(s2, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(s2, s1[j - 1]) && j > i)
			j--;
		str = (char *)malloc(sizeof(char) * (j - i + 1));
		if (str)
			ft_strlcpy(str, &s1[i], j - i + 1);
	}
	return (str);
}

static char	*find_home_env(char **envp)
{
	char	*p;
	int		i;

	i = 0;
	p = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "HOME=", 4) == 0)
		{
			p = ft_strchr(envp[i], '=');
			if (p)
				p++;
			break ;
		}
		i++;
	}
	return (p);
}

static void	join_home(char **cmd, int i, char *p)
{
	char	*tmp;

	tmp = ft_strtrim(cmd[i], "~");
	free(cmd[i]);
	cmd[i] = ft_strjoin(p, tmp);
	free(tmp);
}

void	replace_home(char **cmd, char **envp)
{
	char	*p;
	int		i;

	p = find_home_env(envp);
	i = 0;
	while (cmd[i])
	{
		if (ft_strchr(cmd[i], '~'))
			join_home(cmd, i, p);
		i++;
	}
}

t_args	*set_args(int ac, char **av, char **envp)
{
	t_args	*args;
	int		count;
	int		i;

	count = ac - 3;
	i = 0;
	if (ac <= 5)
	{
		write (2, "Error\nMore than 4 arguments needed\n", 35);
		exit(1);
	}
	else
	{
		args = malloc(sizeof(t_args));
		args->file1 = av[1];
        args->cmd = malloc(sizeof(char *) * (count + 1));
		while (count > 0)
		{
			args->cmd[i] = ft_split(av[i + 2], ' ');
			i++;
			count--;
		}
		args->file2 = av[ac - 1];
	}
	i = 0;
	count = ac - 3;
	while (count)
	{
		replace_home(args->cmd[i], envp);
		i++;
		count--;
	}
	return (args);
}

int	main(int ac, char **av, char **envp)
{
	t_args	*args;

	printf("%d\n", ac);
	args = set_args(ac, av, envp);
	int i = 0;
	int j = 0;
	while (args->cmd[i])
	{
		j = 0;
		while (args->cmd[i][j])
		{
			printf("%s\n", args->cmd[i][j]);
			j++;
		}
		i++;
	}
}