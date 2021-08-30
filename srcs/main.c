#include "../include/rush02.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str && str[i])
        i++;
    return (i);
}

void exit_error(char *str)
{
    write(2, str, ft_strlen(str));
    exit(1);
}

int main(int ac, char **av)
{
    t_dict *dict;
    char *dict_name;

    if (ac == 2)
    {
        
        
    }
    else if (ac == 3)
    {
        dict_name = av[2];
    }
    else
        exit_error("Error\n");
    dict = parse_dict("dict.txt");
    convert_value(av[ac - 1]);
}