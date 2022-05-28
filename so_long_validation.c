/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:35:55 by akocoglu          #+#    #+#             */
/*   Updated: 2022/05/27 19:13:15 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_p_c_e(t_v *v)
{
	int	i;

	i = 0;
	while (i < v->m_line_s)
	{
		v->l = 0;
		while (v->l < (v->col_s - 1))
		{
			if (v->map[i][v->l] == 'C')
				v->c_count++;
			if (v->map[i][v->l] == 'P')
				v->p_count++;
			if (v->map[i][v->l] == 'E')
				v->e_count++;
			v->l++;
		}
		i++;
	}
	if (v->c_count < 1 || v->p_count != 1 || v->e_count < 1)
	{
		ft_printf("ERROR \nHarita hatali\n");
		return (0);
	}
	return (1);
}

int	val_rectangle(t_v *v)
{
	if (v->m_line_s == (v->col_s - 1))
	{
		ft_printf("ERROR \nDikdortgen olmali \n");
		return (0);
	}
	return (1);
}

int	validation_map(t_v *v)
{
	while (v->m < v->m_line_s)
	{
		v->k = 0;
		while (v->k < (v->col_s - 1))
		{
			if (v->map[0][v->k] != '1' || v->map[v->m_line_s - 1][v->k] != '1')
			{
				ft_printf("ERROR \nEtrafi 1 olmalı \n");
				return (0);
			}
			if (v->map[v->m][0] != '1' || v->map[v->m][v->col_s - 2] != '1')
			{
				ft_printf("ERROR \nEtrafi 1 olmalı \n");
				return (0);
			}
			v->k++;
		}
		v->m++;
	}
	if (valid_p_c_e(v) == 0 || val_rectangle(v) == 0 || valid_dif_char(v) == 0)
		return (0);
	return (1);
}

int	validation_c(t_v *v)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < v->m_line_s)
	{
		j = 0;
		while (j < (v->col_s - 1))
		{
			if (v->map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validation_ber(char *str)
{
	int	size;
	int	i;

	i = 0;
	size = strlen(str);
	if (str[size - 1] != 'r')
		return (0);
	if (str[size - 2] != 'e')
		return (0);
	if (str[size - 3] != 'b')
		return (0);
	if (str[size - 4] != '.')
		return (0);
	while (i < size)
	{
		if (ft_isascii(str[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}
