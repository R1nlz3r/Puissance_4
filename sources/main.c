/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 22:46:38 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/04 13:09:38 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance_4.h"

static void		del_p4(t_p4 *p4)
{
	int		tmp;

	tmp = 0;
	while (tmp < 7)
	{
		ft_strdel(&p4->grid[tmp]);
		++tmp;
	}
	ft_memdel((void**)p4->grid);
	ft_memdel((void**)p4);
}

static t_p4		*init_p4(t_p4 *p4)
{
	int		tmp;

	tmp = 0;
	p4 = ft_memalloc(sizeof(t_p4));
	p4->grid = ft_memalloc(sizeof(char**) * 7);
	p4->grid[7] = NULL;
	while (tmp < 7)
	{
		p4->grid[tmp] = ft_strnew(6);
		p4->grid[tmp] = ft_strfill(p4->grid[tmp], 0, 6);
		++tmp;
	}
	return (p4);
}

int				main(int argc, char **argv)
{
	t_p4	*p4;

	p4 = NULL;
	p4 = init_p4(p4);
	display_grid(p4);
	del_p4(p4);
	(void)argc;
	(void)argv;
	return (0);
}
