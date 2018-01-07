/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 19:38:12 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/07 19:39:03 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

# define WIDTH 800
# define HEIGHT 800

typedef struct		s_img
{
	void			*img;
	char			*str;
	int				bpp;
	int				sz_ln;
	int				endian;
}					t_img;

typedef struct		s_a
{
	void			*mlx;
	void			*win;
	t_img			img;
	int				width;
	int				height;
}					t_a;

typedef struct 		s_rgb
{
	unsigned int	r : 8;
	unsigned int	g : 8;
	unsigned int	b : 8;
	unsigned int	a : 8;
}					t_rgb;

#endif
