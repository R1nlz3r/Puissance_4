#include <Puissance_4.h>

static int both_sides(t_p4 *p4,int s1, int s2, int y, int c, int n)
{
	int tn;
	int cpt;

	cpt = 0;
	while (cpt < n || n < 0)
	{
		tn = 0;
		while (p4->grid[p4->x + (s1 * tn)][y + (s2 * tn)] == c && tn < n)
		{
			tn++;
			cpt++;
		}
		tn = 0;
		while (p4->grid[p4->x - (s1 * tn)][y - (s2 * tn)] == c && tn < n)
		{
			tn++;
			cpt++;
		}
		n--;
	}
	if (cpt >= n)
		return (1);
	else 
		return (0);
}

static int		check_arround(t_p4 *p4, int y, int win, int n)
{
	char c;
	int cpt;

	cpt = 0;
	if (y < 0)
		return (0);
	if ((p4->res == J1_PLAYING && win) || (p4->res == J2_PLAYING && !(win)))
		c = 'X';
	else
		c = 'O';
	if (both_sides(p4, 1, 0, y, c, n) || both_sides(p4, 0, 1, y, c, n) ||\
	both_sides(p4, 1, 1, y, c, n) || both_sides(p4, -1, 1, y, c, n))
		return (1);
	else
		return (0);
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
		if (check_arround(p4, y, 1, 3) || (check_arround(p4, y - 1, 0, 3)))
			score = 100;
		if (check_arround(p4, y, 1, 2))
			score = score + 2;
		if (check_arround(p4, y - 1, 0, 2))
			score = score - 2;
		if (check_arround(p4, y, 1, 1))
			score = score + 1;
		if (check_arround(p4, y - 1, 0, 1))
			score = score - 1;
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
