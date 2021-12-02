#include "../include/rush02.h"

char *search_key_by_length(size_t nb_len, t_dict *head)
{
    while (nb_len > 1 && head)
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
    while (head)
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