/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:55:52 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/05 20:55:45 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance_4.h"

static int		rerun(t_p4 *p4)
{
	char	*buf;

	if ((p4->scorej1 == 99 || p4->scorej2 == 99) && !(p4->rerun = 0))
		return (0);
	buf = ft_strnew(1000000);
	ft_putendl("\n> Rejouer? 1: Oui. 2: Non.");
	if (read(0, buf, 1000000) == -1)
		return (-1);
	while (!(ft_atoi(buf) == 1 || ft_atoi(buf) == 2))
	{
		ft_putendl("> Input invalide, réesaye.");
		ft_strclr(buf);
		if (read(0, buf, 1000000) == -1 || buf[999999])
			return (-1);
	}
	p4->rerun = 0;
	if (ft_atoi(buf) == 1)
		p4->rerun = 1;
	clear_grid(p4);
	ft_strdel(&buf);
	return (0);
}

static int		j_plays(t_p4 *p4)
{
	char	*buf;

	buf = ft_strnew(1000000);
	if (p4->res == J1_PLAYING)
		ft_putendl("\n> \033[31mJoueur 1\033[0m : À toi de jouer");
	else if (p4->res == J2_PLAYING)
		ft_putendl("\n> \033[33mJoueur 2\033[0m : À toi de jouer");
	if (read(0, buf, 1000000) == -1)
		return (-1);
	while (check_valid_input(p4, ft_atoi(buf) - 1) == -1)
	{
		ft_putendl("> Input invalide, réesaye.");
		ft_strclr(buf);
		if (read(0, buf, 1000000) == -1 || buf[999999])
			return (-1);
	}
	put_on_map(p4, ft_atoi(buf) - 1);
	ft_strdel(&buf);
	return (0);
}

static void		srch_first_player(t_p4 *p4)
{
	srand((unsigned)time(NULL));
	if (p4->res == DRAW)
	{
		if (rand() % 2)
			p4->res = J2_PLAYING;
		else
			p4->res = J1_PLAYING;
	}
	else if (p4->res == J1)
		p4->res = J2_PLAYING;
	else if (p4->res == J2)
		p4->res = J1_PLAYING;
}

int				game(t_p4 *p4)
{
	while (p4->rerun)
	{
		srch_first_player(p4);
		while (p4->res == J1_PLAYING || p4->res == J2_PLAYING)
		{
			display_grid(p4);
			if (((p4->res == J1_PLAYING && p4->j1 == HUMAN) || \
						(p4->res == J2_PLAYING && p4->j2 == HUMAN)) && \
					j_plays(p4) == -1)
				return (-1);
			else if ((p4->res == J1_PLAYING && p4->j1 == AI) || \
					(p4->res == J2_PLAYING && p4->j2 == AI))
				put_on_map(p4, ai_plays(p4));
			check_end_game(p4);
			if (p4->res == J1_PLAYING)
				p4->res = J2_PLAYING;
			else if (p4->res == J2_PLAYING)
				p4->res = J1_PLAYING;
		}
		display_grid(p4);
		display_score(p4);
		if (rerun(p4) == -1)
			return (-1);
	}
	return (0);
}
