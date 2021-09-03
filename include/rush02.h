#ifndef RUSH_02_H
# define RUSH_02_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
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
char *ft_strcat_space(char *s1, char *s2);
void exit_error(char *str);
char *parse_key(int fd);
char *parse_word(int fd);
void convert_value(char *str, t_dict *dict);
char *search_key_str(char *key, t_dict *head);
char *search_key_unit(char key, char *nb, t_dict *head);
char *search_key_hund(char key, t_dict *head);
char *search_key_tens(char *key, t_dict *head);
void ft_bzero(void *ptr, size_t size);
char *search_key_by_length(size_t nb_len, t_dict *head);
void ft_putstr(char *str);
char *sub_three(char *str, size_t nb);
char *search_key_pos(char *str, size_t i, t_dict *head);
bool is_only_zeros(char *str);
bool is_preceded_by_one(char *str, size_t i);
char *is_right_key(char *str, size_t i, t_dict *elem);

#endif