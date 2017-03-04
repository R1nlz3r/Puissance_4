/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 11:33:20 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/04 12:59:17 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance_4.h"

void	display_grid(t_p4 *p4)
{
	int		x;
	int		y;
	int		tmp;

	x = 0;
	tmp = (int)(ft_strlen(p4->grid[x]) * 2 + 1);
	ft_putchar('X');
	while (tmp)
	{
		ft_putchar('=');
		--tmp;
	}
	ft_putstr("\n");
	while (p4->grid[x])
	{
		y = 0;
		ft_putstr("||");
		while (p4->grid[x][y])
		{
			ft_putchar('a');
			if (p4->grid[x][y + 1])
				ft_putchar('|');
			++y;
		}
		ft_putstr("||\n");
		++x;
	}
	y = 0;
	tmp = (int)(ft_strlen(p4->grid[x]));
	ft_putstr("==");
	while (y < tmp)
	{
		ft_putnbr(y);
		if (y == tmp -1)
			ft_putchar('=');
		++y;
	}
	ft_putstr("==\n");
}
