/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 10:16:26 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/09 11:32:58 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_put_line.c                                            |
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

static t_ui	ft_get_color(t_a *a, int z)
{
	t_rgb	c_start;
	t_rgb	c_end;
	t_rgb	c;

	c_start = *(t_rgb*)&a->color.start;
	c_end = *(t_rgb*)&a->color.end;
	c = *(t_rgb*)&a->color.start;
//	ft_printf("(z %d) (max_z %d)\n", z, a->max_z);
	if (z == 0)
		return (a->color.start);
	c.r = (c_end.r - c_start.r) / ((double)a->max_z / z);
	c.g = (c_end.g - c_start.g) / ((double)a->max_z / z);
	c.b = (c_end.b - c_start.b) / ((double)a->max_z / z);
	return (*(t_ui*)&c);
}

void		ft_put_line_color(t_a *a, t_coord c, int z_start, int z_end)
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
					ft_get_color(a, ((a->max_z == 0) ? 0 : (int)-(((double)x - c.x1) / ((double)c.x2 - c.x1 + 1) * ((double)z_end - z_start)))));
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
					ft_get_color(a, ((a->max_z == 0) ? 0 : (int)-(((double)x - c.x1) / ((double)c.x2 - c.x1 + 1) * ((double)z_end - z_start)))));
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
