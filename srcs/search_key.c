#include "../include/rush02.h"

char *search_key_by_length(size_t nb_len, t_dict *head)
{
    while (nb_len > 1 && head && head->next)
    {
        if (nb_len == ft_strlen(head->key) && head->key[0] == '1'
        && is_only_zeros(head->key, 1, ft_strlen(head->key)))
            return (head->word);
        head = head->next;
    }
    return (NULL);
}

char *search_key(char *str, size_t i, t_dict *head)
{
    size_t pos;

    pos = (ft_strlen(str) - 1 - i) % 3;
    // printf("pour str[%ld] = '%c', pos = %ld\n", i, str[i], pos);
    while (head && head->next)
    {
        if (str[i] == head->key[0])
        {
            if (pos == 2 && str[i] != '0' && !head->key[1])
                return (head->word);
                    
            else if (pos == 1 && head->key[1] && !head->key[2] && ((str[i] == '1' && head->key[1] == str[i + 1])
            || (str[i] != '1' && head->key[1] == '0')) )
                return (head->word);
                    
            else if (pos == 0 && !head->key[1] && str[i - 1] != '1'
            && (str[i] != '0' || (str[i] == '0' && is_only_zeros(str, 0, ft_strlen(str)))))
                return (head->word);
        }
        head = head->next;
    }
    return (NULL);
}

// char *search_key_tens(char *nb, size_t i, t_dict *head)
// {
//     while (head && head->next)
//     {
//         if ((nb[i] == '1' && head->key[0] == '1' && head->key[1] == nb[i + 1] && !head->key[2])
//         || (nb[i] != '1' && head->key[0] == nb[i] && head->key[1] == '0' && !head->key[2]) )
//             return (head->word);
//         // printf("looking for [%s], looking at [%s], i = %ld\n", key, head->key, i);
//         head = head->next;
//     }
//     return (NULL);
// }

// char *search_key_unit(char *nb, size_t i, t_dict *head)
// {
//     while (head && head->next)
//     {
//         if (nb[i] == head->key[0] && !head->key[1])
//         {
//             if (nb[i] != '0')// && nb[ft_strlen(nb) - 1])
//                 return (head->word);
//             if (is_only_zeros(nb, 0))
//                 return (head->word);
//         }
//         head = head->next;
//     }
//     return (NULL);
// }

// char *search_key_hund(char key, t_dict *head)
// {
//     while (key != '0' && head && head->next)
//     {
//         if (key == head->key[0] && !head->key[1])
//             return (head->word);
//         head = head->next;
//     }
//     return (NULL);
// }


// char *search_key_str(char *key, t_dict *head)
// {
//     size_t i;

//     while (head && head->next)
//     {
//         i = 0;
//         while (key[i] == head->key[i] && head->key[i] && key[i])
//             i++;
//         if (i == ft_strlen(key) && i == ft_strlen(head->key))
//             return (head->word);
//         head = head->next;
//     }
//     return (NULL);
// }

// char *is_right_key(char *str, size_t i, t_dict *head)
// {
//     size_t pos;

//     pos = (ft_strlen(str) - 1 - i) % 3;
//     if (pos == 2 && str[i] != '0' && !head->key[1])
//         return (head->word);
            
//     else if (pos == 1 && head->key[1] && !head->key[2] &&
//     ( head->key[1] == str[i + 1] || head->key[1] == '0') )
//         return (head->word);
            
//     else if (pos == 0 && !head->key[1] && !is_preceded_by_one(str, i)
//     && (str[i] != '0' || (str[i] == '0' && is_only_zeros(str, 0))))
//         return (head->word);
//     return (NULL);
// }

