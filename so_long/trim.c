#include "includes/so_long.h"
#include "includes/get_next_line.h"

int main()
{
    int fd = open("test", O_RDONLY);
    int i = 0;
    char **str = (char **)malloc(sizeof(char **) * (9 + 1));
    if (!fd)
        return 0;
    while ((str[i] = get_next_line(fd)))
        i++;
    i = 0;
    // while (str[i])
    // {
    //     printf("%s", str[i]);
    //     i++;
    // }
    char **s = (char **)malloc(sizeof(char **) * 10);
    int j = 0;
    while (str[j])
    {
        s[j] = ft_strtrim(str[j], "\n");
        j++;
    }
    j = 0;
    while (s[j])
    {
        printf("%s", s[j]);
        j++;
    }
}