/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:56:01 by tbahlai           #+#    #+#             */
/*   Updated: 2019/02/13 17:29:12 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	init_frac(t_frac *frac)
{
	if (frac->ind != 0)
		init_val_mandelbrot(frac);
	threading(frac);
}

void	helper(void)
{
	ft_putendl("1 Mandelbrot");
	ft_putendl("2 Julia");
	ft_putendl("3 Circle");
	ft_putendl("4 Chameleon");
	ft_putendl("5 Lilies");
	ft_putendl("6 Сhinese eyes");
	ft_putendl("7 DuoMandelbrot");
	ft_putendl("8 TrioMandelbrot");
	ft_putendl("9 Bird");
	ft_putendl("10 Leaves");
	ft_putendl("11 QudroMandelbrot");
	ft_putendl("12 Alien");
	ft_putendl("13 Thorn");
	ft_putendl("14 Shell");
	ft_putendl("15 Randomness");
}

int		is_fractol(char **av, t_frac *frac)
{
	if (!(ft_atoi(av[1]) > 0 && ft_atoi(av[1]) < 16))
	{
		helper();
		return (0);
	}
	frac->ind = ft_atoi(av[1]);
	return (1);
}

int		destroy(void)
{
	exit(0);
}

int		main(int ac, char **av)
{
	t_frac *frac;

	if (ac != 2)
		helper();
	if (ac == 2)
	{
		CHECKMEMO((frac = (t_frac*)malloc(sizeof(t_frac))));
		frac->mlx.init = mlx_init();
		frac->mlx.win = mlx_new_window(frac->mlx.init, WID, HEIG, "Fractol");
		frac->mlx.img = mlx_new_image(frac->mlx.init, WID, HEIG);
		frac->mlx.img_ptr = (int*)mlx_get_data_addr(frac->mlx.img, \
			&frac->mlx.bpp, &frac->mlx.sl, &frac->mlx.endian);
		if (is_fractol(av, frac) == 0)
			return (0);
		init_frac(frac);
		mlx_hook(frac->mlx.win, 2, 0, keys, frac);
		mlx_hook(frac->mlx.win, 3, 0, choose_fractals, frac);
		mlx_hook(frac->mlx.win, 6, 1L < 6, julia_mouse, frac);
		mlx_hook(frac->mlx.win, 4, 0, my_mouse, frac);
		mlx_hook(frac->mlx.win, 17, 0, destroy, NULL);
		mlx_loop_hook(frac->mlx.init, psixodel, frac);
		mlx_loop(frac->mlx.init);
	}
}
