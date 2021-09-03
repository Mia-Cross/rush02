#include "../include/rush02.h"

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
        dict_name = "dico.txt";
    else if (ac == 3)
        dict_name = av[2];
    else
        exit_error("0===Error\n");
    dict = parse_dict(dict_name);
    //show_dic(dict);
    convert_value(av[ac - 1], dict);
    write(1, "\n", 1);
    clear_list(dict);
}