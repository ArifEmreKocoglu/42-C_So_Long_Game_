
#include "mlx.h"
#include "./get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

typedef struct s_vars
{
    void    *wall;
    void    *player;
    void    *princess;
    void    *castle;
    char    **map;
    void    *mlx;
    void    *mlx_win;
    void    *img;
    int     img_size;
    int     x;
    int     y;
    int     current_x;
    int     current_y;
    int     map_line_size;
    int     map_column_size;
    int     move_count;
}       t_vars;

void    add_wall_image(char obj_name, t_vars vars)
{ 
    vars.img_size = 0;
    char	*relative_path = "./assets/wall.xpm";
    if (obj_name == '1')
    {
        vars.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &vars.img_size, &vars.img_size);
        mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img, vars.x, vars.y);
    }
    
}

void    add_flour_image(char obj_name, t_vars vars)
{
    vars.img_size = 0;
    char	*relative_path = "./assets/ground.xpm";
        vars.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &vars.img_size, &vars.img_size);
        mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img, vars.x, vars.y);
}

void    add_collectible_image(char obj_name, t_vars vars)
{
    vars.img_size = 0;
    char	*relative_path = "./assets/castle1.xpm";
        vars.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &vars.img_size, &vars.img_size);
        mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img, vars.x, vars.y);
}

void    add_king_image(char obj_name, t_vars vars)
{
    vars.img_size = 0;
    char	*relative_path = "./assets/player.xpm";
        vars.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &vars.img_size, &vars.img_size);
        mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img, vars.x , vars.y);

}

void    add_princess_image(char obj_name, t_vars vars)
{
        vars.img_size = 0;
    char	*relative_path = "./assets/princess.xpm";
        vars.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &vars.img_size, &vars.img_size);
        mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img, vars.x, vars.y);

}
int     render_map(t_vars *vars)
{
    int i;
    int j;

    vars->x = 0;
    vars->y = 0;
    i = 0;
    j = 0;
    while(i < vars->map_line_size )
    {
        j = 0;
        vars->x = 0;
        while(j < vars->map_column_size)
        {
            if (vars->map[i][j] == '1')
            {
                add_flour_image(vars->map[i][j], *vars);
                add_wall_image(vars->map[i][j], *vars);   
            }
            else if (vars->map[i][j] == '0')
            {
                add_flour_image(vars->map[i][j], *vars);
            }
            else if (vars->map[i][j] == 'C')
            {
                add_flour_image(vars->map[i][j], *vars);
                add_collectible_image(vars->map[i][j], *vars);
            }
            else if (vars->map[i][j] == 'P')
            {
                add_flour_image(vars->map[i][j], *vars);
                add_king_image(vars->map[i][j], *vars);
                vars->current_x = i;
                vars->current_y = j;
            }
            else if (vars->map[i][j] == 'E')
            {
                add_flour_image(vars->map[i][j], *vars);
                add_princess_image(vars->map[i][j], *vars);
            }
            vars->x += 64;
            j++;
        }
        vars->y += 64;
        i++;
    }
    return (0);
}
void    go_right(t_vars *vars)
{
    if(vars->map[vars->current_x][vars->current_y + 1] == '0')
    {
        vars->map[vars->current_x][vars->current_y] = '0';
        vars->map[vars->current_x][vars->current_y + 1] = 'P';
        render_map(vars);
    }else if(vars->map[vars->current_x][vars->current_y + 1] == 'C')
    {
        vars->map[vars->current_x][vars->current_y] = '0';
        vars->map[vars->current_x][vars->current_y + 1] = 'P';
        render_map(vars);
    }else if(vars->map[vars->current_x][vars->current_y + 1] == 'E')
    {
        exit(0);
    }
}

void    go_up(t_vars *vars)
{
    if(vars->map[vars->current_x - 1][vars->current_y] == '0')
    {
        vars->map[vars->current_x][vars->current_y] = '0';
        vars->map[vars->current_x - 1][vars->current_y] = 'P';
        render_map(vars);
    }else if(vars->map[vars->current_x - 1][vars->current_y] == 'C')
    {
        vars->map[vars->current_x][vars->current_y] = '0';
        vars->map[vars->current_x - 1][vars->current_y] = 'P';
        render_map(vars);
    }
    else if(vars->map[vars->current_x - 1][vars->current_y] == 'E')
    {
        exit(0);
    }
}

void    go_left(t_vars *vars)
{
    
    if(vars->map[vars->current_x][vars->current_y - 1] == '0')
    {
        vars->map[vars->current_x][vars->current_y] = '0';
        vars->map[vars->current_x][vars->current_y - 1] = 'P';
        render_map(vars);
    }else if(vars->map[vars->current_x][vars->current_y - 1] == 'C')
    {
        vars->map[vars->current_x][vars->current_y] = '0';
        vars->map[vars->current_x][vars->current_y - 1] = 'P';
        render_map(vars);
    }
    else if(vars->map[vars->current_x][vars->current_y - 1] == 'E')
    {
        exit(0);
    }
}

