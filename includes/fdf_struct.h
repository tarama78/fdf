/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 19:38:12 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/08 17:36:24 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

# define WIDTH 800
# define HEIGHT 800
# define SUCCESS 0
# define ERROR 1
# define PI 3.14159265358979323846
# define CTE 0.75

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

typedef struct		s_a
{
	void			*mlx;
	void			*win;
	t_img			img;
	int				width;
	int				height;
	t_map			*map;
	int				map_h;
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
	unsigned int	r : 8;
	unsigned int	g : 8;
	unsigned int	b : 8;
	unsigned int	a : 8;
}					t_rgb;

typedef unsigned int t_ui;
typedef long long t_ll;
typedef unsigned long long t_ull;

#endif
