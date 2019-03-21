/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:03:38 by tbahlai           #+#    #+#             */
/*   Updated: 2019/02/13 17:34:13 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	threading(t_frac *frac)
{
	pthread_t	thr[THREADS];
	t_frac		mass[THREADS];

	frac->thread_id = 0;
	while (frac->thread_id < THREADS)
	{
		ft_memcpy((void *)&mass[frac->thread_id], (void *)frac, \
			sizeof(t_frac));
		mass[frac->thread_id].y = frac->thread_id * THR_WIDTH;
		pthread_create(&thr[frac->thread_id], NULL, draw_fractol,\
			&mass[frac->thread_id]);
		frac->thread_id++;
	}
	frac->thread_id = 0;
	while (frac->thread_id < THREADS)
	{
		pthread_join(thr[frac->thread_id], NULL);
		frac->thread_id++;
	}
	mlx_put_image_to_window(frac->mlx.init, frac->mlx.win, \
		frac->mlx.img, 0, 0);
}
