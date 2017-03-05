/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 20:58:21 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/05 20:51:14 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance_4.h"

static int		check_directions(t_p4 *p4, int c)
{
	if ((p4->x < p4->lines - 3 && p4->grid[p4->x][p4->y] == c && \
				p4->grid[p4->x + 1][p4->y] == c && \
				p4->grid[p4->x + 2][p4->y] == c && \
				p4->grid[p4->x + 3][p4->y] == c)
		|| (p4->y < p4->columns - 3 && p4->grid[p4->x][p4->y] == c && \
			p4->grid[p4->x][p4->y + 1] == c && \
			p4->grid[p4->x][p4->y + 2] == c && \
			p4->grid[p4->x][p4->y + 3] == c)
		|| (p4->x < p4->lines - 3 && p4->y < p4->columns - 3 && \
			p4->grid[p4->x][p4->y] == c && \
			p4->grid[p4->x + 1][p4->y + 1] == c && \
			p4->grid[p4->x + 2][p4->y + 2] == c && \
			p4->grid[p4->x + 3][p4->y + 3] == c)
		|| (p4->x < p4->lines - 3 && p4->y >= 3 && \
			p4->grid[p4->x][p4->y] == c && \
			p4->grid[p4->x + 1][p4->y - 1] == c && \
			p4->grid[p4->x + 2][p4->y - 2] == c && \
			p4->grid[p4->x + 3][p4->y - 3] == c))
		return (1);
	else
		return (0);
}

static int		check_draw(t_p4 *p4)
{
	p4->x = 0;
	p4->y = 0;
	while (p4->y < p4->columns && p4->grid[p4->x][p4->y] != ' ')
		++p4->y;
	if (!(p4->y < p4->columns))
		return (1);
	return (0);
}

static int		check_j_win(t_p4 *p4)
{
	char	c;

	c = 'O';
	if (p4->res == J1_PLAYING)
		c = 'X';
	p4->x = 0;
	while (p4->x < p4->lines)
	{
		p4->y = 0;
		while (p4->y < p4->columns)
		{
			if (check_directions(p4, c))
				return (1);
			++p4->y;
		}
		++p4->x;
	}
	return (0);
}

void			check_end_game(t_p4 *p4)
{
	if (check_draw(p4))
		p4->res = DRAW;
	else if (check_j_win(p4))
	{
		if (p4->res == J1_PLAYING)
			p4->res = J1;
		else if (p4->res == J2_PLAYING)
			p4->res = J2;
	}
}