void    go_down(t_vars *vars)
{
    if(vars->map[vars->current_x + 1][vars->current_y] == '0')
    {
        vars->map[vars->current_x][vars->current_y] = '0';
        vars->map[vars->current_x + 1][vars->current_y] = 'P';
        render_map(vars);
    }else if(vars->map[vars->current_x + 1][vars->current_y] == 'C')
    {
        vars->map[vars->current_x][vars->current_y] = '0';
        vars->map[vars->current_x + 1][vars->current_y] = 'P';
        render_map(vars);
    }
    else if(vars->map[vars->current_x + 1][vars->current_y] == 'E')
    {
        exit(0);
    }
}

int move_king_image(int keycode, t_vars *vars)
 {
    if(keycode == 2)
    {
        vars->move_count++;
        printf("Hareket saiyisi - right: %d \n", vars->move_count);
        go_right(vars);
    }
    if(keycode == 13)
    {
        vars->move_count++;
        printf("Hareket saiyisi - up: %d \n", vars->move_count);
        go_up(vars);
    }
    if(keycode == 0)
    {
        vars->move_count++;
        printf("Hareket saiyisi - left: %d \n", vars->move_count);
        go_left(vars);
    }
    if(keycode == 1)
    {
        vars->move_count++;
        printf("Hareket saiyisi - down: %d \n", vars->move_count);
        go_down(vars);
    }
    if(keycode == 53)
    {
        exit(0);
    }
    return(0);
}
int    validation_map(t_vars *vars)
{
    int i;
    int j;
    int c_count;
    int p_count;
    int e_count;

    e_count = 0;
    p_count = 0;
    c_count = 0;
    i = 0;
    j = 0;
    while(i < vars->map_line_size)
    {
        j = 0; 
        while(j < (vars->map_column_size - 1))
        {
            if(vars->map[0][j] != '1' || vars->map[vars->map_line_size - 1][j] != '1' || vars->map[i][0] != '1' || vars->map[i][vars->map_column_size - 2] != '1')
            { 
                printf("ERROR \n");
                printf("Etrafi 1 olmalı \n");
                return (0);
            }else
            {
                if(vars->map[i][j] == 'C')
                    c_count++;
                
                if (vars->map[i][j] == 'P')
                    p_count++;
                
                if (vars->map[i][j] == 'E')
                    e_count++;
            }
            if (vars->map_line_size == (vars->map_column_size - 1))
            {
                printf("ERROR \n");
                printf("Dikdortgen olmali \n");
                return(0);
            }
            j++;
        }
        i++;
    }
                if(c_count < 1)
                {
                    printf("ERROR \n");
                    printf("C eksik \n");
                    return (0);
                }
                if(p_count != 1)
                {
                    printf("ERROR \n");
                    printf("P sorunu \n");
                    return (0);
                }
                if (e_count < 1)
                {
                    printf("ERROR \n");
                    printf("E eksik \n");
                    return (0);
                }
    return(1);
}
int main(int argc, char **argv)
{
    t_vars *vars;
    vars = malloc(sizeof(t_vars));
    char    *str;
    int     i;
    int     j;
    char *line;
    int fd;
    char c;
    int line_count;
    int column_size;

    column_size = 0;
    line_count = 0;

    vars->mlx = mlx_init();
    if (argc != 2)
    {
        return (0);
    }
    i = 0;
    fd = open(argv[1], O_RDONLY);
    while(read(fd, &c, 1))
    {
        if(c == '\n')
            line_count++;
        column_size++;
    }
    line_count = line_count + 1;
    column_size = (column_size / line_count) + 1 ;
    vars->map_column_size = column_size;
    vars->map_line_size = line_count;
    vars->mlx_win = mlx_new_window(vars->mlx, (column_size - 1) * 64, (line_count) * 64, "Hello world!");
    close(fd);
    vars->map = (char **)malloc(sizeof(char) * column_size * line_count);
    // line = (char **)malloc(sizeof(char) * column_size * line_count);
    fd= open(argv[1], O_RDONLY);  
        
    while (line_count > 0)
    { 
        line = get_next_line(fd);
        vars->map[i] = line;
        i++;
        line_count--;
    }
    close(fd);
    i = 0;
    j = 0;
    vars->x = 0;
    vars->y = 0;
    while (i < vars->map_line_size)
    {
        j = 0;
        vars->x = 0;
        while( j < (vars->map_column_size - 1))
        {
            if (vars->map[i][j] == '1')
            {
                add_flour_image(vars->map[i][j], *vars);
                add_wall_image(vars->map[i][j], *vars);   
            }
            else if (vars->map[i][j] == '0')
            {
                add_flour_image(vars->map[i][j], *vars);
            }
            else if (vars->map[i][j] == 'C')
            {
                add_flour_image(vars->map[i][j], *vars);
                add_collectible_image(vars->map[i][j], *vars);
            }
            else if (vars->map[i][j] == 'P')
            {
                add_flour_image(vars->map[i][j], *vars);
                add_king_image(vars->map[i][j], *vars);
                vars->current_x = i;
                vars->current_y = j;
            }
            else if (vars->map[i][j] == 'E')
            {
                add_flour_image(vars->map[i][j], *vars);
                add_princess_image(vars->map[i][j], *vars);
            }
            vars->x += 64;
            j++;
        }
        vars->y += 64;
        i++;
    }
    if(validation_map(vars) == 0)
    {
        return (0);
    }
    vars->move_count = 0;
    mlx_key_hook(vars->mlx_win, move_king_image, vars);
    mlx_loop(vars->mlx);
    return (0);
}
