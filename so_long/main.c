#include "includes/so_long.h"

int main(int ac, char **av)
{
    int fd;

    fd = open(av[1], O_RDONLY);
    if (fd < 0)
        return (NULL);
    
}