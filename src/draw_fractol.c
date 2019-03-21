/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:03:28 by tbahlai           #+#    #+#             */
/*   Updated: 2019/02/13 17:20:18 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int		which_fractol_draw5(t_frac *frac)
{
	if (frac->ind == 13)
	{
		frac->new_re = frac->old_re / cos(frac->old_im) + frac->re;
		frac->new_im = frac->old_im / sin(frac->old_re) - frac->im;
	}
	else if (frac->ind == 9)
	{
		frac->new_re = (frac->old_re * frac->old_re - (frac->old_im * \
			frac->old_im * 3)) * fabs(frac->old_re) + frac->pr;
		frac->new_im = ((frac->old_re * frac->old_re * 3) - frac->old_im * \
			frac->old_im) * fabs(frac->old_im) + frac->pi;
	}
	else if (frac->ind == 15)
	{
		frac->new_re = frac->old_re * frac->old_re - frac->old_im * \
			frac->old_im + frac->pr;
		frac->new_im = 2 * frac->old_re * frac->old_im + frac->pi;
		frac->pr = -cos(frac->new_im) - sin(frac->new_im) + 0.1;
		frac->pi = sin(frac->new_re);
	}
	else
		return (0);
	return (1);
}

void	calc_fractol(t_frac *frac)
{
	int i;

	i = 0;
	frac->pr = frac->x * 1.0 / frac->zoom + frac->x1;
	frac->pi = frac->y * 1.0 / frac->zoom + frac->y1;
	REWRITE(frac->old_re, frac->pr, frac->old_im, frac->pi);
	TO_ZERO(frac->new_re, frac->new_im);
	while (i < frac->max_iter && (frac->old_re * frac->old_re + frac->old_im * \
		frac->old_im) < 16)
	{
		if ((which_fractol_draw(frac) == 0) && \
			(which_fractol_draw1(frac) == 0) && \
			(which_fractol_draw2(frac) == 0) && \
			(which_fractol_draw4(frac) == 0) && \
			which_fractol_draw5(frac) == 0)
			which_fractol_draw3(frac);
		REWRITE(frac->old_re, frac->new_re, frac->old_im, frac->new_im);
		i++;
	}
	if (i == frac->max_iter)
		pixel(frac, frac->x, frac->y, 0);
	else
		pixel(frac, frac->x, frac->y, (frac->color * i));
}

void	*draw_fractol(void *data)
{
	t_frac *frac;

	frac = (t_frac*)data;
	frac->y = HEIG / THREADS * frac->thread_id;
	while (frac->y < HEIG / THREADS * (frac->thread_id + 1))
	{
		frac->x = 0;
		while (frac->x < WID)
		{
			calc_fractol(frac);
			frac->x++;
		}
		frac->y++;
	}
	return (data);
}
