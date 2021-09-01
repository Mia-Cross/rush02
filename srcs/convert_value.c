#include "../include/rush02.h"

// t_tri **blocks_of_three(char *str)
// {
//     t_tri **number;
//     size_t i;
//     size_t j;

//     if (!(*number = malloc(sizeof(t_tri) * ((ft_strlen(str) / 3) + 1))))
//         exit_error("malloc=== Error\n");
//     i = ft_strlen(str) - 1;
//     j = () - 1;
//     number[j--] = NULL;
//     while (i > 0 && j > 0)
//     {
//         ft_bzero(number[j], sizeof(t_tri));
//         number[j]->unit = str[i--];
//         number[j]->tens = str[i--];
//         number[j]->hund = str[i--];
//         j--;
//     }
//     ft_bzero(number[0], sizeof(t_tri));
//     number[0]->unit = str[i--];
//     number[0]->tens = str[i--];
//     number[0]->hund = str[i--];
//     return (number);
// }

char *adjust_as_thirds(char *str)
{
    char *new;
    size_t i;
    size_t j;
    size_t rest;

    rest = ft_strlen(str) % 3;
    if (!rest)
        return (str);
    if (!(new = malloc(sizeof(char) * (ft_strlen(str) + rest + 1))))
        exit_error("malloc=== Error\n");
    i = 0;
    j = 0;
    while (j < rest)
        new[j++] = '0';
    while (str[i])
        new[j++] = str[i++];
    new[j] = '\0';
    free(str);
    return (new);
}

void convert_value(char *str, t_dict *dict)
{
    // char *word;
    char *sub;
    size_t i;

    if (!str)
        exit_error("2.0=== Error\n");
    str = adjust_as_thirds(str);
    i = 0;
    while (i < ft_strlen(str) / 3)
    {
        sub = sub_three(str, i);
        ft_putstr(sub);
        ft_putstr(search_key(&sub[0], 0, dict));
        ft_putstr(search_key(&sub[1], 1, dict));
        ft_putstr(search_key(&sub[2], 2, dict));
        ft_putstr(search_key_by_length(ft_strlen(str), dict));
        free(sub);
        i++;
    }
}