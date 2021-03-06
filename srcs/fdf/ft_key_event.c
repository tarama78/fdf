/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 19:36:50 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/15 11:06:49 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_key_event.c                                           |
**   |     ft_key_event_move(20 lines)                          |
**   |     ft_key_event_zoom(20 lines)                          |
**   |     ft_key_event_proj(20 lines)                          |
**   |     ft_key_event(14 lines)                               |
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
		ft_print_result(((ft_set_cte(a)) ? a : a));
	}
	else if (keycode == 0)
	{
		a->add_cte += CTE_SPEED;
		ft_print_result(((ft_set_cte(a)) ? a : a));
	}
	else if (keycode == 7)
	{
		a->add_cte -= CTE_SPEED;
		ft_print_result(((ft_set_cte(a)) ? a : a));
	}
	else if (keycode == 78 || keycode == 27)
	{
		a->zoom -= a->zoom_speed;
		ft_print_result(((ft_set_cte(a)) ? a : a));
	}
}

static void	ft_key_event_proj(int keycode, t_a *a)
{
	if (keycode == 49)
	{
		a->start_x = a->def.start_x;
		a->start_y = a->def.start_y;
		if (a->proj == PARA)
		{
			a->zoom = ft_max(a->height / a->map_h, a->width / a->map->w) /
				((a->isom_cte1 + a->isom_cte2)) * MULT_ZOOM_ISOM;
			a->add_cte = 1 * (double)a->mult_cte / MULT_CTE;
			a->proj = ISOM;
		}
		else
		{
			a->zoom = (ft_min(a->height / a->map_h, a->width / a->map->w)) *
				MULT_ZOOM_PARA;
			a->add_cte = 1;
			a->proj = PARA;
		}
		ft_print_result(((ft_set_cte(a)) ? a : a));
	}
}

int			ft_key_event(int keycode, t_a *a)
{
	ft_key_event_move(keycode, a);
	ft_key_event_zoom(keycode, a);
	ft_key_event_proj(keycode, a);
	if (keycode == 82 || keycode == 29)
	{
		a->proj = (a->proj == PARA) ? ISOM : PARA;
		ft_key_event(49, a);
	}
	else if (keycode == 53)
	{
		ft_close(a);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
