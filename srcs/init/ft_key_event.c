/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 19:36:50 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/08 19:32:55 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_key_event.c                                           |
**   |     ft_key_event(35 lines)                               |
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

int			ft_key_event(int keycode, t_a *a)
{
	(void)a;
	ft_printf("{green}(key %d){eoc}\n", keycode);
	if (keycode == 69)
	{
		a->zoom += ZOOM_SPEED;
		ft_print_result(a);
	}
	else if (keycode == 78)
	{
		a->zoom -= ZOOM_SPEED;
		ft_print_result(a);
	}
	else if (keycode == 123)
	{
		a->start_x -= MOVE_SPEED;
		ft_print_result(a);
	}
	else if (keycode == 124)
	{
		a->start_x += MOVE_SPEED;
		ft_print_result(a);
	}
	else if (keycode == 125)
	{
		a->start_y += MOVE_SPEED;
		ft_print_result(a);
	}
	else if (keycode == 126)
	{
		a->start_y -= MOVE_SPEED;
		ft_print_result(a);
	}
	else if (keycode == 82)
	{
		a->start_x = START_X;
		a->start_y = START_Y;
		a->zoom = ZOOM;
		a->proj = PARA;
		ft_print_result(a);
	}
	else if (keycode == 49)
	{
		if (a->proj == PARA)
			a->proj = ISOM;
		else if (a->proj == ISOM)
			a->proj = CONI;
		else
			a->proj = PARA;
		ft_print_result(a);
	}
	else if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
