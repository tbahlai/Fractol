/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:14:06 by tbahlai           #+#    #+#             */
/*   Updated: 2019/02/13 17:21:55 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	init_val_mandelbrot(t_frac *frac)
{
	frac->x1 = -1.7;
	frac->y1 = -1.3;
	frac->y2 = 0;
	frac->x2 = 0;
	frac->zoom = 300;
	frac->max_iter = 100;
	frac->color = 004001006;
	frac->per_re = 0.285;
	frac->per_im = 0.01;
	frac->mouse_re = -0.5f;
	frac->re = 0.1;
	frac->im = -0.1;
	frac->per_div = 1;
	frac->ind_mouse = 1;
	frac->psiho = 0;
	frac->norm_color = 0;
}
