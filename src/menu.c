/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:21:00 by tbahlai           #+#    #+#             */
/*   Updated: 2019/02/13 17:30:23 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	menu(t_frac *frac)
{
	mlx_clear_window(frac->help.init, frac->help.win);
	mlx_string_put(frac->help.init, frac->help.win, 0, 20, 5822086,
		"    Switch between fractals:   arrows up, down");
	mlx_string_put(frac->help.init, frac->help.win, 0, 40, 16044883,
		"    Zoom: mouse scroll");
	mlx_string_put(frac->help.init, frac->help.win, 0, 60, 5822086,
		"    Move: mouse button left, right, or arrows");
	mlx_string_put(frac->help.init, frac->help.win, 0, 80, 16044883,
		"    Choose norm color: K stop: Ctrl");
	mlx_string_put(frac->help.init, frac->help.win, 0, 100, 5822086,
		"    For (12): C/V");
	mlx_string_put(frac->help.init, frac->help.win, 0, 120, 16044883,
		"    For (13): 1/2 (mandatory button)");
	mlx_string_put(frac->help.init, frac->help.win, 0, 140, 5822086,
		"    WAY effect: A");
	mlx_string_put(frac->help.init, frac->help.win, 0, 160, 16044883,
		"    Psihodelic: P stop: Ctrl");
	mlx_string_put(frac->help.init, frac->help.win, 0, 180, 5822086,
		"    Reset: Enter");
	mlx_string_put(frac->help.init, frac->help.win, 0, 200, 16044883,
		"    Exit: ESC or (X) in the corner of the window");
	mlx_string_put(frac->help.init, frac->help.win, 0, 220, 5822086,
		"    Iterations: +/-");
	mlx_string_put(frac->help.init, frac->help.win, 0, 240, 16044883,
		"    Stop mouse for Julia: S");
}

void	wind_for_menu(t_frac *frac)
{
	frac->help.init = mlx_init();
	frac->help.win = mlx_new_window(frac->help.init, 600, 300, "Helper");
	menu(frac);
	mlx_loop(frac->help.init);
}
