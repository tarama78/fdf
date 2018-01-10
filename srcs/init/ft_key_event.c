/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 19:36:50 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/10 17:46:38 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_key_event.c                                           |
**   |     ft_key_event_move(20 lines)                          |
**   |     ft_key_event_zoom(14 lines)                          |
**   |     ft_key_event(29 lines)                               |
**   |         MEUUUU too many lines                            |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <fdf.h>

static void	ft_key_event_move(int keycode, t_a *a)
{
	if (keycode == 123)
	{
		a->start_x -= a->move_speed;
		ft_print_result(a);
	}
	else if (keycode == 124)
	{
		a->start_x += a->move_speed;
		ft_print_result(a);
	}
	else if (keycode == 125)
	{
		a->start_y += a->move_speed;
		ft_print_result(a);
	}
	else if (keycode == 126)
	{
		a->start_y -= a->move_speed;
		ft_print_result(a);
	}
}

static void	ft_key_event_zoom(int keycode, t_a *a)
{
	if (keycode == 69 || keycode == 24)
	{
		a->zoom += a->zoom_speed;
		ft_set_cte(a);
		ft_printf("zoom %f\n", a->zoom);
		ft_print_result(a);
	}
	else if (keycode == 0)
	{
		a->add_cte += CTE_SPEED;
		ft_set_cte(a);
		ft_print_result(a);
	}
	else if (keycode == 7)
	{
		a->add_cte -= CTE_SPEED;
		ft_set_cte(a);
		ft_print_result(a);
	}
	else if (keycode == 78 || keycode == 27)
	{
		a->zoom -= a->zoom_speed;
		ft_set_cte(a);
		ft_printf("zoom %f\n", a->zoom);
		ft_print_result(a);
	}
}

int			ft_key_event(int keycode, t_a *a)
{
	ft_printf("{green}(key %d){eoc}\n", keycode);
	ft_printf("isom cte %3f\tpara cte %f\n", a->isom_cte1, a->para_cte);
	ft_key_event_move(keycode, a);
	ft_key_event_zoom(keycode, a);
	if (keycode == 82 || keycode == 29)
	{
		a->start_x = a->def.start_x;
		a->start_y = a->def.start_y;
		a->zoom = a->def.zoom;
		a->add_cte = 1;
		a->proj = PARA;
		ft_print_result(a);
	}
	else if (keycode == 49)
	{
		a->start_x = a->def.start_x;
		a->start_y = a->def.start_y;
		if (a->proj == PARA)
		{
			a->zoom = ft_max(a->height / a->map_h, a->width / a->map->w) / ((a->isom_cte1 + a->isom_cte2)) * 4.5;
			a->add_cte = 1;
			ft_printf("{yellow}zoom isom %f{eoc}\n", a->zoom);
			a->proj = ISOM;
			ft_set_cte(a);
		}
		else
		{
			a->zoom = (ft_min(a->height / a->map_h, a->width / a->map->w)) * 1.5;
			a->add_cte = 1;
			ft_printf("{yellow}zoom para %f{eoc}\n", a->zoom);
			a->proj = PARA;
			ft_set_cte(a);
		}
		ft_print_result(a);
	}
	else if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
