#include "../include/rush02.h"

// bool display_hundreds(char *str, size_t i, t_dict *dict, bool space)
// {
//     char *word;

//     word = search_key(str, i, dict);
//     if (word)
//     {
//         if (space == true)
//             write(1, " ", 1);
//         ft_putstr(word);
//         write(1, " ", 1);
//         ft_putstr(search_key_by_length(3, dict));
//         return (true);
//     }
//     else if (space == true)
//         return (true);
//     return (false);
// }

// bool display_tens(char *str, size_t i, t_dict *dict, bool space)
// {
//     char *word;

//     word = search_key(str, i, dict);
//     if (word)
//     {
//         if (space == true)
//             write(1, " ", 1);
//         ft_putstr(word);
//         return (true);
//     }
//     else if (space == true)
//         return (true);
//     return (false);
// }

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

// bool display_thousands(char *str, size_t i, t_dict *dict, bool space)
// {
//     char *word;

//     word = search_key_by_length(ft_strlen(str) - i, dict);
//     if (word)
//     {
//         if (space == true)
//             write(1, " ", 1);
//         ft_putstr(word);
//         return (true);
//     }
//     else if (space == true)
//         return (true);
//     return (false);
// }