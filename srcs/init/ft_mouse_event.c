/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 18:30:01 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/08 19:06:24 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_mouse_event.c                                         |
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
//		a->zoom += ZOOM_SPEED;
//		ft_print_result(a);
//	}
//	if (keycode == 5)
//	{
//		a->zoom -= ZOOM_SPEED;
//		ft_print_result(a);
//	}
	return (0);
}
