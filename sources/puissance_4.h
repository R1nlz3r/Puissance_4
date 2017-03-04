/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance_4.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 22:47:23 by mapandel          #+#    #+#             */
/*   Updated: 2017/03/04 18:59:05 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE_4_H
# define PUISSANCE_4_H

# include "../libft/libft.h"
# include "time.h"

enum e_result
{
	J1_PLAYING,
	J2_PLAYING,
	DRAW,
	J1,
	J2,
};

typedef struct	s_p4
{
	char			**grid;
	int				x;
	int				y;
	int				columns;
	int				lines;
	int				j1;
	int				j2;
	int				scorej1;
	int				scorej2;
	enum e_result	res;
	int				rerun;
}					t_p4;

void		game(t_p4 *p4);
void		display_grid(t_p4 *p4);
void		display_score(t_p4 *p4);

#endif
