#ifndef RUSH_02_H
# define RUSH_02_H

# include <unistd.h>
# include <stdlib.h>

typedef struct  s_dict {
    int     key;
    char    *word;
    t_dict  *next;
}               t_dict;

#endif