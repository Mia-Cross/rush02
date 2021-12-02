#include "../include/rush02.h"

size_t ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str && str[i])
        i++;
    return (i);
}

char *ft_append(char *str, char c, int need_free)
{
    char *new;
    size_t i;

    if (!(new = malloc(sizeof(char) * ft_strlen(str) + 2)))
        exit_error("malloc=== Error\n");
    i = 0;
    while (str && str[i])
    {
        new[i] = str[i];
        i++;
    }
    new[i++] = c;
    new[i] = '\0';
    if (need_free)
        free(str);
    return (new);
}

void ft_bzero(void *ptr, size_t size)
{
    char *c;

    if (!ptr)
        return;
    c = ptr;
    while (size--)
        *c++ = '\0';
}

void ft_putstr(char *str)
{
    size_t i;

    i = 0;
    while (str && str[i])
        write(1, &str[i++], 1);
}

bool is_only_zeros(char *str, size_t i, size_t i_max)
{
    while (str && str[i] && str[i] == '0' && i < i_max)
        i++;
    if (i == i_max)
        return (true);
    return (false);
}