/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:29:45 by akocoglu          #+#    #+#             */
/*   Updated: 2022/05/27 15:49:08 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./get_nextline/get_next_line.h"
# include "./printf/ft_printf.h"
# include "./printf/libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

typedef struct s_v
{
	void	*wall;
	void	*player;
	void	*princess;
	void	*castle;
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		img_s;
	int		x;
	int		y;
	int		current_x;
	int		current_y;
	int		m_line_s;
	int		col_s;
	int		move_count;
	int		c_count;
	int		p_count;
	int		e_count;
	int		k;
	int		m;
	int		l;
	int		c;
}	t_v;

void	add_wall_image(char obj_name, t_v v);
void	add_flour_image(t_v v);
void	add_collectible_image(t_v v);
void	add_king_image( t_v v);
void	add_princess_image(t_v v);
int		validation_p_c_e(t_v *v);
int		validation_rectangle(t_v *v);
int		validation_map(t_v *v);
int		valid_dif_char(t_v *v);
int		ft_exit(t_v *v);
void	take_map(t_v *v, int i, int j);
int		render_map(t_v *v);
int		validation_c(t_v *v);
void	go_right(t_v *v);
void	go_up(t_v *v);
void	go_left(t_v *v);
void	go_down(t_v *v);
int		move_king_image(int keycode, t_v *v);
int		validation_ber(char *str);
int		find_column_and_line_size(int fd, t_v *v);
void	get_map(int fd, int line_s, t_v *v);
int		main(int argc, char **argv);

#endif
