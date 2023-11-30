#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int get_next_line(int fd, char *line)
{
    char buf[2];
    int ret;
    int i;

    i = 0;
    while ((ret = read(fd, buf, 1)) > 0)
    {
        if (buf[0] == '\n')
            break;
        line[i] = buf[0];
        i++;
    }
    line[i] = '\0';
    return (ret);

}

int main()
{
    int fd = open ("main.c", O_RDONLY);
    ssize_t size = 1;
    char *line = (char *)malloc(1000);
    while (size > 0)
    {
        size = get_next_line(fd, line);
        printf("%s\n", line);
        free(line);
    }
    return 0;
}