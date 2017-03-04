/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:37:48 by agautier          #+#    #+#             */
/*   Updated: 2017/03/04 19:39:23 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "puissance_4.h"

static int		check_draw(t_p4 *p4)
{
	int tmpx;

	tmpx = p4->columns;
	while (p4->grid[tmpx][0] != ' ' && tmpx >= 0)
		tmpx--;
	if (tmpx == 0)
		return (1);
	return (0);
}

static int		check_win(tp4 *p4)
{
	int x;
	int y;

	x = p4->columns;
	y = p4->lines;

}

int		check_finish(t_p4 *p4)
{
	if (check_draw(p4))
		return (1);
	else if (check_win(p4))
		return (2);
	return (0);
}
