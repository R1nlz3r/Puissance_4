/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 22:46:38 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/05 20:58:51 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance_4.h"

void			clear_grid(t_p4 *p4)
{
	p4->x = 0;
	p4->y = 0;
	while (p4->x < p4->lines)
	{
		ft_strfill(p4->grid[p4->x], ' ', (size_t)(p4->columns));
		++p4->x;
	}
}

static void		del_p4(t_p4 *p4)
{
	int		tmp;

	tmp = 0;
	while (tmp < p4->lines)
	{
		ft_strdel(&p4->grid[tmp]);
		++tmp;
	}
	ft_memdel((void**)p4->grid);
	ft_memdel((void**)p4);
}

static void		init_p4_2(t_p4 *p4)
{
	p4->x = 0;
	p4->y = 0;
	p4->scorej1 = 0;
	p4->scorej2 = 0;
	p4->res = DRAW;
	p4->j1 = HUMAN;
	p4->j2 = HUMAN;
}

static t_p4		*init_p4(t_p4 *p4, char **argv)
{
	int		tmp;

	tmp = 0;
	if (!(p4 = ft_memalloc(sizeof(t_p4))) || \
			!(p4->grid = ft_memalloc(sizeof(char**) * \
					(unsigned long)ft_atoi(argv[1]))))
		return (NULL);
	p4->lines = ft_atoi(argv[1]);
	p4->columns = ft_atoi(argv[2]);
	p4->grid[p4->lines] = NULL;
	while (tmp < p4->lines)
	{
		if (!(p4->grid[tmp] = ft_strnew((size_t)p4->columns)))
			return (NULL);
		p4->grid[tmp] = ft_strfill(p4->grid[tmp], ' ', (size_t)p4->columns);
		++tmp;
	}
	init_p4_2(p4);
	if (ft_atoi(argv[3]) == 2)
		p4->j1 = AI;
	if (ft_atoi(argv[4]) == 2)
		p4->j2 = AI;
	p4->rerun = 1;
	return (p4);
}

int				main(int argc, char **argv)
{
	t_p4	*p4;

	p4 = NULL;
	if (argc != 5 || ft_atoi(argv[1]) < 6 || ft_atoi(argv[1]) > 99
		|| ft_atoi(argv[2]) < 7 || ft_atoi(argv[2]) > 99
		|| !(ft_atoi(argv[3]) == 1 || ft_atoi(argv[3]) == 2)
		|| !(ft_atoi(argv[4]) == 1 || ft_atoi(argv[4]) == 2))
	{
		ft_putstr("usage: puissance4 [5 < lines < 100] [6 < columns < 100] ");
		ft_putendl("[J1: Humain - 1 / AI - 2] [J2: Humain - 1 / AI - 2]");
		return (-1);
	}
	p4 = init_p4(p4, argv);
	if (game(p4) == -1)
		return (-1);
	del_p4(p4);
	return (0);
}
