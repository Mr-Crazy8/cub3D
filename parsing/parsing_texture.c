#include "parsing.h"


void extract_and_pars_the_texture(t_utils *util, char **file)
{
    int i = 0;
    int j = 0;
    char **texture;
    int fd;

    int done_no = 0;
    int done_so = 0;
    int done_we = 0;
    int done_ea = 0;

    while (file[i])
    {
        if(strchr(file[i], "./") != NULL)
        {
            if(strchr(file[i], "NO") != NULL
            || strchr(file[i], "SO") != NULL
            || strchr(file[i], "EA") != NULL
            || strchr(file[i], "WE") != NULL)
            {
                texture = ft_split(file[i], " ");
                fd = open(texture[1], O_RDONLY);
                print_error(fd);
                if(strcmp(texture[0], "NO") == 0 && done_no == 0)
                {
                    util->no_fd = fd;
                    done_no = 1;
                }
                else if (strcmp(texture[0], "SO") == 0 && done_so == 0)
                {
                    util->so_fd = fd;
                    done_so = 1;
                }
                else if (strcmp(texture[0], "EA") == 0 && done_ea == 0)
                {
                    util->ea_fd = fd;
                    done_ea = 1;
                }
                else if (strcmp(texture[0], "WE") == 0 && done_we == 0)
                {
                    util->we_fd = fd;
                    done_we = 1;
                }
                if (done_ea > 1 || done_no > 1 || done_so > 1 || done_we > 1)
                {
                    write(2, "Duplicate identifier\n", 22);
                    exit(2);
                }
                else
                {
                    write(2, "not valide identifier\n", 23);
                    exit(2);
                }
            }
        }
        i++;
    }
}
