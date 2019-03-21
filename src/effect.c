/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:27:04 by tbahlai           #+#    #+#             */
/*   Updated: 2019/02/13 17:21:38 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int		psixodel(t_frac *frac)
{
	int sector;

	if (frac->psiho == 1)
	{
		frac->color += 004000100;
		threading(frac);
	}
	if (frac->norm_color == 1)
	{
		sector = rand() % 10;
		(sector == 0) ? frac->color = 1050370 : 1;
		(sector == 1) ? frac->color = 526849 : 1;
		(sector == 2) ? frac->color = 002001006 : 1;
		(sector == 3) ? frac->color = 004001006 : 1;
		(sector == 4) ? frac->color = 262662 : 1;
		(sector == 5) ? frac->color = 001001001 : 1;
		(sector == 6) ? frac->color = 001001006 : 1;
		(sector == 7) ? frac->color = 004002007 : 1;
		(sector == 8) ? frac->color = 000002004 : 1;
		(sector == 9) ? frac->color = 002004005 : 1;
		threading(frac);
	}
	return (0);
}

void	pixel(t_frac *frac, int x, int y, int color)
{
	if (frac->x < WID && frac->y < HEIG)
		*(frac->mlx.img_ptr + (y * WID + x )) = color;
}
