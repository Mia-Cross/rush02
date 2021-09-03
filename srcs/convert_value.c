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

    rest = 3 - ft_strlen(str) % 3;
    if (rest == 3)
        rest = 0;
    // printf("rest = %ld, sizeofmalloc = %ld\t", rest, ft_strlen(str) + rest + 1);
    // if (!rest)
    //     return (str);
    if (!(new = malloc(sizeof(char) * (ft_strlen(str) + rest + 1))))
        exit_error("malloc=== Error\n");
    i = 0;
    j = 0;
    while (j < rest)
        new[j++] = '0';
    while (str[i])
        new[j++] = str[i++];
    new[j] = '\0';
    // printf("[%s] to [%s]\n", str, new);
    //free(str);
    return (new);
}

void convert_value(char *str, t_dict *dict)
{
    char *word;
    size_t pos;
    // char *sub;
    size_t i;

    if (!str)
        exit_error("2.0=== Error\n");
    // printf("[%p\n", str);
    // str = adjust_as_thirds(str);
    
    // printf("nb tours -> %ld\n", ft_strlen(str) / 3);
    i = 0;
    // en fait toutes les opes que je fais dans la boucle je dois aussi les faire pour le premier;
    while (i < ft_strlen(str))
    {
        if (i != 0)
            write(1, " ", 1);
        word = search_key_pos(str, i, dict);
        pos = (ft_strlen(str) - 1 - i) % 3;
        ft_putstr(word);
        if (pos == 2 && str[i] != '0')
        {
            write(1, " <100>", 5);
            ft_putstr(search_key_str("100", dict));
        }
        if (pos == 0)
        {
            write(1, " *3*", 4);
            ft_putstr(search_key_by_length(ft_strlen(str) - i, dict));
        }
        // free(word);
        i++;
    }
        
    // while (i < ft_strlen(str) / 3)
    // {
    //     sub = sub_three(str, i);
    //     // ft_putstr(sub);
    //     word = search_key_hund(sub[0], dict);
    //     if (word)
    //     {
    //         ft_putstr(word);
    //         write(1, " ", 1);
    //         ft_putstr(search_key_str("100", dict));
    //         write(1, " ", 1);
    //     }
    //     word = search_key_tens(&sub[1], dict);
    //     if (word)
    //     {
    //         ft_putstr(word);
    //         write(1, " ", 1);
    //     }
    //     word = search_key_unit(sub[2], str, dict);
    //     if (word)
    //     {
    //         ft_putstr(word);
    //         write(1, " ", 1);
    //     }
    //     word = search_key_by_length(ft_strlen(str) - (i * 3), dict);
    //     if (word)
    //     {
    //         ft_putstr(word);
    //         write(1, " ", 1);
    //     }
    //     free(sub);
    //     i++;
    // }
    // str -= (i * 3);
    // printf("%p]\n", str);
    // free(str);
}