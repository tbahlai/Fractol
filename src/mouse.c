/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:30:39 by tbahlai           #+#    #+#             */
/*   Updated: 2019/02/13 17:31:36 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	make_me_zoom(int x, int y, t_frac *frac, double l)
{
	frac->x1 = (x / frac->zoom + frac->x1) - (x / (frac->zoom * l));
	frac->y1 = (y / frac->zoom + frac->y1) - (y / (frac->zoom * l));
	frac->zoom *= l;
	frac->max_iter++;
}

int		julia_mouse(int x, int y, t_frac *frac)
{
	if (frac->ind == 2 && (frac->ind_mouse == 1))
	{
		frac->per_re = (2 * x);
		frac->per_im = (2 * y - 1000);
		threading(frac);
	}
	return (0);
}

int		my_mouse(int button, int x, int y, t_frac *frac)
{
	if (button == 4)
		make_me_zoom(x, y, frac, FOR_ZOOM);
	if (button == 5)
		make_me_zoom(x, y, frac, 1 / FOR_ZOOM);
	if (button == 1)
	{
		frac->x1 -= 20 / frac->zoom;
		frac->y1 -= 20 / frac->zoom;
	}
	if (button == 2)
	{
		frac->x1 += 20 / frac->zoom;
		frac->y1 += 20 / frac->zoom;
	}
	threading(frac);
	return (0);
}
