#include "includes/so_long.h"
#include "includes/get_next_line.h"

int main(int ac, char **av)
{
    int fd;
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (0);
    }
    //first let's check if the map is a .ber file
    if (!check_ber(av[1]))
    {
        printf("Map isn't a .ber file\n");
        return (0);
    }
    char **str = malloc(sizeof(char *));
    int i = 0;
    while ((str[i] = get_next_line(fd)))
        i++;
    if (!check_len(str))
    {
        printf("Map isn't rectangular\n");
        return (0);
    }
}