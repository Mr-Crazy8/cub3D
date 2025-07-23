#include "parsing.h"


int check_file(char *str)
{
    int fd;
    // int valid_extension = 0;

    fd = open(str, O_RDONLY);
    if(fd == -1)
    {
        write(2, "File doesn't exist or can't be opened\n", 39);
        exit(2);
    }
    // int i = 0;
    size_t len = strlen(str);
    if (len < 4 || strcmp(str + len - 4, ".cub") != 0)
    {
        write(2, "Not valid extension\n", 21);
        exit(2);
    }

    return fd;
}
void print_failed(void)
{
    write(2, "File doesn't exist or can't be opened\n", 39);
    exit(2);
}

int count_lines(char *str)
{
    int fd_2;
    char *tmp;
    int count = 0;
    fd_2 = open(str, O_RDONLY);
    if(fd_2 == -1)
        print_failed();
    while ((tmp = get_next_line(fd_2)) != NULL)
    {
        free(tmp);
        count++;
    }
    close(fd_2);
    return count;
}
char **read_file(int fd, char *str)
{
    char **file;
    char *line;
    int lent;
   
    int i = 0;
   
    lent = count_lines(str);
    file = malloc(sizeof(char *) * (lent+ 1));
    if (!file)
        return NULL;
    line = get_next_line(fd);
    while (line != NULL)
    {
        file[i] = strdup(line);
        free(line);
        i++;
        line = get_next_line(fd);
    }
    file[i] = NULL;
    return file;
}

void parser(char *str)
{
    t_utils *util;
    int fd;
    util =  malloc(sizeof(t_utils));

    util->c_color = malloc(3 * sizeof(int));
    util->f_color = malloc(3 * sizeof(int));
    util->no_fd = -1;
    util->so_fd = -1;
    util->ea_fd = -1;
    util->we_fd = -1;
    util->map = NULL;

    fd = check_file(str);
    char **file = read_file(fd, str);
    extract_and_pars_the_texture(util, file);
    extract_and_pars_the_floor_and_ceiling_color(util, file);
    extract_and_pars_the_map(util, file);
}


int main(int argc, char *argv[])
{
    (void)argc;

    parser(argv[1]);

}