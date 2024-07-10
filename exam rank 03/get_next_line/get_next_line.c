#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

char    *ft_strchr(const char *s, int c)
{
    size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

size_t ft_strlen(const char *s)
{
    size_t i = 0;
    while (s[i])
        i++;
    return (i);
}

char *ft_strdup(char *s)
{
    int i = 0;
    int j = ft_strlen(s);
    char *str;
    str = (char *)malloc(sizeof(char) * (j + 1));
    if (!str)
        return NULL;
    while (i < j)
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return str;
}

char *ft_strjoin(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    char *str;

    if (!s1)
        s1 = ft_strdup("");
    str = (char *)malloc(sizeof(char) *
        (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
    if (!str)
        return NULL;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    while(s2[j])
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = '\0';
    free(s1);
    return (str);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t i;
    size_t j;
    size_t s_len;
    char *str;

    i = 0;
    j = 0;
    if (!s)
        return NULL;
    s_len = ft_strlen(s);
    if (start >= s_len)
        return (ft_strdup(""));
    if (start + len > s_len)
        len = s_len - start;
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return NULL;
    while (s[i++])
    {
        if (i - 1 >= start && j < len)
            str[j++] = s[i - 1];
    }
    str[j] = '\0';
    return str;
}
static char *get_clean_line(char *buffer)
{
    int i = 0;

    if (!*buffer)
        return (NULL);
    while (buffer[i] && buffer[i] != '\n')
        i++;
    return (ft_substr(buffer, 0, i + 1));
}

static char *get_clean_buffer(char *buffer)
{
    int i = 0;
    char *str;

    if (!*buffer)
    {
        free(buffer);
        return NULL;
    }
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n')
        i++;
    str = ft_strdup(buffer + i);
    free(buffer);
    return str;
}

char    *get_next_line(int fd)
{
    char    *line;
    char    *clean_line;
    static char *buffer;
    ssize_t end;

    end = 1;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = (char *)malloc(BUFFER_SIZE + 1);
    if (!line)
        return (NULL);
    line[0] = 0;
    while (end > 0 && !ft_strchr(line, '\n'))
    {
        end = read(fd, line, BUFFER_SIZE);
        if (end < 0)
            return (free(line), free(buffer), NULL);
        line[end] = '\0';
        buffer = ft_strjoin(buffer, line);
    }
    clean_line = get_clean_line(buffer);
    buffer = get_clean_buffer(buffer);
    free(line);
    return (clean_line);
}
