/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:40:57 by akocoglu          #+#    #+#             */
/*   Updated: 2022/05/17 15:02:50 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_right(t_v *v)
{
	if (v->map[v->current_x][v->current_y + 1] == '0')
	{
		v->move_count++;
		ft_printf("Hareket saiyisi - right: %d \n", v->move_count);
		v->map[v->current_x][v->current_y] = '0';
		v->map[v->current_x][v->current_y + 1] = 'P';
		render_map(v);
	}
	else if (v->map[v->current_x][v->current_y + 1] == 'C')
	{
		v->move_count++;
		ft_printf("Hareket saiyisi - right: %d \n", v->move_count);
		v->map[v->current_x][v->current_y] = '0';
		v->map[v->current_x][v->current_y + 1] = 'P';
		render_map(v);
	}
	else if (v->map[v->current_x][v->current_y + 1] == 'E')
	{
		if (validation_c(v) == 0)
		{
			v->move_count++;
			ft_printf("Hareket saiyisi - right: %d \n", v->move_count);
			exit(0);
		}
	}
}

void	go_up(t_v *v)
{
	if (v->map[v->current_x - 1][v->current_y] == '0')
	{
		v->move_count++;
		ft_printf("Hareket saiyisi - up: %d \n", v->move_count);
		v->map[v->current_x][v->current_y] = '0';
		v->map[v->current_x - 1][v->current_y] = 'P';
		render_map(v);
	}
	else if (v->map[v->current_x - 1][v->current_y] == 'C')
	{
		v->move_count++;
		ft_printf("Hareket saiyisi - up: %d \n", v->move_count);
		v->map[v->current_x][v->current_y] = '0';
		v->map[v->current_x - 1][v->current_y] = 'P';
		render_map(v);
	}
	else if (v->map[v->current_x - 1][v->current_y] == 'E')
	{
		if (validation_c(v) == 0)
		{
			v->move_count++;
			ft_printf("Hareket saiyisi - up: %d \n", v->move_count);
			exit(0);
		}
	}
}

void	go_left(t_v *v)
{
	if (v->map[v->current_x][v->current_y - 1] == '0')
	{
		v->move_count++;
		ft_printf("Hareket saiyisi - left: %d \n", v->move_count);
		v->map[v->current_x][v->current_y] = '0';
		v->map[v->current_x][v->current_y - 1] = 'P';
		render_map(v);
	}
	else if (v->map[v->current_x][v->current_y - 1] == 'C')
	{
		v->move_count++;
		ft_printf("Hareket saiyisi - left: %d \n", v->move_count);
		v->map[v->current_x][v->current_y] = '0';
		v->map[v->current_x][v->current_y - 1] = 'P';
		render_map(v);
	}
	else if (v->map[v->current_x][v->current_y - 1] == 'E')
	{
		if (validation_c(v) == 0)
		{
			v->move_count++;
			ft_printf("Hareket saiyisi - left: %d \n", v->move_count);
			exit(0);
		}
	}
}

void	go_down(t_v *v)
{
	if (v->map[v->current_x + 1][v->current_y] == '0')
	{
		v->move_count++;
		ft_printf("Hareket saiyisi - down: %d \n", v->move_count);
		v->map[v->current_x][v->current_y] = '0';
		v->map[v->current_x + 1][v->current_y] = 'P';
		render_map(v);
	}
	else if (v->map[v->current_x + 1][v->current_y] == 'C')
	{
		v->move_count++;
		ft_printf("Hareket saiyisi - down: %d \n", v->move_count);
		v->map[v->current_x][v->current_y] = '0';
		v->map[v->current_x + 1][v->current_y] = 'P';
		render_map(v);
	}
	else if (v->map[v->current_x + 1][v->current_y] == 'E')
	{
		if (validation_c(v) == 0)
		{
			v->move_count++;
			ft_printf("Hareket saiyisi - down: %d \n", v->move_count);
			exit (0);
		}		
	}
}

int	move_king_image(int keycode, t_v *v)
{
	if (keycode == 2)
	{
		go_right(v);
	}
	if (keycode == 13)
	{
		go_up(v);
	}
	if (keycode == 0)
	{
		go_left(v);
	}
	if (keycode == 1)
	{
		go_down(v);
	}
	if (keycode == 53)
		exit(0);
	return (0);
}
