/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 11:33:20 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/05 20:44:49 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance_4.h"

void			display_score(t_p4 *p4)
{
	ft_putendl("\n*************************************");
	if (p4->res == DRAW)
		ft_putendl("**              Draw !             **");
	else if (p4->res == J1 && ++(p4->scorej1))
		ft_putendl("**            \033[31mJ1 gagne !\033[0m           **");
	else if (p4->res == J2 && ++(p4->scorej2))
		ft_putendl("**            \033[33mJ2 gagne !\033[0m           **");
	ft_putstr("**    Score : \033[31mJ1\033[0m - ");
	ft_putnbr(p4->scorej1);
	if (p4->scorej1 < 10)
		ft_putchar(' ');
	ft_putstr(" / \033[33mJ2\033[0m - ");
	ft_putnbr(p4->scorej2);
	if (p4->scorej2 < 10)
		ft_putendl("     **");
	else
		ft_putendl("    **");
	ft_putendl("*************************************");
}

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
	ft_putstr("\033c");
	display_column_nbrs(p4);
	p4->x = 0;
	while (p4->x < p4->lines)
	{
		display_grid_lines(p4);
		p4->y = 0;
		while (p4->y < p4->columns)
		{
			ft_putstr("| ");
			if (p4->grid[p4->x][p4->y] == 'X')
				ft_putstr("\033[31m");
			else if (p4->grid[p4->x][p4->y] == 'O')
				ft_putstr("\033[33m");
			ft_putchar(p4->grid[p4->x][p4->y]);
			ft_putstr("\033[0m");
			ft_putstr(" ");
			++p4->y;
		}
		ft_putendl("|");
		++p4->x;
	}
	display_grid_lines(p4);
	display_column_nbrs(p4);
}
