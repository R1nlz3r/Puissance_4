/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_put_on_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 20:42:25 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/05 22:07:17 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance_4.h"

void	get_lower(t_p4 *p4)
{
	p4->y = p4->lines - 1;
	while (p4->y >= 0 && p4->grid[p4->y][p4->x] != ' ')
		--p4->y;
}

void	put_on_map(t_p4 *p4, int column)
{
	p4->x = p4->lines - 1;
	p4->y = column;
	while (p4->x >= 0)
	{
		if (p4->grid[p4->x][p4->y] == ' ' && p4->res == J1_PLAYING)
		{
			p4->grid[p4->x][p4->y] = 'X';
			break ;
		}
		else if (p4->grid[p4->x][p4->y] == ' ' && p4->res == J2_PLAYING)
		{
			p4->grid[p4->x][p4->y] = 'O';
			break ;
		}
		--p4->x;
	}
}

int		check_valid_input(t_p4 *p4, int column)
{
	if (column < 0 || column >= p4->columns || p4->grid[0][column] != ' ')
		return (-1);
	return (0);
}
