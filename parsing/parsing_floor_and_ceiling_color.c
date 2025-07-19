#include "parsing.h"


void check_if_in_range(int color)
{
    if(!(color >= 0 && color <= 255))
    {
        write(2, "Color not in range [0 - 255]\n", 30);
        exit(2);
    }
}

int f_c_color_helpr(t_utils *util, char *file)
{
    int i = 0;
    int counter = 0;
    char **split;
    char **split1;

    if (file[0] != 'F' && file[0] != 'C')
        return (0);
    i = 1;
    while (file[i] == ' ' || (file[i] >= 9 && file[i] <= 13))
        i++;
    while (file[i])
    {
        if (file[i] == ',')
            counter++;
            i++;
    }
    if (counter != 2)
    {
        write(2, "not valide color for floor or ceiling\n", 39);
        exit(2);
    }
    split = ft_split(file, " ");
    split1 = ft_split(split[1], ",");
    if (file[0] == 'C')
    {
        util->c_color[0] = ft_atoi(split1[0]);
        check_if_in_range(util->c_color[0]);
        util->c_color[1] = ft_atoi(split1[1]);
        check_if_in_range(util->c_color[1]);
        util->c_color[2] = ft_atoi(split1[2]);
        check_if_in_range(util->c_color[2]);
    }
    else if (file[0] == 'F')
    {
        util->f_color[0] = ft_atoi(split1[0]);
        check_if_in_range(util->f_color[0]);
        util->f_color[1] = ft_atoi(split1[1]);
        check_if_in_range(util->f_color[1]);
        util->f_color[2] = ft_atoi(split1[2]);
        check_if_in_range(util->f_color[2]);
    }
    free_split(split);
    free_split(split1);
    return (1);
}
void extract_and_pars_the_floor_and_ceiling_color(t_utils *util, char **file)
{
    int i = 0;
    int done_f = 0;
    int done_c = 0;
    while (file[i])
    {
        if (file[i][0] == 'F' && done_f == 0)
        {
            f_c_color_helpr(util, file[i]);
            done_f = 1;
        }
        else if (file[i][0] == 'C' && done_c == 0)
        {
        f_c_color_helpr(util, file[i]);
        done_c = 1;
        }
        else if ((file[i][0] == 'F' && done_f == 1)
            || (file[i][0] == 'C' && done_c == 1))
        {
            write(2, "Duplicate color identifier\n", 28);
            exit(2);
        }
        i++;
    }
}

// int f_c_color_helpr(t_utils *util, char *file)
// {
//     int i = 0;
//     int counter = 0;

//     char **split;
//     char **split1;

   
//     while (file[i])
//     {
//         if (file[i] == 'F' || file[i] == 'C')
//                 i++;
//         while (file[i] == ' ' || (file[i] >= 9 && file[i] <= 13))
// 		        i++;
//         while(ft_isdigit(file[i]) == 0)
//                 i++;
//         while (file[i] == ',' )
//         {
//             counter++;
//             i++;
//         }
//         if (counter != 2)
//         {
//             write(2, "not valide color for floor or ceiling\n", 39);
//             exit(2);
//         }
//         i = 0;
//         split = ft_split(file, " ");
//         split1 = ft_split(split[1], ",");

//         if (file[0] == 'C')
//         {
//             util->c_color[0];
//             util->c_color[1];
//             util->c_color[1];
//         }

//         i++;
//     }
// }





// void extract_and_pars_the_floor_and_ceiling_color(t_utils *util, char **file)
// {
//     int i = 0;
//     int j = 0;
    
//     while (file[i])
//     {
//        f_c_color_helpr(util, file[i]);
//        i++;
//     }
// }
//             // if(ft_isdigit(file[i]) == 0 && file[i] != ',' )
//             // {
//             //     if (file[i] == ' ' || (file[i] >= 9 && file[i] <= 13))
// 		    //         i++;
//             //     else if (file[i] == '\n' || file[i] == '\0')
//             //         break;
//             //     else
//             //     {
//             //         write(2, "Invalid character in color\n", 27);
//             //         exit(2);
//             //     }
//             // }
//             // else if (file[i] == ',')
//             // {
//             //     counter +=1;
//             //     i++;
//             // }