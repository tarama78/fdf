/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:16:26 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/10 19:16:04 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_put_line.c                                            |
**   |     ft_get_color(2 lines)                                |
**   |     ft_put_line_color(27 lines)                          |
**   |         MEUUUU too many lines                            |
**   |     ft_put_line(25 lines)                                |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <fdf.h>

static int	ft_get_color(t_a *a, t_coord c, int x)
{
	t_rgb	color;
	t_rgb	color_s;
	t_rgb	color_e;

	color_s = *(t_rgb*)&c.c1;
	color_e = *(t_rgb*)&c.c2;
	c.x2 = (c.x2 == 0) ? 1 : c.x2;
	color_s.r = (color_s.r == 0) ? 1 : color_s.r;
	color_s.g = (color_s.g == 0) ? 1 : color_s.g;
	color_s.b = (color_s.b == 0) ? 1 : color_s.b;
	color.r = floor((color_e.r / (double)color_s.r) * (x / (double)c.x2));
//	color.g = (color_s.g / color_e.g) * (x / (c.x2 - c.x1));
//	color.b = (color_s.b / color_e.b) * (x / (c.x2 - c.x1));
	color.g = 255;
	color.b = 255;
	if (color_s.r > 1 || color_e.r > 1)
	ft_printf("%#08x (r %3d) (g %3d) (b %3d)\n", *(int*)&color, color.r, color.g, color.b);
	return (*(int*)&color);
}

void		ft_put_line_color(t_a *a, t_coord c)
{
	int		x;

//	ft_printf("(x1 %3d) (y1 %3d)\n", c.x1, c.y1);
//	ft_printf("(x2 %3d) (y2 %3d)\n\n", c.x2, c.y2);
	if (abs(c.x2 - c.x1) >= abs(c.y2 - c.y1))
	{
		if (c.x2 - c.x1 < 0)
		{
			ft_swap_int(&c.x1, &c.x2);
			ft_swap_int(&c.y1, &c.y2);
		}
		x = c.x1 - 1;
		while (++x < c.x2)
			ft_put_px(a, x, c.y1 + ((c.y2 - c.y1) * (x - c.x1) / (c.x2 - c.x1)),
					ft_get_color(a, c, x));
		return ;
	}
	if (c.y2 - c.y1 < 0)
		ft_swap_int(&c.x1, &c.x2);
	if (c.y2 - c.y1 < 0)
		ft_swap_int(&c.y1, &c.y2);
	ft_swap_int(&c.x1, &c.y1);
	ft_swap_int(&c.x2, &c.y2);
	x = c.x1 - 1;
	while (++x < c.x2)
		ft_put_px(a, c.y1 + ((c.y2 - c.y1) * (x - c.x1) / (c.x2 - c.x1)), x,
					ft_get_color(a, c, x));
}

void		ft_put_line(t_a *a, t_coord c, t_ui color)
{
	int		x;

	if (abs(c.x2 - c.x1) >= abs(c.y2 - c.y1))
	{
		if (c.x2 - c.x1 < 0)
		{
			ft_swap_int(&c.x1, &c.x2);
			ft_swap_int(&c.y1, &c.y2);
		}
		x = c.x1 - 1;
		while (++x < c.x2)
			ft_put_px(a, x, c.y1 + ((c.y2 - c.y1) * (x - c.x1) / (c.x2 - c.x1)),
					color);
		return ;
	}
	if (c.y2 - c.y1 < 0)
		ft_swap_int(&c.x1, &c.x2);
	if (c.y2 - c.y1 < 0)
		ft_swap_int(&c.y1, &c.y2);
	ft_swap_int(&c.x1, &c.y1);
	ft_swap_int(&c.x2, &c.y2);
	x = c.x1 - 1;
	while (++x < c.x2)
		ft_put_px(a, c.y1 + ((c.y2 - c.y1) * (x - c.x1) / (c.x2 - c.x1)), x,
				color);
}

/*
**void		ft_put_line(t_a *a, t_ll xy1, t_ll xy2, t_ui color)
**{
**	double	angle;
**	double	sz;
**	double	x;
**	double	y;
**
**	angle = atan(((double)ft_get2arg(xy2, 0) - ft_get2arg(xy1, 0)) /
**			((double)ft_get2arg(xy2, 1) - ft_get2arg(xy1, 1))) * 180 / PI;
**	sz = sqrt(pow((double)ft_get2arg(xy2, 0) - ft_get2arg(xy1, 0), 2) +
**			pow((double)ft_get2arg(xy2, 1) - ft_get2arg(xy1, 1), 2));
**	ft_printf("(angle %f) (size %f)\n", angle, sz);
**	x = (double)ft_get2arg(xy1, 0);
**	y = (double)ft_get2arg(xy1, 1);
**	while (ft_abs(x - ft_get2arg(xy1, 0)) < ft_abs(ft_get2arg(xy2, 0) -
**				ft_get2arg(xy1, 0)) || ft_abs(x - ft_get2arg(xy1, 0)) <
**				ft_abs(ft_get2arg(xy2, 0) - ft_get2arg(xy1, 0)))
**	{
**		ft_printf("\t(x %f) (y %f) (x2 %d) (y2 %d)\n", x, y, ft_get2arg(xy2, 0),
**			ft_get2arg(xy2, 1));
**		ft_put_px(a, floor(x), floor(y), color);
**		x += ((double)ft_get2arg(xy2, 0) - ft_get2arg(xy1, 0)) / sz;
**		y += ((double)ft_get2arg(xy2, 1) - ft_get2arg(xy1, 1)) / sz;
**	}
**}
*/
