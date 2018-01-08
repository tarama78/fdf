/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 19:36:50 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/08 17:39:51 by tnicolas         ###   ########.fr       */
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
//	static int	x1 = 200;
//	static int	y1 = 200;
//	static int	x2 = 100;
//	static int	y2 = 100;
//
//	ft_printf("{green}(key %d){eoc}\n", keycode);
//	x1 = 200;
//	y1 = 200;
//	x2 = 100;
//	y2 = 100;
//	while (++x2 <= 300)
//		ft_put_line(a, ft_set_coord(x1, y1, x2, y2), 0x00FF00);
//	x1 = 200;
//	y1 = 200;
//	x2 = 100;
//	y2 = 300;
//	while (++x2 <= 300)
//		ft_put_line(a, ft_set_coord(x1, y1, x2, y2), 0xFF0000);
//	x1 = 200;
//	y1 = 200;
//	x2 = 100;
//	y2 = 100;
//	while (++y2 <= 300)
//		ft_put_line(a, ft_set_coord(x1, y1, x2, y2), 0xFFFF00);
//	x1 = 200;
//	y1 = 200;
//	x2 = 300;
//	y2 = 100;
//	while (++y2 <= 300)
//		ft_put_line(a, ft_set_coord(x1, y1, x2, y2), 0x00FFFF);
//	ft_print_win(a);
	(void)a;
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
