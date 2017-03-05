/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 20:52:04 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/05 22:06:15 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance_4.h"

static int		triple_threat3(t_p4 *p4, char c)
{
	if ((p4->x < p4->columns - 2 && p4->x > 0
		&& p4->grid[p4->y][p4->x + 1] == c && p4->grid[p4->y][p4->x + 2] == c
		&& p4->grid[p4->y][p4->x - 1] == c)
		|| (p4->x < p4->columns - 1 && p4->x > 1
		&& p4->grid[p4->y][p4->x - 1] == c && p4->grid[p4->y][p4->x - 2] == c
		&& p4->grid[p4->y][p4->x + 1] == c)
		|| (p4->x < p4->columns - 2 && p4->x > 0 && p4->y < p4->lines - 2
		&& p4->y > 0 && p4->grid[p4->y + 1][p4->x + 1] == c
		&& p4->grid[p4->y + 2][p4->x + 2] == c
		&& p4->grid[p4->y - 1][p4->x - 1] == c) || (p4->x < p4->columns - 1
		&& p4->x > 1 && p4->y < p4->lines - 2 && p4->y > 0
		&& p4->grid[p4->y + 1][p4->x - 1] == c
		&& p4->grid[p4->y + 2][p4->x - 2] == c
		&& p4->grid[p4->y - 1][p4->x + 1] == c)
		|| (p4->x < p4->columns - 2 && p4->x > 0
		&& p4->y < p4->lines - 1
		&& p4->y > 1 && p4->grid[p4->y - 1][p4->x + 1] == c
		&& p4->grid[p4->y - 2][p4->x + 2] == c
		&& p4->grid[p4->y + 1][p4->x - 1] == c) || (p4->x < p4->columns - 1
		&& p4->x > 1 && p4->y < p4->lines - 1 && p4->y > 1
		&& p4->grid[p4->y - 1][p4->x - 1] == c
		&& p4->grid[p4->y - 2][p4->x - 2] == c
		&& p4->grid[p4->y + 1][p4->x + 1] == c))
		return (1);
	return (0);
}

static int		triple_threat2(t_p4 *p4, char c)
{
	if ((p4->x < p4->columns - 3 && p4->grid[p4->y][p4->x + 1] == c
		&& p4->grid[p4->y][p4->x + 2] == c && p4->grid[p4->y][p4->x + 3] == c)
		|| (p4->x > 2 && p4->grid[p4->y][p4->x - 1] == c
		&& p4->grid[p4->y][p4->x - 2] == c && p4->grid[p4->y][p4->x - 3] == c)
		|| (p4->y < p4->lines - 3 && p4->grid[p4->y + 1][p4->x] == c
		&& p4->grid[p4->y + 2][p4->x] == c && p4->grid[p4->y + 3][p4->x] == c)
		|| (p4->x < p4->columns - 3 && p4->y < p4->lines - 3
		&& p4->grid[p4->y + 1][p4->x + 1] == c
		&& p4->grid[p4->y + 2][p4->x + 2] == c
		&& p4->grid[p4->y + 3][p4->x + 3] == c)
		|| (p4->x > 2 && p4->y < p4->lines - 3
		&& p4->grid[p4->y + 1][p4->x - 1] == c
		&& p4->grid[p4->y + 2][p4->x - 2] == c
		&& p4->grid[p4->y + 3][p4->x - 3] == c)
		|| (p4->x < p4->columns - 3 && p4->y > 2
		&& p4->grid[p4->y - 1][p4->x + 1] == c
		&& p4->grid[p4->y - 2][p4->x + 2] == c
		&& p4->grid[p4->y - 3][p4->x + 3] == c)
		|| (p4->x > 2 && p4->y > 2 && p4->grid[p4->y - 1][p4->x - 1] == c
		&& p4->grid[p4->y - 2][p4->x - 2] == c
		&& p4->grid[p4->y - 3][p4->x - 3] == c))
		return (1);
	else if (triple_threat3(p4, c))
		return (1);
	return (0);
}

static int		triple_threat(t_p4 *p4, char c)
{
	p4->x = 0;
	while (p4->x < p4->columns)
	{
		get_lower(p4);
		if (p4->y >= 0 && triple_threat2(p4, c))
			return (1);
		++p4->x;
	}
	return (0);
}

static int		double_threat(t_p4 *p4, char c)
{
	p4->x = 0;
	while (p4->x < p4->columns)
	{
		get_lower(p4);
		if (p4->y >= 0)
		{
			if ((p4->x < p4->columns - 3 && p4->grid[p4->y][p4->x + 1] == c
				&& p4->grid[p4->y][p4->x + 2] == c
				&& p4->grid[p4->y][p4->x + 3] == ' ')
				|| (p4->x > 2 && p4->grid[p4->y][p4->x - 1] == c
				&& p4->grid[p4->y][p4->x - 2] == c
				&& p4->grid[p4->y][p4->x - 3] == ' '))
				return (1);
		}
		++p4->x;
	}
	return (0);
}

int				ai_plays(t_p4 *p4)
{
	int		tmp;

	if (p4->res == J1_PLAYING && (triple_threat(p4, 'O')
		|| triple_threat(p4, 'X') || double_threat(p4, 'X')
		|| double_threat(p4, 'O')))
		return (p4->x);
	else if (p4->res == J2_PLAYING && (triple_threat(p4, 'X')
		|| triple_threat(p4, 'O') || double_threat(p4, 'O')
		|| double_threat(p4, 'X')))
		return (p4->x);
	while (((tmp = rand() % p4->columns) + 1) && p4->grid[0][tmp] != ' ')
		;
	return (tmp);
}
