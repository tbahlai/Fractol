/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:29:59 by tbahlai           #+#    #+#             */
/*   Updated: 2019/02/13 17:22:37 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	choose_fractals(int keycode, t_frac *frac)
{
	FRACT_GO(keycode);
	COLOR(keycode);
	FRACT_BACK(keycode);
	STOP_COLOR(keycode);
	ALFA(keycode);
	ALFA1(keycode);
	RESET(keycode);
	threading(frac);
	return (0);
}

int	keys(int keycode, t_frac *frac)
{
	if (keycode == 18 && frac->re <= 1.06 && frac->im >= -0.52)
	{
		frac->re += 0.08;
		frac->im += -0.035;
	}
	if (keycode == 19 && frac->re > -0.62 && frac->im <= 0.215)
	{
		frac->re -= 0.08;
		frac->im -= -0.035;
	}
	PSIHO_ACTIVE(keycode);
	PSIHO_DEACTIVE(keycode);
	DOWN(keycode);
	LEFT(keycode);
	RIGHT(keycode);
	TOP(keycode);
	MENU(keycode);
	TWELVE_RIGHT(keycode);
	TWELVE_LEFT(keycode);
	STOP_MOUSE(keycode);
	ESC(keycode);
	ITER(keycode);
	ITER_MIN(keycode);
	threading(frac);
	return (0);
}
