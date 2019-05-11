/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:03:56 by yadouble          #+#    #+#             */
/*   Updated: 2018/09/30 15:46:20 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define W 13
# define S 1
# define A 0
# define D 2
# define ESC 53
# define PLUS 24
# define MINUS 27
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define MOUSE_UP 5
# define MOUSE_DOWN 4
# define RESET 15
# define ONE 18
# define TWO 19
# define THREE 20
# define FOUR 21
# define FIVE 23
# define SIX 22
# define M 46
# define X 7
# define POINT 47
# define COMA 43
#endif

typedef	struct		s_par
{
	int				x;
	int				y;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			tmp;
	int				i;
	int				color_r;
	int				color_g;
	int				color_b;
	int				max_iter;
}					t_par;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_addr;
	int				bpp;
	int				size_line;
	int				endian;
	int				x_size;
	int				y_size;
}					t_mlx;

typedef struct		s_key
{
	int				fract;
	double			move_x;
	double			move_y;
	double			zoom;
	int				color_bonus;
	double			x_pos;
	double			y_pos;
	int				act_mouse;
	int				click;
}					t_key;

typedef	struct		s_stc
{
	t_mlx			mlx;
	t_key			key;
	t_par			par;

}					t_stc;

void	ft_init_mlx(t_stc *stc, char **argv);
void	ft_init_keycode(t_stc *stc);
int		ft_rgb_color(t_stc *stc);
void	mlx_pixel_put_to_image(t_stc *stc, int x, int y, int color);
int		ft_fractal_check(char *str, t_stc *stc);
void	ft_fractal_init(t_stc *stc);
void	ft_fractal_choice(t_stc *stc);
int		ft_keycode(int key, t_stc *stc);
int		ft_keycode2(int key, t_stc *stc);
int		ft_mousehook(int button, int x, int y, t_stc *stc);
int		ft_motion_hook(int x, int y, t_stc *stc);
void	ft_redraw(t_stc *stc);
void	ft_init_mandelbrot_param(t_stc *stc);
int		ft_mandelbrot(t_stc *stc);
void	ft_mandelbrot_calcul(t_stc *stc);
void	ft_init_julia_param(t_stc *stc);
int		ft_julia(t_stc *stc);
void	ft_julia_calcul(t_stc *stc);
void	ft_init_burning_ship(t_stc *stc);
int		ft_burning_ship(t_stc *stc);
void	ft_burning_ship_calcul(t_stc *stc);