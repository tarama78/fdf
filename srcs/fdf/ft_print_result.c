/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:37:25 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/09 00:15:55 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_print_result.c                                        |
**   |     ft_print_para_2(22 lines)                            |
**   |     ft_print_isom_2(28 lines)                            |
**   |         MEUUUU too many lines                            |
**   |     ft_print_result(24 lines)                            |
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

static void	ft_print_para_2(t_a *a, t_map *map, t_map *last_map, long long xy)
{
	t_coord		c;
	int			x;
	int			y;

	x = ft_get2arg(xy, 0);
	y = ft_get2arg(xy, 1);
	if (x > 0)
	{
		c = ft_set_coord( (a->start_x + x * a->zoom) + a->para_cte * -map->m[x],
		(a->start_y + y * a->zoom) + a->para_cte * -map->m[x], (a->start_x + (x
		- 1) * a->zoom) + a->para_cte * -map->m[x - 1], (a->start_y + y *
		a->zoom) + a->para_cte * -map->m[x - 1]);
		ft_put_line(a, c, a->color.c);
	}
	if (y > 0)
	{
		c = ft_set_coord( (a->start_x + x * a->zoom) + a->para_cte * -map->m[x],
		(a->start_y + y * a->zoom) + a->para_cte * -map->m[x], (a->start_x + x *
		a->zoom) + a->para_cte * -last_map->m[x], (a->start_y + (y - 1) *
		a->zoom) + a->para_cte * -last_map->m[x]);
		ft_put_line(a, c, a->color.c);
	}
}

/*
**	x = CTE1 * x - CTE2 * y
**	y = z + CTE1 / 2 * x + CTE2 / 2 * y
*/

static void	ft_print_isom_2(t_a *a, t_map *map, t_map *last_map, long long xy)
{
	t_coord		c;
	int			x;
	int			y;

	x = ft_get2arg(xy, 0);
	y = ft_get2arg(xy, 1);
	if (x > 0)
	{
		c = ft_set_coord( (a->start_x + x * a->zoom) * a->isom_cte1 -
		(a->start_y + y * a->zoom) * a->isom_cte2, -map->m[x] + a->isom_cte1 / 2
		* (a->start_x + x * a->zoom) + a->isom_cte2 / 2 * (a->start_y + y *
		a->zoom), (a->start_x + (x - 1) * a->zoom) * a->isom_cte1 -
		(a->start_y + y * a->zoom) * a->isom_cte2, -map->m[x - 1] +
		a->isom_cte1 / 2 * (a->start_x + (x - 1) * a->zoom) + a->isom_cte2 / 2
		* (a->start_y + y * a->zoom));
		ft_put_line(a, c, a->color.c);
	}
	if (y > 0)
	{
		c = ft_set_coord( (a->start_x + x * a->zoom) * a->isom_cte1 -
		(a->start_y + y * a->zoom) * a->isom_cte2, -map->m[x] + a->isom_cte1 / 2
		* (a->start_x + x * a->zoom) + a->isom_cte2 / 2 * (a->start_y + y *
		a->zoom), (a->start_x + x * a->zoom) * a->isom_cte1 - (a->start_y + (y
		- 1) * a->zoom) * a->isom_cte2, -last_map->m[x] + a->isom_cte1 / 2 *
		(a->start_x + x * a->zoom) + a->isom_cte2 / 2 * (a->start_y + (y - 1)
		* a->zoom));
		ft_put_line(a, c, a->color.c);
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
				ft_print_para_2(a, map, last_map, ft_2arg(x, y));
			else
				ft_print_isom_2(a, map, last_map, ft_2arg(x, y));
		}
		last_map = map;
		map = map->next;
	}
	ft_print_win(a);
}
