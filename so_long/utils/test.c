#include "../headers/so_long.h"
#include "../headers/get_next_line.h"

char	*ft_strcpy(char *s1, char *s2)
{
	int i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
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

char	*ft_strchr(const char *s, int c)
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

int main()
{
    const char *a = "  hello  ";
    char *b = ft_strtrim(a, " ");

    
    if (b != NULL)
    {
        char *c = (char *)malloc(ft_strlen(b) + 1); // Allocate memory for c

        if (c != NULL)
        {
            ft_strcpy(b, c); // Copy from b to c
            printf("%s\n", c);

            // Don't forget to free the allocated memory
            free(c);
        }

        // Free memory allocated by ft_strtrim
        free(b);
    }

    return 0;
}