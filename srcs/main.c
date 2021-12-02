#include "../include/rush02.h"

int exit_error(char *str)
{
    write(2, str, ft_strlen(str));
    return (1);
}

bool display(char *word, bool space)
{
    if (word)
    {
        if (space == true)
            write(1, " ", 1);
        ft_putstr(word);
        return (true);
    }
    else if (space == true)
        return (true);
    return (false);
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
        exit(exit_error("Error\n"));
    dict = parse_dict(dict_name);
    // show_dic(dict);
    convert_value(av[ac - 1], dict);
    clear_list(dict);
}