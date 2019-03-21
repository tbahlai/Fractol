/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahlai <tbahlai@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:55:18 by tbahlai           #+#    #+#             */
/*   Updated: 2019/02/13 17:40:45 by tbahlai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "lib/libft.h"
# include <math.h>
# include <pthread.h>
# define CHECKMEMO(x) if (!(x)) return (-1);
# define WID 1000
# define HEIG 800
# define FOR_ZOOM 0.9f
# define REWRITE(a, b, c, d) a = b; c = d;
# define TO_ZERO(a, b) a = 0; b = 0;
# define THREADS 8
# define THR_WIDTH 150
# define STOP_MOUSE(l) if (l == 1) frac->ind_mouse = 0;
# define ESC(l) if (l == 53) exit(0);
# define TWELVE_LEFT(l) if (l == 9) frac->per_div += 0.5;
# define TWELVE_RIGHT(l) if (l == 8 && frac->per_div > 1) frac->per_div -= 0.5;
# define TOP(l) if (l == 125) frac->y1 += 20 / frac->zoom;
# define DOWN(l) if (l == 126) frac->y1 -= 20 / frac->zoom;
# define LEFT(l) if (l == 123) frac->x1 += 20 / frac->zoom;
# define RIGHT(l) if (l == 124) frac->x1 -= 20 / frac->zoom;
# define ITER(l) if (l == 69) frac->max_iter += 50;
# define ITER_MIN(l) if (l == 78 && frac->max_iter > 50) frac->max_iter -= 50;
# define MENU(l) if (l == 46) wind_for_menu(frac);
# define FRACT_BACK(l) if (l == 121 && frac->ind < 15) frac->ind += 1;
# define FRACT_GO(l) if (l == 116 && (frac->ind - 1) >= 1) frac->ind -= 1;
# define PSIHO_ACTIVE(l) if (l == 35) {frac->psiho = 1;}
# define PSIHO_DEACTIVE(l) if (l == 256) frac->psiho = 0;
# define COLOR(l) if (l == 40) {frac->norm_color = 1;}
# define STOP_COLOR(l) if (l == 256) frac->norm_color = 0;
# define ALFA(l) if (l == 0) frac->color = 318568064;
# define ALFA1(l) if (l == 12) frac->color = 268568064;
# define RESET(l) if (l == 36) {init_val_mandelbrot(frac);}

typedef struct	s_help
{
	void		*win;
	void		*init;
}				t_help;

typedef struct	s_mlx
{
	void		*win;
	void		*init;
	void		*img;
	int			*img_ptr;
	int			bpp;
	int			sl;
	int			endian;
}				t_mlx;

typedef struct	s_frac
{
	int			color;
	int			psiho;
	int			norm_color;
	int			x;
	int			y;
	int			close;
	int			max_iter;
	int			thread_id;
	int			ind_mouse;
	int			ind;
	double		per_div;
	double		re;
	double		im;
	double		per_re;
	double		per_im;
	double		mouse_re;
	double		mouse_im;
	double		x1;
	double		y1;
	double		x2;
	double		y2;
	double		zoom;
	double		new_re;
	double		new_im;
	double		old_re;
	double		old_im;
	double		pr;
	double		pi;
	t_mlx		mlx;
	t_help		help;
}				t_frac;

int				color(t_frac *frac);
int				choose_fractals(int keycode, t_frac *frac);
void			wind_for_menu(t_frac *frac);
void			threading(t_frac *frac);
int				which_fractol_draw2(t_frac *frac);
int				which_fractol_draw3(t_frac *frac);
void			*draw_fractol(void *data);
int				which_fractol_draw1(t_frac *frac);
int				main(int ac, char **av);
int				which_fractol_draw4(t_frac *frac);
int				which_fractol_draw(t_frac *frac);
void			init_val_mandelbrot(t_frac *frac);
int				psixodel(t_frac *frac);
int				my_mouse(int button, int x, int y, t_frac *frac);
int				julia_mouse(int x, int y, t_frac *frac);
int				keys(int keycode, t_frac *frac);
void			pixel(t_frac *frac, int x, int y, int color);
void			calc_fractol(t_frac *frac);

#endif
