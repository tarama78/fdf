/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:37:25 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/08 20:12:29 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_print_result.c                                        |
**   |     ft_print_result(1 lines)                             |
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

static void	ft_print_para(t_a *a)
{
	t_coord	c;
	t_map	*map;
	t_map	*last_map;
	int		x;
	int		y;
	int		color;

	ft_reset_win(a);
	last_map = a->map;
	map = a->map;
	color = 0x00FF00;
	y = -1;
	while (++y < a->map_h)
	{
		x = -1;
		while (++x < map->w)
		{
			if (x > 0)
			{
				c = ft_set_coord(
						(a->start_x + x * a->zoom) + PARA_CTE * -map->m[x],
						(a->start_y + y * a->zoom) + PARA_CTE * -map->m[x],
						(a->start_x + (x - 1) * a->zoom) + PARA_CTE * -map->m[x - 1],
						(a->start_y + y * a->zoom) + PARA_CTE * -map->m[x - 1]);
				ft_put_line(a, c, color);
			}
			if (y > 0)
			{
				c = ft_set_coord(
						(a->start_x + x * a->zoom) + PARA_CTE * -map->m[x],
						(a->start_y + y * a->zoom) + PARA_CTE * -map->m[x],
						(a->start_x + x * a->zoom) + PARA_CTE * -last_map->m[x],
						(a->start_y + (y - 1) * a->zoom) + PARA_CTE * -last_map->m[x]);
				ft_put_line(a, c, color);
			}
		}
		last_map = map;
		map = map->next;
	}
}

/*
**	x = CTE1 * x - CTE2 * y
**	y = z + CTE1 / 2 * x + CTE2 / 2 * y
*/

static void	ft_print_isom(t_a *a)
{
	t_coord	c;
	t_map	*map;
	t_map	*last_map;
	int		x;
	int		y;
	int		color;

	ft_reset_win(a);
	last_map = a->map;
	map = a->map;
	color = 0xFFFF00;
	y = -1;
	while (++y < a->map_h)
	{
		x = -1;
		while (++x < map->w)
		{
			if (x > 0)
			{
				c = ft_set_coord(
						(a->start_x + x * a->zoom) * ISOM_CTE1 - (a->start_y + y * a->zoom) * ISOM_CTE2,
						-map->m[x] + ISOM_CTE1 / 2 * (a->start_x + x * a->zoom) + ISOM_CTE2 / 2 * (a->start_y + y * a->zoom),
						(a->start_x + (x - 1) * a->zoom) * ISOM_CTE1 - (a->start_y + y * a->zoom) * ISOM_CTE2,
						-map->m[x - 1] + ISOM_CTE1 / 2 * (a->start_x + (x - 1) * a->zoom) + ISOM_CTE2 / 2 * (a->start_y + y * a->zoom));
				ft_put_line(a, c, color);
			}
			if (y > 0)
			{
				c = ft_set_coord(
						(a->start_x + x * a->zoom) * ISOM_CTE1 - (a->start_y + y * a->zoom) * ISOM_CTE2,
						-map->m[x] + ISOM_CTE1 / 2 * (a->start_x + x * a->zoom) + ISOM_CTE2 / 2 * (a->start_y + y * a->zoom),
						(a->start_x + x * a->zoom) * ISOM_CTE1 - (a->start_y + (y - 1) * a->zoom) * ISOM_CTE2,
						-last_map->m[x] + ISOM_CTE1 / 2 * (a->start_x + x * a->zoom) + ISOM_CTE2 / 2 * (a->start_y + (y - 1) * a->zoom));
				ft_put_line(a, c, color);
			}
		}
		last_map = map;
		map = map->next;
	}
}

static void	ft_print_coni(t_a *a)
{
	ft_printf("{yellow}%s: %s(){eoc} a cree\n", __FILE__, __func__);
}

void		ft_print_result(t_a *a)
{
	if (a->proj == PARA)
		ft_print_para(a);
	else if (a->proj == ISOM)
		ft_print_isom(a);
	else if (a->proj == CONI)
		ft_print_coni(a);
	ft_print_win(a);
}
