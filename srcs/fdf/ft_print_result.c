/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:37:25 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 16:14:41 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_print_result.c                                        |
**   |     ft_print_para_2(18 lines)                            |
**   |     ft_print_para(18 lines)                              |
**   |     ft_print_isom_2(22 lines)                            |
**   |     ft_print_isom(22 lines)                              |
**   |     ft_print_result(23 lines)                            |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <fdf.h>

/*
**	x = x + cte * z
**	y = y + cte / 2 * z
*/

static void	ft_print_para_2(t_a *a, t_map *map, int x, int y)
{
	t_coord	c;

	if (x > 0)
	{
		c = ft_set_coord(x * a->zoom + a->para_cte * -map->m[x], y * a->zoom +
		a->para_cte * -map->m[x], (x - 1) * a->zoom + a->para_cte *
		-map->m[x - 1], y * a->zoom + a->para_cte * -map->m[x - 1]);
		if (x == 1 && y == 0)
		{
			a->add_x = MAX_Z * 2;
			a->add_y = a->add_x;
		}
		(c.x1 += a->add_x + a->start_x) && (c.y1 += a->add_y + a->start_y);
		(c.x2 += a->add_x + a->start_x) && (c.y2 += a->add_y + a->start_y);
		c.c1 = map->color[x - 1];
		c.c2 = map->color[x];
		ft_put_line_color(a, c);
	}
}

static void	ft_print_para(t_a *a, t_map *map, t_map *last_map, long long xy)
{
	t_coord		c;
	int			x;
	int			y;

	x = ft_get2arg(xy, 0);
	y = ft_get2arg(xy, 1);
	ft_print_para_2(a, map, x, y);
	if (y > 0)
	{
		c = ft_set_coord(x * a->zoom + a->para_cte * -map->m[x], y * a->zoom +
		a->para_cte * -map->m[x], x * a->zoom + a->para_cte * -last_map->m[x],
		(y - 1) * a->zoom + a->para_cte * -last_map->m[x]);
		(c.x1 += a->add_x + a->start_x) && (c.y1 += a->add_y + a->start_y);
		(c.x2 += a->add_x + a->start_x) && (c.y2 += a->add_y + a->start_y);
		c.c1 = last_map->color[x];
		c.c2 = map->color[x];
		ft_put_line_color(a, c);
	}
}

/*
**	x = CTE1 * x - CTE2 * y
**	y = z + CTE1 / 2 * x + CTE2 / 2 * y
*/

static void	ft_print_isom_2(t_a *a, t_map *map, int x, int y)
{
	t_coord c;

	if (x > 0)
	{
		c = ft_set_coord((a->start_x + x * a->zoom) * a->isom_cte1 - (a->start_y
		+ y * a->zoom) * a->isom_cte2, -map->m[x] * a->add_cte * a->zoom +
		a->isom_cte1 / 2 * (a->start_x + x * a->zoom) + a->isom_cte2 / 2 *
		(a->start_y + y * a->zoom), (a->start_x + (x - 1) * a->zoom) *
		a->isom_cte1 - (a->start_y + y * a->zoom) * a->isom_cte2, -map->m[x - 1]
		* a->add_cte * a->zoom + a->isom_cte1 / 2 * (a->start_x + (x - 1) *
		a->zoom) + a->isom_cte2 / 2 * (a->start_y + y * a->zoom));
		if (x == 1 && y == 0)
		{
			a->add_x = -(c.x1 - (a->width / 2) - a->start_x);
			a->add_y = -(c.y1 - 200 - a->start_y);
		}
		(c.x1 += a->add_x) && (c.y1 += a->add_y);
		(c.x2 += a->add_x) && (c.y2 += a->add_y);
		c.c1 = map->color[x - 1];
		c.c2 = map->color[x];
		ft_put_line_color(a, c);
	}
}

static void	ft_print_isom(t_a *a, t_map *map, t_map *last_map, long long xy)
{
	t_coord		c;
	int			x;
	int			y;

	x = ft_get2arg(xy, 0);
	y = ft_get2arg(xy, 1);
	ft_print_isom_2(a, map, x, y);
	if (y > 0)
	{
		c = ft_set_coord((a->start_x + x * a->zoom) * a->isom_cte1 - (a->start_y
		+ y * a->zoom) * a->isom_cte2, -map->m[x] * a->add_cte * a->zoom +
		a->isom_cte1 / 2 * (a->start_x + x * a->zoom) + a->isom_cte2 / 2 *
		(a->start_y + y * a->zoom), (a->start_x + x * a->zoom) * a->isom_cte1 -
		(a->start_y + (y - 1) * a->zoom) * a->isom_cte2, -last_map->m[x] *
		a->add_cte * a->zoom + a->isom_cte1 / 2 * (a->start_x + x * a->zoom) +
		a->isom_cte2 / 2 * (a->start_y + (y - 1) * a->zoom));
		(c.x1 += a->add_x) && (c.y1 += a->add_y);
		(c.x2 += a->add_x) && (c.y2 += a->add_y);
		c.c1 = last_map->color[x];
		c.c2 = map->color[x];
		ft_put_line_color(a, c);
	}
}

void		ft_print_result(t_a *a)
{
	t_map	*map;
	t_map	*last_map;
	int		x;
	int		y;

	ft_reset_win(a);
	last_map = a->map;
	map = a->map;
	y = -1;
	while (++y < a->map_h)
	{
		x = -1;
		while (++x < map->w)
		{
			if (a->proj == PARA)
				ft_print_para(a, map, last_map, ft_2arg(x, y));
			else
				ft_print_isom(a, map, last_map, ft_2arg(x, y));
		}
		last_map = map;
		map = map->next;
	}
	ft_print_win(a);
}
