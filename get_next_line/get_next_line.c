#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int getnextline(char **line)
{
    char c;
    char buf[1024];
    int ret;
    int i;
    i = 0;
    while ((ret = read(0, &c, 1)))
    {
        if (ret == -1)
            return (-1);
        if (c == '\n')
            break;
        else
            buf[i++] = c;
    }
    buf[i] = '\0';
    *line = malloc(strlen((char *)buf));
    strcpy(*line, buf);
    if (ret == 0)
        return (0);
    return (1);
}
