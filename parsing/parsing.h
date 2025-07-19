#ifndef PARSING_H
# define PARSING_H

#include "get_next_line.h"


typedef struct s_utils
{
    char **c_color;
    char **f_color;
    char **map;
    int no_fd;
    int so_fd;
    int ea_fd;
    int we_fd;
}	t_utils;




void print_error(int fd);
void check_if_it_texture(char *line);
void check_floor_and_ceiling_color(char *line);
void check_line(char *line);
void read_map(int fd);
void parser(char *str);
char	**ft_split(char const *s, char c);

#endif