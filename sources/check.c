/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:37:48 by agautier          #+#    #+#             */
/*   Updated: 2017/03/04 23:55:09 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

static int		check_win(t_p4 *p4)
{
	int		x;
	int		y;
	int		is_win;

	x = (p4->columns - 3);
	y = (p4->lines - 3);
	is_win = 0;
	while (y > 2 && !is_win)
		while (x > 2 && !is_win)
		{
			if ((p4->grid[x][y] == 'X' && p4->grid[x + 1][y] == 'X'
			&& p4->grid[x + 2][y] == 'X' && p4->grid[x + 3][y] == 'X')
			|| (p4->grid[x][y] == 'X' && p4->grid[x - 1][y] == 'X'
			&& p4->grid[x - 2][y] == 'X' && p4->grid[x - 3][y] == 'X')
			|| (p4->grid[x][y] == 'X' && p4->grid[x][y + 1] == 'X'
			&& p4->grid[x][y + 2] == 'X' && p4->grid[x][y + 3] == 'X')
			|| (p4->grid[x][y] == 'X' && p4->grid[x - 1][y - 1]
			&& p4->grid[x - 2][y - 2] && p4->grid[x - 3][y - 3])
			|| (p4->grid[x][y] == 'X' && p4->grid[x - 1][y + 1]
			&& p4->grid[x - 2][y + 2] && p4->grid[x - 3][y + 3])
			|| (p4->grid[x][y] == 'X' && p4->grid[x + 1][y - 1]
			&& p4->grid[x + 2][y - 2] && p4->grid[x + 3][y - 3])
			|| (p4->grid[x][y] == 'X' && p4->grid[x + 1][y + 1]
			&& p4->grid[x + 2][y + 2] && p4->grid[x + 3][y + 3]))
				is_win = 1;
			x++;
		}
		y--;
	return (is_win);
}

int		check_finish(t_p4 *p4)
{
	if (check_draw(p4))
		return (1);
	else if (check_win(p4))
		return (2);
	return (0);
}
