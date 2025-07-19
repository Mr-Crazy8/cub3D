// #include "parsing.h"



// // void check_if_it_texture(char *line)
// // {
// //     char **texture = ft_split(line, ' ');
// //     if (!texture || !texture[1])
// //     {
// //         write(2, "Invalid texture format\n", 23);
// //         exit(2);
// //     }
// //     int fd;
// //     int done_no = 0;
// //     int done_so = 0;
// //     int done_we = 0;
// //     int done_ea = 0;

// //     int len = strlen(texture[1]);
// //     if (len > 0 && texture[1][len-1] == '\n')
// //         texture[1][len-1] = '\0';
// //     if (strcmp(texture[0], "NO") == 0 && done_no == 0)
// //     {
// //         fd = open(texture[1], O_RDONLY);
// //         done_no = 1;
// //         print_error(fd);
// //     }
// //     else if (strcmp(texture[0], "SO") == 0 && done_so == 0)
// //     {
// //         fd = open(texture[1], O_RDONLY);
// //         done_so = 1;
// //         print_error(fd);
// //     }
// //     else if (strcmp(texture[0], "WE") == 0 && done_we == 0)
// //     {
// //         fd = open(texture[1], O_RDONLY);
// //         done_we = 1;
// //         print_error(fd);
// //     }
// //     else if (strcmp(texture[0], "EA") == 0 && done_ea == 0)
// //     {
// //         fd = open(texture[1], O_RDONLY);
// //         done_ea = 1;
// //         print_error(fd);
// //     }
// //     else
// //     {
// //         write(2, "not valide identifier\n", 23);
// //         exit(2);
// //     }
// // }


// // void check_floor_and_ceiling_color(char *line)
// // {
// //     int i = 0;
// //     int counter = 0;
// //     int done_f = 0;
// //     int done_c = 0;

// //     if (line[i] == 'F' || line[i] == 'C')
// //         i++;
// //     while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
// // 		i++;
// //     while(line && line[i])
// //     {
// //         if(ft_isdigit(line[i]) == 0 && line[i] != ',' )
// //         {
// //             if (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
// // 		        i++;
// //             else if (line[i] == '\n' || line[i] == '\0')
// //                 break;
// //             else
// //             {
// //                 write(2, "Invalid character in color\n", 27);
// //                 exit(2);
// //             }
// //         }
// //         else if (line[i] == ',')
// //             {
// //                 counter +=1;
// //                 i++;
// //             }
// //         else
// //             i++;
// //     }
// //     if (counter != 2)
// //     {
// //         write(2, "not valide color for floor or ceiling\n", 39);
// //         exit(2);
// //     }

// // }

// // void check_map(char *line)
// // {
// //     int i;


// //     //look for the player and count how many player we have
// //     while (line && line[i])
// //     {

// //     }

// // }

// // void check_line(char *line)
// // {

// //     int	i;
// // 	i = 0;
// // 	while (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13))
// // 		i++;
    
// //     if (line[i] == '\0' || line[i] == '\n')
// //         return;
// //     if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E' )
// //         check_if_it_texture(line+i);
// //     else if (line[i] == 'F' || line[i] == 'C')
// //         check_floor_and_ceiling_color(line+i);
// //     // else
// //     //     check_map(line+i);
// // }

// // void read_map(int fd)
// // {
// //     char *line;

// //     line = NULL;

// //     while ((line = get_next_line(fd)) != NULL)
// //     {
// //         check_line(line);
// //         free(line);
// //     }

// // }


// int check_file(char *str)
// {
//     int fd;
//     int valid_extension = 0;

//     fd = open(str, O_RDONLY);
//     if(fd == -1)
//     {
//         write(2, "File doesn't exist or can't be opened\n", 39);
//         exit(2);
//     }
//     int i = 0;
//     size_t len = strlen(str);
//     if (len < 4 || strcmp(str + len - 4, ".cub") != 0)
//     {
//         write(2, "Not valid extension\n", 21);
//         exit(2);
//     }

//     return fd;
// }

// char **read_file(int fd)
// {
//     char **file;

    
// }




// void parser(char *str)
// {
//     t_utils *util;
//     int fd;
//     util =  malloc(sizeof(t_utils));

//     fd = check_file(str);
//     char **file = read_file(fd);
//     extract_and_pars_the_texture(util, fd);
//     extract_and_pars_the_floor_and_ceiling_color(util, fd);
//     extract_and_pars_the_map(util, fd);
// }


// int main(int argc, char *argv[])
// {

//     parser(argv[1]);

// }