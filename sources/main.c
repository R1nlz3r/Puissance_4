/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 22:46:38 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/04 15:18:25 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance_4.h"

static void		del_p4(t_p4 *p4)
{
	int		tmp;

	tmp = 0;
	while (tmp <= p4->lines)
	{
		ft_strdel(&p4->grid[tmp]);
		++tmp;
	}
	ft_memdel((void**)p4->grid);
	ft_memdel((void**)p4);
}

static t_p4		*init_p4(t_p4 *p4, char **argv)
{
	int		tmp;

	tmp = 0;
	if (!(p4 = ft_memalloc(sizeof(t_p4))) || !(p4->grid =
		ft_memalloc(sizeof(char**) * (unsigned long)(ft_atoi(argv[1]) + 1))))
		return (NULL);
	p4->lines = ft_atoi(argv[1]);
	p4->columns = ft_atoi(argv[2]);
	p4->grid[p4->lines + 1] = NULL;
	while (tmp < p4->lines)
	{
		if (!(p4->grid[tmp] = ft_strnew((size_t)p4->columns)))
			return (NULL);
		p4->grid[tmp] = ft_strfill(p4->grid[tmp], 'X', (size_t)p4->columns);
		++tmp;
	}
	p4->x = 0;
	p4->y = 0;
	return (p4);
}

int				main(int argc, char **argv)
{
	t_p4	*p4;

	p4 = NULL;
	(void)argc;
	if (!argv[1] || !argv[2] || !argv[3] || !argv[4]
		|| ft_atoi(argv[1]) < 6 || ft_atoi(argv[1]) > 99
		|| ft_atoi(argv[2]) < 7 || ft_atoi(argv[2]) > 99
		|| !(ft_atoi(argv[3]) == 1 || ft_atoi(argv[3]) == 2)
		|| !(ft_atoi(argv[4]) == 1 || ft_atoi(argv[4]) == 2))
	{
		ft_putstr("usage: puissance4 [5 < lines < 100] [6 < columns < 100] ");
		ft_putstr("[J1: Humain - 1 / AI - 2] [J2: Humain - 1 / AI - 2] ");
		ft_putendl("[J3+...]");
		return (-1);
	}
	p4 = init_p4(p4, argv);
	p4->lines = ft_atoi(argv[1]);
	p4->columns = ft_atoi(argv[2]);
	display_grid(p4);
	del_p4(p4);
	return (0);
}
