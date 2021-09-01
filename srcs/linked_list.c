#include "../include/rush02.h"

t_dict *new_entry(int fd)
{
    t_dict *new;

    if (!(new = malloc(sizeof(t_dict))))
        exit_error("malloc===Dict Error\n");
    new->key = get_key(fd);
    new->word = get_word(fd);
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

    while (head && head->next)
    {
        to_free = head;
        head = head->next;
        free(to_free->key);
        free(to_free->word);
        free(to_free);
    }
    // free(head->word);
    // free(head);
}

void show_dic(t_dict *head)
{
    while (head && head->next)
    {
        printf("[%s] -> [%s]\n", head->key, head->word);
        head = head->next;
    }
}

char *search_key(char *key, int pos, t_dict *head)
{
    size_t i;

    if (pos == 1)
        key = ft_append(key, '0', 0);
    while (head && head->next)
    {
        i = 0;
        while (key[i] && key[i] == head->key[i])
            i++;
        printf("looking for [%s], looking at [%s], i = %ld\n", key, head->key, i);
        if (i == ft_strlen(key) && i == ft_strlen(head->key))
        {
            if (pos == 1)
                free(key);
            return (head->word);
        }
        head = head->next;
    }
    if (pos == 1)
        free(key);
    return (NULL);
}

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
