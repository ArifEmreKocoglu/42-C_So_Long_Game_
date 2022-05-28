/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:21:36 by akocoglu          #+#    #+#             */
/*   Updated: 2022/05/27 19:09:28 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	take_map(t_v *v, int i, int j)
{
	while (i < v->m_line_s)
	{
		j = 0;
		v->x = 0;
		while (j < (v->col_s - 1))
		{
			add_flour_image(*v);
			if (v->map[i][j] == '1')
				add_wall_image(v->map[i][j], *v);
			else if (v->map[i][j] == 'C')
				add_collectible_image(*v);
			else if (v->map[i][j] == 'P')
			{
				add_king_image(*v);
				v->current_x = i;
				v->current_y = j;
			}
			else if (v->map[i][j] == 'E')
				add_princess_image(*v);
			v->x += 64;
			j++;
		}
		i++;
		v->y += 64;
	}
}

int	render_map(t_v *v)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	v->x = 0;
	v->y = 0;
	mlx_hook(v->mlx_win, 17, 1L << 2, ft_exit, v);
	take_map(v, i, j);
	return (0);
}

int	find_column_and_line_size(int fd, t_v *v)
{
	int		line_s;
	int		column_size;
	char	c;

	column_size = 0;
	line_s = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			line_s++;
		column_size++;
	}
	line_s = line_s + 1;
	column_size = (column_size / line_s) + 1 ;
	v->col_s = column_size;
	v->m_line_s = line_s;
	return (line_s);
}

void	get_map(int fd, int line_s, t_v *v)
{
	char	*line;
	int		i;

	v->k = 0;
	v->m = 0;
	v->l = 0;
	v->c = 0;
	i = 0;
	v->c_count = 0;
	v->p_count = 0;
	v->e_count = 0;
	v->map = (char **)malloc(sizeof(char) * (v->col_s * line_s) + line_s);
	while (line_s > 0)
	{
		line = get_next_line(fd);
		v->map[i] = line;
		i++;
		line_s--;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	int		line_s;
	t_v		*v;

	v = malloc(sizeof(t_v));
	v->mlx = mlx_init();
	if (argc != 2)
		return (0);
	if (validation_ber(argv[1]) == 0)
	{
		ft_printf("ERROR\nmap ismi yanlış\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	line_s = find_column_and_line_size(fd, v);
	v->mlx_win = mlx_new_window(v->mlx, (v->col_s - 1) * 64, line_s * 64, "s");
	close(fd);
	fd = open(argv[1], O_RDONLY);
	get_map(fd, line_s, v);
	if (validation_map(v) == 0)
		return (0);
	render_map(v);
	mlx_key_hook(v->mlx_win, move_king_image, v);
	mlx_loop(v->mlx);
	return (0);
}
