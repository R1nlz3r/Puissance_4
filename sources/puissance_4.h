/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance_4.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 22:47:23 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/05 22:06:44 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE_4_H
# define PUISSANCE_4_H

# include "../libft/libft.h"
# include "time.h"

enum	e_result
{
	J1_PLAYING,
	J2_PLAYING,
	DRAW,
	J1,
	J2,
};

enum	e_players
{
	HUMAN,
	AI,
};

typedef struct		s_p4
{
	char			**grid;
	int				x;
	int				y;
	int				lines;
	int				columns;
	enum e_players	j1;
	enum e_players	j2;
	int				scorej1;
	int				scorej2;
	enum e_result	res;
	int				rerun;
}					t_p4;

int					game(t_p4 *p4);
int					ai_plays(t_p4 *p4);
int					check_valid_input(t_p4 *p4, int column);
void				put_on_map(t_p4 *p4, int column);
void				display_grid(t_p4 *p4);
void				check_end_game(t_p4 *p4);
void				display_score(t_p4 *p4);
void				clear_grid(t_p4 *p4);
void				get_lower(t_p4 *p4);

#endif
