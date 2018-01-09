/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 19:38:12 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/09 11:55:21 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

# define WIDTH 1200
# define HEIGHT 800
# define ZOOM 30
# define ZOOM_SPEED (double)ZOOM / 10
# define MOVE_SPEED 10
# define START_X 400
# define START_Y 70
# define PARA_CTE 500
# define ISOM_CTE1 1
# define ISOM_CTE2 1
# define SUCCESS 0
# define ERROR 1
# define PI 3.14159265358979323846

typedef struct		s_img
{
	void			*img;
	char			*str;
	int				bpp;
	int				sz_ln;
	int				endian;
}					t_img;

typedef struct		s_map
{
	int				*m;
	int				w;
	struct s_map	*next;
}					t_map;

typedef enum		e_proj
{
	PARA, ISOM
}					t_proj;

typedef struct		s_def
{
	int				zoom;
	int				start_x;
	int				start_y;
}					t_def;

typedef struct		s_color
{
	unsigned int	c;
	unsigned int	start;
	unsigned int	end;
}					t_color;

typedef struct		s_a
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_def			def;

	int				width;
	int				height;
	int				start_x;
	int				start_y;

	double			zoom;
	double			zoom_speed;
	int				move_speed;

	double			para_cte;
	double			isom_cte1;
	double			isom_cte2;

	t_color			color;

	t_map			*map;
	int				map_h;
	int				max_z;
	t_proj			proj;
}					t_a;

typedef struct		s_coord
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
}					t_coord;

typedef struct 		s_rgb
{
	unsigned int	b : 8;
	unsigned int	g : 8;
	unsigned int	r : 8;
	unsigned int	a : 8;
}					t_rgb;

typedef unsigned int t_ui;
typedef long long t_ll;
typedef unsigned long long t_ull;

#endif
