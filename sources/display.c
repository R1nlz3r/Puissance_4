/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 11:33:20 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/04 15:16:20 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance_4.h"

static void		display_column_nbrs(t_p4 *p4)
{
	p4->y = 1;
	ft_putstr("  ");
	while (p4->y <= p4->columns)
	{
		ft_putnbr(p4->y);
		if (p4->y + 1 <= p4->columns && p4->y < 10)
			ft_putstr("   ");
		else if (p4->y + 1 <= p4->columns)
			ft_putstr("  ");
		++p4->y;
	}
	if (p4->y <= 10)
		ft_putendl("  ");
	else
		ft_putendl(" ");
}

static void		display_grid_lines(t_p4 *p4)
{
	p4->y = 0;
	while (p4->y < p4->columns)
	{
		ft_putstr("+---");
		++p4->y;
	}
	ft_putendl("+");
}

void			display_grid(t_p4 *p4)
{
	display_column_nbrs(p4);
	p4->x = 0;
	while (p4->x < p4->lines)
	{
		display_grid_lines(p4);
		p4->y = 0;
		while (p4->y < p4->columns)
		{
			ft_putstr("| ");
			ft_putchar(p4->grid[p4->x][p4->y]);
			ft_putstr(" ");
			++p4->y;
		}
		ft_putendl("|");
		++p4->x;
	}
	display_grid_lines(p4);
	display_column_nbrs(p4);
}
