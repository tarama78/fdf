/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 19:36:50 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/09 18:58:12 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_key_event.c                                           |
**   |     ft_key_event_move(20 lines)                          |
**   |     ft_key_event_zoom(10 lines)                          |
**   |     ft_key_event(22 lines)                               |
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
		ft_print_result(a);
	}
	else if (keycode == 78 || keycode == 27)
	{
		a->zoom -= a->zoom_speed;
		ft_set_cte(a);
		ft_print_result(a);
	}
}

int			ft_key_event(int keycode, t_a *a)
{
	ft_printf("{green}(key %d){eoc}\n", keycode);
	ft_key_event_move(keycode, a);
	ft_key_event_zoom(keycode, a);
	if (keycode == 82 || keycode == 29)
	{
		a->start_x = a->def.start_x;
		a->start_y = a->def.start_y;
		a->zoom = a->def.zoom;
		a->proj = PARA;
		ft_print_result(a);
	}
	else if (keycode == 49)
	{
		if (a->proj == PARA)
			a->proj = ISOM;
		else
			a->proj = PARA;
		ft_print_result(a);
	}
	else if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
