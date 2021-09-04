#include "../include/rush02.h"

size_t ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str && str[i])
        i++;
    return (i);
}

// unsigned long long ft_atoull(char *str)
// {
//     size_t i;
//     unsigned long long result;

//     i = 0;
//     result = 0;
//     while (str && str[i])
//         result = 10 * result + str[i++] - 48;
//     return (result);
// }

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

// char *ft_strcat_space(char *s1, char *s2)
// {
//     char *new;
//     size_t i;
//     size_t j;

//     if (!(new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2))))
//         exit_error("malloc=== Error\n");
//     i = 0;
//     while (s1 && s1[i])
//     {
//         new[i] = s1[i];
//         i++;
//     }
//     new[i++] = ' ';
//     j = 0;
//     while (s2 && s2[j])
//         new[i++] = s2[j++];
//     new[i] = '\0';
//     return (new);
// }

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
// char *sub_three(char *str, size_t nb)
// {
//     char *sub;
//     size_t i;
//     size_t j;

//     if (!(sub = malloc(sizeof(char) * 4)))
//         exit_error("malloc=== Error\n");
//     i = nb * 3;
//     j = 0;
//     while (str && str[i] && j < 3)
//         sub[j++] = str[i++];
//     sub[j] = '\0';
//     return (sub);
// }



// bool is_preceded_by_one(char *str, size_t i)
// {
//     if (str && str[i] && i > 0 && str[i - 1] == '1')
//         return (true);
//     return (false);
// }