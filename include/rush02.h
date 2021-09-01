#ifndef RUSH_02_H
# define RUSH_02_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

// struct s_dict;

typedef struct  s_dict {
    char    *key;
    char    *word;
    struct s_dict  *next;
}               t_dict;

// typedef struct s_tri {
//     char hund;
//     char tens;
//     char unit;
// }               t_tri;               

t_dict *parse_dict(char *dict_name);
t_dict *new_entry(int fd);
void add_to_list(t_dict *head, t_dict *to_add);
void clear_list(t_dict *head);
void show_dic(t_dict *head);
size_t ft_strlen(char *str);
unsigned long long ft_atoull(char *str);
char *ft_append(char *str, char c, int need_free);
void exit_error(char *str);
char *get_key(int fd);
char *get_word(int fd);
void convert_value(char *str, t_dict *dict);
char *search_key(char *key, int pos, t_dict *head);
void ft_bzero(void *ptr, size_t size);
char *search_key_by_length(size_t nb_len, t_dict *head);
void ft_putstr(char *str);
char *sub_three(char *str, size_t nb);

#endif