#include <Puissance_4.h>

static int		check_arround(t_p4 *p4, int y, int win, int n)
{
	char c;
	int cpt;
	int tmp_n;

	cpt = 0;
	if (y < 0)
		return (0);
	if ((p4->res == J1_PLAYING && win) || (p4->res == J2_PLAYING && !(win)))
		c = 'X';
	else
		c = 'O';
	while (n > cpt)
	{
		tmp_n = n;
		cpt = 0;;
		while (p4->grid[p4->x + tmp_n++][y] == 'c' && tmp_n < n)
			cpt++;
	}
}

static int		search_lower(t_p4 *p4)
{
	p4->y = 0;
	if (p4->grid[p4->x][p4->y] != ' ')
		return (-1);
	else 
		while(p4->y < p4->lines && p4->grid[p4->x][p4->y] == ' ')
			--p4->y;
		return (p4->y);
}

static int		compute_score(t_p4 *p4)
{
	int y;
	int score;

	y = search_lower(p4);
	score  = 0;
	if (y < 0)
		return (-100);
	else
	{
		if (check_wol(p4, y, 1) || (check_wol(p4, y - 1, 0)))
			score = 100;
		return (score);
	}
}

int		AI_plays(t_p4 *p4)
{
	int tmpx;
	int curr_score;
	int prev_score;

	p4->x = 0;
	prev_score = 0;
	tmpx = 0;
	while (p4->x < p4->columns)
	{
		curr_score = compute_score(p4);
		if (curr_score > prev_score)
		{
			prev_score = curr_score;
			tmpx = p4->x;
		}
		++p4->x;
	}
	return (tmpx);
}
