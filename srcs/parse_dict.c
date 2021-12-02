#include "../include/rush02.h"

char *parse_key(int fd)
{
    char buf;
    char *key;
    ssize_t size;

    if (!(key = malloc(sizeof(char))))
        exit_error("malloc===Dict Error\n");
    *key = '\0';
    while ((size = read(fd, &buf, 1)) && size > 0 && buf != ':')
    {
        if (buf != ' ')
            key = ft_append(key, buf, 1);
    }
    if (size == -1)
        exit_error("1.1===Dict Error\n");
    if (size == 0)
    {
        free(key);
        return (NULL);
    }
    return (key);
}

char *parse_word(int fd)
{
    char buf;
    char *word;
    ssize_t size;

    if (!(word = malloc(sizeof(char) + 1)))
        exit_error("malloc===Dict Error\n");
    while ((size = read(fd, &buf, 1)) && size > 0 && buf == ' ')
        ;
    word[0] = buf;
    word[1] = '\0';
    while ((size = read(fd, &buf, 1)) && size > 0 && buf != '\n')
        word = ft_append(word, buf, 1);
    if (size == -1)
        exit_error("1.2===Dict Error\n");
    if (size == 0)
    {
        free(word);
        return (NULL);
    }
    return (word);
}

t_dict *parse_dict(char *dict_name)
{
    t_dict *elem;
    t_dict *head;
    int fd;

    if ((fd = open(dict_name, O_RDONLY)) == -1)
        exit_error("1.0===Dict Error\n");
    head = new_entry(fd);
    while ((elem = new_entry(fd)) && elem->key)
        add_to_list(head, elem);
    free(elem);
    return (head);
}