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

    while (head && head->next)
    {
        to_free = head;
        head = head->next;
        free(to_free->key);
        free(to_free->word);
        free(to_free);
    }
    free(head->key);
    free(head->word);
    free(head);
}

void show_dic(t_dict *head)
{
    while (head)
    {
        printf("[%s] -> [%s]\n", head->key, head->word);
        head = head->next;
    }
}