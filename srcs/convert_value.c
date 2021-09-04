#include "../include/rush02.h"

char *adjust_as_thirds(char *str)
{
    char *new;
    size_t i;
    size_t j;
    size_t rest;

    rest = 3 - ft_strlen(str) % 3;
    if (rest == 3)
        rest = 0;
    if (!(new = malloc(sizeof(char) * (ft_strlen(str) + rest + 1))))
        exit_error("Error\n");
    i = 0;
    j = 0;
    while (j < rest)
        new[j++] = '0';
    while (str[i])
        new[j++] = str[i++];
    new[j] = '\0';
    return (new);
}

void convert_value(char *str, t_dict *dict)
{
    size_t i;
    bool space;

    if (!str)
        exit_error("Error\n");
    str = adjust_as_thirds(str);
    space = false;
    i = 0;
    while (i < ft_strlen(str))
    {
        space = display(search_key(str, i++, dict), space);
        if (str[i - 1] != '0')
            space = display(search_key_by_length(3, dict), space);
        space = display(search_key(str, i++, dict), space);
        space = display(search_key(str, i, dict), space);
        if (!is_only_zeros(str, i - 2, i + 1))
            space = display(search_key_by_length(ft_strlen(str) - i, dict), space);
        i++;
    }
    write(1, "\n", 1);
    free(str);
}
    