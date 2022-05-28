/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_another_valid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:57:48 by akocoglu          #+#    #+#             */
/*   Updated: 2022/05/27 17:33:21 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_dif_char(t_v *v)
{
	int	j;

	j = 0;
	while (v->c < v->m_line_s)
	{
		j = 0;
		while (j < (v->col_s - 1))
		{
			if (v->map[v->c][j] == '1' || v->map[v->c][j] == '0')
				;
			else if (v->map[v->c][j] == 'P' || v->map[v->c][j] == 'C')
				;
			else if (v->map[v->c][j] == 'E')
				;
			else
			{
				ft_printf("ERROR \nFARLI BIR KAREKTER VAR \n");
				return (0);
			}
			j++;
		}
		v->c++;
	}
	return (1);
}

int	ft_exit(t_v *v)
{
	free(v);
	exit(1);
	return (0);
}
