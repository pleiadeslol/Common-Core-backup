#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd = open("hello", O_RDONLY);
    if (fd < 0)
        perror("Error!");
    return 0;
}