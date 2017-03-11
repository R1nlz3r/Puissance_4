/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 20:52:04 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/11 14:15:56 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance_4.h"

static int		triple_threat(t_p4 *p4, char c)
{
	int		way;

	way = rand() % 2;
	p4->x = p4->columns - 1;
	if (way)
		p4->x = 0;
	while (p4->x < p4->columns && p4->x >= 0)
	{
		get_lower(p4);
//droite
		if (p4->y >= 0 && ((p4->x + 3 < p4->columns && p4->grid[p4->y][p4->x + 1] == c && p4->grid[p4->y][p4->x + 2] == c && p4->grid[p4->y][p4->x + 3] == c)
//gauche
			|| (p4->x > 2 && p4->grid[p4->y][p4->x - 1] == c && p4->grid[p4->y][p4->x - 2] == c && p4->grid[p4->y][p4->x - 3] == c)
//vertical
			|| (p4->y + 3 < p4->lines && p4->grid[p4->y + 1][p4->x] == c && p4->grid[p4->y + 2][p4->x] == c && p4->grid[p4->y + 3][p4->x] == c)
//diagonale
			|| (p4->x + 3 < p4->columns && p4->y + 3 < p4->lines && p4->grid[p4->y + 1][p4->x + 1] == c && p4->grid[p4->y + 2][p4->x + 2] == c && p4->grid[p4->y + 3][p4->x + 3] == c)
			|| (p4->x > 2 && p4->y + 3 < p4->lines && p4->grid[p4->y + 1][p4->x - 1] == c && p4->grid[p4->y + 2][p4->x - 2] == c && p4->grid[p4->y + 3][p4->x - 3] == c)
//diagonale
			|| (p4->x + 3 < p4->columns && p4->y > 2 && p4->grid[p4->y - 1][p4->x + 1] == c && p4->grid[p4->y - 2][p4->x + 2] == c && p4->grid[p4->y - 3][p4->x + 3] == c)
			|| (p4->x > 2 && p4->y > 2 && p4->grid[p4->y - 1][p4->x - 1] == c && p4->grid[p4->y - 2][p4->x - 2] == c && p4->grid[p4->y - 3][p4->x - 3] == c)
//troué
			|| (p4->x + 2 < p4->columns && p4->x > 0 && p4->grid[p4->y][p4->x + 1] == c && p4->grid[p4->y][p4->x + 2] == c && p4->grid[p4->y][p4->x - 1] == c)
			|| (p4->x + 1 < p4->columns && p4->x > 1 && p4->grid[p4->y][p4->x - 1] == c && p4->grid[p4->y][p4->x - 2] == c && p4->grid[p4->y][p4->x + 1] == c)
			|| (p4->x + 2 < p4->columns && p4->x > 0 && p4->y + 2 < p4->lines && p4->y > 0 && p4->grid[p4->y + 1][p4->x + 1] == c && p4->grid[p4->y + 2][p4->x + 2] == c && p4->grid[p4->y - 1][p4->x - 1] == c)
			|| (p4->x + 1 < p4->columns && p4->x > 1 && p4->y + 2 < p4->lines && p4->y > 0 && p4->grid[p4->y + 1][p4->x - 1] == c && p4->grid[p4->y + 2][p4->x - 2] == c && p4->grid[p4->y - 1][p4->x + 1] == c)
			|| (p4->x + 2 < p4->columns && p4->x > 0 && p4->y + 1 < p4->lines && p4->y > 1 && p4->grid[p4->y - 1][p4->x + 1] == c && p4->grid[p4->y - 2][p4->x + 2] == c && p4->grid[p4->y + 1][p4->x - 1] == c)
			|| (p4->x + 1 < p4->columns && p4->x > 1 && p4->y + 1 < p4->lines && p4->y > 1 && p4->grid[p4->y - 1][p4->x - 1] == c && p4->grid[p4->y - 2][p4->x - 2] == c && p4->grid[p4->y + 1][p4->x + 1] == c)))
			return (1);
		--p4->x;
		if (way)
			p4->x += 2;
	}
	return (0);
}

static int		double_threat(t_p4 *p4, char c)
{
	int		way;

	way = rand() % 2;
	p4->x = p4->columns - 1;
	if (way)
		p4->x = 0;
	while (p4->x < p4->columns && p4->x >= 0)
	{
		get_lower(p4);
		if (p4->y >= 0)
		{
			if ((p4->x - 3 < p4->columns && p4->grid[p4->y][p4->x + 1] == c && p4->grid[p4->y][p4->x + 2] == c && p4->grid[p4->y][p4->x + 3] == ' ')
				|| (p4->x > 2 && p4->grid[p4->y][p4->x - 1] == c && p4->grid[p4->y][p4->x - 2] == c && p4->grid[p4->y][p4->x - 3] == ' '))
				return (1);
		}
		--p4->x;
		if (way)
			p4->x += 2;
	}
	return (0);
}

static int		double_up(t_p4 *p4, char c)
{
	int		way;

	way = rand() % 2;
	p4->x = p4->columns - 1;
	if (way)
		p4->x = 0;
	while (p4->x < p4->columns && p4->x >= 0)
	{
		get_lower(p4);
		if (p4->y >= 0 && ((p4->x + 1 < p4->columns && p4->grid[p4->y][p4->x + 1] == c) || (p4->x - 1 >= 0 && p4->grid[p4->y][p4->x - 1] == c)))
			return (1);
		--p4->x;
		if (way)
			p4->x += 2;
	}
	p4->x = p4->columns - 1;
	if (way)
		p4->x = 0;
	while (p4->x < p4->columns && p4->x >= 0)
	{
		get_lower(p4);
		if (p4->y >= 1 && p4->y + 1 < p4->lines && p4->grid[p4->y + 1][p4->x] == c)
			return (1);
		--p4->x;
		if (way)
			p4->x += 2;
	}
	return (0);
}

int				ai_plays(t_p4 *p4)
{
	int		tmp;

	if (p4->res == J1_PLAYING && (triple_threat(p4, 'X')
		|| triple_threat(p4, 'O') || double_threat(p4, 'O')
		|| double_threat(p4, 'X') || double_up(p4, 'X')))
		return (p4->x);
	else if (p4->res == J2_PLAYING && (triple_threat(p4, 'O')
		|| triple_threat(p4, 'X') || double_threat(p4, 'X')
		|| double_threat(p4, 'O') || double_up(p4, 'O')))
		return (p4->x);
	while (((tmp = rand() % p4->columns) + 1) && p4->grid[0][tmp] != ' ')
		;
	return (tmp);
}
