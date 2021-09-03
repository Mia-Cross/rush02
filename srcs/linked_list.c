#include "../include/rush02.h"

t_dict *new_entry(int fd)
{
    t_dict *new;

    if (!(new = malloc(sizeof(t_dict))))
        exit_error("malloc===Dict Error\n");
    new->key = parse_key(fd);
    new->word = parse_word(fd);
    new->next = NULL;
    return (new);
}

void add_to_list(t_dict *head, t_dict *to_add)
{
    while (head && head->next)
        head = head->next;
    head->next = to_add;
}

void clear_list(t_dict *head)
{
    t_dict *to_free;
    // int i = 1;

    while (head && head->next)
    {
        to_free = head;
        head = head->next;
        free(to_free->key);
        free(to_free->word);
        // printf("erasing entry number %d\n", i++);
        free(to_free);
    }
    free(head->key);
    free(head->word);
    free(head);
}

void show_dic(t_dict *head)
{
    while (head && head->next)
    {
        printf("[%s] -> [%s]\n", head->key, head->word);
        head = head->next;
    }
}

// char *search_key_tens(char *key, t_dict *head)
// {
//     while (head && head->next)
//     {
//         if (head->key[0] == key[0] && head->key[1] == key[1] && !head->key[2])
//             return (head->word);
//         // printf("looking for [%s], looking at [%s], i = %ld\n", key, head->key, i);
//         head = head->next;
//     }
//     while (head && head->next)
//     {
//         if (head->key[0] == key[0] && head->key[1] == '0' && !head->key[2])
//             return (head->word);
//         // printf("looking for [%s], looking at [%s], i = %ld\n", key, head->key, i);
//         head = head->next;
//     }
//     return (NULL);
// }

// char *search_key_unit(char key, char *nb, t_dict *head)
// {
//     size_t i;

//     while (head && head->next)
//     {
//         if (key == head->key[0] && !head->key[1])
//         {
//             if (key != '0' && nb[ft_strlen(nb) - ])
//                 return (head->word);
//             i = 0;
//             while (nb[i] && nb[i] == '0')
//                 i++;
//             if (i == ft_strlen(nb))
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

char *search_key_by_length(size_t nb_len, t_dict *head)
{
    while (nb_len > 3 && head && head->next)
    {
        if (nb_len >= ft_strlen(head->key) && nb_len - ft_strlen(head->key) < 3)
            return (head->word);
        head = head->next;
    }
    return (NULL);
}

char *search_key_str(char *key, t_dict *head)
{
    size_t i;

    while (head && head->next)
    {
        i = 0;
        while (key[i] == head->key[i] && head->key[i] && key[i])
            i++;
        if (i == ft_strlen(key) && i == ft_strlen(head->key))
            return (head->word);
        head = head->next;
    }
    return (NULL);
}

// char *is_right_key(char *str, size_t i, t_dict *elem)
// {
//     size_t pos;

//     pos = (ft_strlen(str) - 1 - i) % 3;
//     if (pos == 2 && str[i] != '0' && !elem->key[1])
//         return (elem->word);
            
//     else if (pos == 1 && elem->key[1] && !elem->key[2] &&
//     ( elem->key[1] == str[i + 1] || elem->key[1] == '0') )
//         return (elem->word);
            
//     else if (pos == 0 && !elem->key[1] && !is_preceded_by_one(str, i)
//     && (str[i] != '0' || (str[i] == '0' && is_only_zeros(str))))
//         return (elem->word);
//     return (NULL);
// }

char *search_key_pos(char *str, size_t i, t_dict *head)
{
    size_t pos;
    t_dict *elem;
    // char *word;

    elem = head;
    pos = (ft_strlen(str) - 1 - i) % 3;
    // printf("pour str[%ld] = '%c', pos = %ld\n", i, str[i], pos);
    while (elem && elem->next)
    {
        if (str[i] == elem->key[0])
        {
            if (pos == 2 && str[i] != '0' && !elem->key[1])
                return (elem->word);
                    
            else if (pos == 1 && elem->key[1] && !elem->key[2] &&
            ( elem->key[1] == str[i + 1] || elem->key[1] == '0') )
                return (elem->word);
                    
            else if (pos == 0 && !elem->key[1] && !is_preceded_by_one(str, i)
            && (str[i] != '0' || (str[i] == '0' && is_only_zeros(str))))
                return (elem->word);
        }
        // while (key[i] ==  && elem->key[i] && key[i])
        //     i++;
        // if (i == ft_strlen(key) && i == ft_strlen(elem->key))
        //     return (elem->word);
        elem = elem->next;
    }
    return (NULL);
}