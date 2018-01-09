/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 18:30:01 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/09 11:51:28 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_mouse_event.c                                         |
**   |     ft_mouse_event(3 lines)                              |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <fdf.h>

int			ft_mouse_event(int keycode, t_a *a)
{
	(void)a;
	ft_printf("{green}(mouse %d){eoc}\n", keycode);
//	if (keycode == 4)
//	{
//		a->zoom += a->zoom_speed;
//		ft_print_result(a);
//	}
//	else if (keycode == 5)
//	{
//		a->zoom -= a->zoom_speed;
//		ft_print_result(a);
//	}
	return (0);
}
