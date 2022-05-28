/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_add_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:40:07 by akocoglu          #+#    #+#             */
/*   Updated: 2022/05/12 19:01:21 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_wall_image(char obj_name, t_v v)
{
	char	*relative_path;

	relative_path = "./assets/wall.xpm";
	v.img_s = 0;
	if (obj_name == '1')
	{
		v.img = mlx_xpm_file_to_image(v.mlx, relative_path, &v.img_s, &v.img_s);
		mlx_put_image_to_window(v.mlx, v.mlx_win, v.img, v.x, v.y);
	}
}

void	add_flour_image(t_v v)
{
	char	*relative_path;

	relative_path = "./assets/ground.xpm";
	v.img_s = 0;
	v.img = mlx_xpm_file_to_image(v.mlx, relative_path, &v.img_s, &v.img_s);
	mlx_put_image_to_window(v.mlx, v.mlx_win, v.img, v.x, v.y);
}

void	add_collectible_image(t_v v)
{
	char	*relative_path;

	relative_path = "./assets/castle1.xpm";
	v.img_s = 0;
	v.img = mlx_xpm_file_to_image(v.mlx, relative_path, &v.img_s, &v.img_s);
	mlx_put_image_to_window(v.mlx, v.mlx_win, v.img, v.x, v.y);
}

void	add_king_image(t_v v)
{
	char	*relative_path;

	relative_path = "./assets/player.xpm";
	v.img_s = 0;
	v.img = mlx_xpm_file_to_image(v.mlx, relative_path, &v.img_s, &v.img_s);
	mlx_put_image_to_window(v.mlx, v.mlx_win, v.img, v.x, v.y);
}

void	add_princess_image(t_v v)
{
	char	*relative_path;

	relative_path = "./assets/princess.xpm";
	v.img_s = 0;
	v.img = mlx_xpm_file_to_image(v.mlx, relative_path, &v.img_s, &v.img_s);
	mlx_put_image_to_window(v.mlx, v.mlx_win, v.img, v.x, v.y);
}
