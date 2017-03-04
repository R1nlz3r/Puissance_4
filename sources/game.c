/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:55:52 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/04 18:17:18 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance_4.h"

//entrée stdrt -> piece dans la grille

static void		j1_plays(t_p4 *p4)
{
	(void)p4;
}

static void		j2_plays(t_p4 *p4)
{
	(void)p4;
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

void		game(t_p4 *p4)
{
	while (p4->rerun)
	{
		srch_first_player(p4);
		while (p4->res == J1_PLAYING || p4->res == J2_PLAYING)
		{
			if (p4->res == J1_PLAYING)
				j1_plays(p4);
			else if (p4->res == J2_PLAYING)
				j2_plays(p4);
			//check
			if (p4->res == J1_PLAYING)
				p4->res = J2_PLAYING;
			else if (p4->res == J2_PLAYING)
				p4->res = J1_PLAYING;
		}
		//afficher le résultat, highlight + score
		//demande de rerun (si oui -> reset)
	}
}
