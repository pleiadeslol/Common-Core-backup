#include "includes/so_long.h"
#include "includes/get_next_line.h"

int main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    int i = 0;
    int first = 0;
    int last = 0;
    char **line = malloc(sizeof(char **) * 17);
    while ((line[i] = get_next_line(fd)))
    {
        i++;
    }
    int j = 0;
    while (line[j])
    {
        if (ft_strlen(line[j]) > 1 && ft_strlen(line[j - 1]) == 1)
            break ;
        first++;
        j++;
    }
    printf("%d\n", first);
    printf("%d\n", last);
}