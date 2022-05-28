/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:54:41 by akocoglu          #+#    #+#             */
/*   Updated: 2022/01/31 15:06:21 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int y)
{
	if ((y >= 'A' && y <= 'Z') || (y >= 'a' && y <= 'z'))
	{
		return (1);
	}
	return (0);
}

// int main(void)
// {
//     int a = ft_isalpa(122);
// 		printf("%d",a);
//     return (0);
// }
