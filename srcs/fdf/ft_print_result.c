/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:37:25 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/10 17:48:36 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_print_result.c                                        |
**   |     ft_print_para(41 lines)                              |
**   |         MEUUUU too many lines                            |
**   |     ft_print_isom(48 lines)                              |
**   |         MEUUUU too many lines                            |
**   |     ft_print_result(25 lines)                            |
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

static void	ft_print_para(t_a *a, t_map *map, t_map *last_map, long long xy)
{
	t_coord		c;
	int			x;
	int			y;

	x = ft_get2arg(xy, 0);
	y = ft_get2arg(xy, 1);
	if (x > 0)
	{
		c = ft_set_coord(
				(a->start_x + x * a->zoom) + a->para_cte * -map->m[x],
				(a->start_y + y * a->zoom) + a->para_cte * -map->m[x],
				(a->start_x + (x - 1) * a->zoom) + a->para_cte * -map->m[x - 1],
				(a->start_y + y * a->zoom) + a->para_cte * -map->m[x - 1]);
		if (x == 1 && y == 0)
		{
			a->add_x = 10;
			a->add_y = 10;
		}
		c.x1 += a->add_x;
		c.y1 += a->add_y;
		c.x2 += a->add_x;
		c.y2 += a->add_y;
		c.c1 = map->color[x];
		c.c1 = map->color[x - 1];
		ft_put_line_color(a, c, map->m[x], map->m[x - 1]);
	}
	if (y > 0)
	{
		c = ft_set_coord(
				(a->start_x + x * a->zoom) + a->para_cte * -map->m[x],
				(a->start_y + y * a->zoom) + a->para_cte * -map->m[x],
				(a->start_x + x * a->zoom) + a->para_cte * -last_map->m[x],
				(a->start_y + (y - 1) * a->zoom) + a->para_cte * -last_map->m[x]);
		c.x1 += a->add_x;
		c.y1 += a->add_y;
		c.x2 += a->add_x;
		c.y2 += a->add_y;
		c.c1 = last_map->color[x];
		c.c1 = last_map->color[x];
		ft_put_line_color(a, c, map->m[x], last_map->m[x]);
	}
}

/*
**	x = CTE1 * x - CTE2 * y
**	y = z + CTE1 / 2 * x + CTE2 / 2 * y
*/

static void	ft_print_isom(t_a *a, t_map *map, t_map *last_map, long long xy)
{
	t_coord		c;
	int			x;
	int			y;
	double		zoom;

	zoom = a->zoom * 0.2;
//	x = map->w - ft_get2arg(xy, 0) - 1;
//	ft_printf("map->w %d, x %d\n", map->w, x);
	x = ft_get2arg(xy, 0);
	y = ft_get2arg(xy, 1);
	if (x > 0)
	{
		c = ft_set_coord(
				(a->start_x + x * zoom) * a->isom_cte1 - (a->start_y + y * zoom) * a->isom_cte2,
				-map->m[x] * a->add_cte * zoom + a->isom_cte1 / 2 * (a->start_x + x * zoom) + a->isom_cte2 / 2 * (a->start_y + y * zoom),
				(a->start_x + (x - 1) * zoom) * a->isom_cte1 - (a->start_y + y * zoom) * a->isom_cte2,
				-map->m[x - 1] * a->add_cte * zoom + a->isom_cte1 / 2 * (a->start_x + (x - 1) * zoom) + a->isom_cte2 / 2 * (a->start_y + y * zoom));
		if (x == 1 && y == 0)
		{
			a->add_x = -(c.x1 - (a->width / 2) - a->start_x);
			a->add_y = -(c.y1 - 200 - a->start_y);
		}
		c.x1 += a->add_x;
		c.y1 += a->add_y;
		c.x2 += a->add_x;
		c.y2 += a->add_y;
//		ft_printf("start (x %-5d) (y %-5d) (add_x %-5d) (add_y %-5d)\n", c.x1, c.y2, a->add_x, a->add_y);
		c.c1 = map->color[x];
		c.c1 = map->color[x - 1];
		if (x == 1 && y == 1)
			ft_printf("%5d\t%5d\n", c.x1, c.y1);
		ft_put_line_color(a, c, map->m[x], map->m[x - 1]);
	}
	if (y > 0)
	{
		c = ft_set_coord(
				(a->start_x + x * zoom) * a->isom_cte1 - (a->start_y + y * zoom) * a->isom_cte2,
				-map->m[x] * a->add_cte * zoom + a->isom_cte1 / 2 * (a->start_x + x * zoom) + a->isom_cte2 / 2 * (a->start_y + y * zoom),
				(a->start_x + x * zoom) * a->isom_cte1 - (a->start_y + (y - 1) * zoom) * a->isom_cte2,
				-last_map->m[x] * a->add_cte * zoom + a->isom_cte1 / 2 * (a->start_x + x * zoom) + a->isom_cte2 / 2 * (a->start_y + (y - 1) * zoom));
		c.x1 += a->add_x;
		c.y1 += a->add_y;
		c.x2 += a->add_x;
		c.y2 += a->add_y;
		c.c1 = last_map->color[x];
		c.c1 = last_map->color[x];
		ft_put_line_color(a, c, map->m[x], last_map->m[x]);
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
//			ft_printf("[%2d %2d %2d] ", x, y, map->m[x]);
		}
//		ft_printf("\n");
		last_map = map;
		map = map->next;
	}
	ft_print_win(a);
}
