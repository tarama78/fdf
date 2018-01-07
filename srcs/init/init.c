/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 19:35:34 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/07 19:53:06 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | init.c                                                   |
**   |     ft_init_a(11 lines)                                  |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <fdf.h>

void		ft_init_a(t_a *a)
{
	a->width = WIDTH;
	a->height = HEIGHT;
	a->img.bpp = 32;
	a->img.sz_ln = a->width * 4;
	a->img.endian = 0;
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, a->width, a->height, "fdf");
	a->img.img = mlx_new_image(a->mlx, a->width, a->height);
	a->img.str = mlx_get_data_addr(a->img.img, &a->img.bpp, &a->img.sz_ln,
			&a->img.endian);
	mlx_key_hook(a->win, ft_key_event, a);
}
