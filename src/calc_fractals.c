/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:10:10 by tbahlai           #+#    #+#             */
/*   Updated: 2019/02/13 17:14:06 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	which_fractol_draw(t_frac *frac)
{
	if (frac->ind == 1)
	{
		frac->new_re = frac->old_re * frac->old_re - frac->old_im * \
			frac->old_im + frac->pr;
		frac->new_im = 2 * frac->old_re * frac->old_im + frac->pi;
	}
	else if (frac->ind == 2)
	{
		frac->new_re = frac->old_re * frac->old_re - frac->old_im * \
			frac->old_im + frac->per_re / WID;
		frac->new_im = 2 * frac->old_re * frac->old_im + frac->per_im / WID;
	}
	else if (frac->ind == 3)
	{
		frac->new_re = 2.0 * (frac->old_re + (50 * frac->pr - frac->pi));
		frac->new_im = 2.0 * (frac->old_im + (frac->pr - 50 * frac->pi));
	}
	else if (frac->ind == 4)
	{
		frac->new_re = pow(frac->old_re, 2) - pow(frac->old_im, 2) + 0.29;
		frac->new_im = -2 * frac->old_re * frac->old_im + 0.02;
	}
	else
		return (0);
	return (1);
}

int	which_fractol_draw1(t_frac *frac)
{
	if (frac->ind == 5)
	{
		frac->new_re = fabs(frac->old_re * frac->old_re - \
			frac->old_im * frac->old_im) + 0.35;
		frac->new_im = -2 * frac->old_re * frac->old_im - 0.57;
	}
	else if (frac->ind == 6)
	{
		frac->new_re = frac->old_re / cos(frac->old_im);
		frac->new_im = frac->old_im / sin(frac->old_re);
	}
	else if (frac->ind == 7)
	{
		frac->new_re = frac->old_re * frac->old_re * frac->old_re - 3 * \
			frac->old_re * frac->old_im * frac->old_im + frac->pr;
		frac->new_im = 3 * frac->old_re * frac->old_re * frac->old_im - \
			frac->old_im * frac->old_im * frac->old_im + frac->pi;
	}
	else
		return (0);
	return (1);
}

int	which_fractol_draw2(t_frac *frac)
{
	if (frac->ind == 8)
	{
		frac->new_re = frac->old_re * frac->old_re * frac->old_re * \
			frac->old_re + frac->old_im * frac->old_im * frac->old_im \
			* frac->old_im - 6 * frac->old_re * frac->old_re * \
			frac->old_im * frac->old_im + frac->pr;
		frac->new_im = 4 * frac->old_re * frac->old_im * (frac->old_re * \
			frac->old_re - frac->old_im * frac->old_im) + frac->pi;
	}
	else if (frac->ind == 11)
	{
		frac->new_re = frac->old_re * frac->old_re * frac->old_re * \
			frac->old_re * frac->old_re - 10 * frac->old_re * frac->old_re \
			* frac->old_re * frac->old_im * frac->old_im + 5 * frac->old_re \
			* frac->old_im * frac->old_im * frac->old_im * frac->old_im \
			+ frac->pr;
		frac->new_im = 5 * frac->old_re * frac->old_re * frac->old_re * \
			frac->old_re * frac->old_im - 10 * frac->old_re * frac->old_re \
			* frac->old_im * frac->old_im * frac->old_im + frac->old_im * \
			frac->old_im * frac->old_im * frac->old_im * frac->old_im \
			+ frac->pi;
	}
	else
		return (0);
	return (1);
}

int	which_fractol_draw3(t_frac *frac)
{
	double a;
	double b;
	double c;

	if (frac->ind == 10)
	{
		frac->new_re = frac->old_re * frac->old_re * frac->old_re - 3 * \
			frac->old_re * frac->old_im * frac->old_im;
		frac->new_im = 3 * frac->old_re * frac->old_re * frac->old_im - \
			frac->old_im * frac->old_im * frac->old_im;
		a = sin(frac->new_im);
		b = cos(frac->new_im);
		c = exp(frac->new_re);
		frac->new_re = b + c;
		frac->new_im = b + a;
	}
	else
		return (0);
	return (1);
}

int	which_fractol_draw4(t_frac *frac)
{
	if (frac->ind == 12)
	{
		frac->new_re = frac->old_re * frac->old_re - frac->old_im * \
			frac->old_im + frac->pr;
		frac->new_im = 2 * frac->old_re * frac->old_im + frac->pi;
		frac->pr = frac->old_re + frac->new_re / frac->per_div;
		frac->pi = frac->old_im + frac->new_im / frac->per_div;
	}
	else if (frac->ind == 14)
	{
		frac->new_re = frac->old_re * frac->old_re - frac->old_im * \
			frac->old_im + frac->pr + 0.12;
		frac->new_im = 2 * frac->old_re * frac->old_im + frac->pi;
		frac->pr = frac->old_re / 2 + frac->new_re;
		frac->pi = frac->old_im / 2 + frac->new_im;
	}
	else
		return (0);
	return (1);
}
