/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 19:35:34 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/11 16:10:35 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_init_a.c                                              |
**   |     ft_init_a_2(20 lines)                                |
**   |     ft_init_a(10 lines)                                  |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <fdf.h>

static void		ft_init_a_2(t_a *a, char **arg, int nb_arg)
{
	a->width = (nb_arg > 0 && ft_atoi(arg[0]) != 0) ? ft_atoi(arg[0]) : WIDTH;
	a->height = (nb_arg > 1 && ft_atoi(arg[1]) != 0) ? ft_atoi(arg[1]) : HEIGHT;
	a->mult_cte = (nb_arg > 2 && ft_atoi(arg[2]) != 0) ? ft_atoi(arg[2]) :
		MULT_CTE;
	a->start_x = 0;
	a->start_y = 0;
	a->add_x = 0;
	a->add_y = 0;
	a->add_cte = 1 * (double)a->mult_cte / MULT_CTE;
	a->move_speed = MOVE_SPEED;
	a->zoom = ZOOM;
	a->def.zoom = a->zoom;
	a->def.start_x = a->start_x;
	a->def.start_y = a->start_y;
	a->img.bpp = 32;
	a->img.sz_ln = a->width * 4;
	a->img.endian = 0;
	a->map = NULL;
	a->proj = PARA;
	a->max_z = 0;
}

void			ft_init_a(t_a *a, char **arg, int nb_arg)
{
	ft_init_a_2(a, arg, nb_arg);
	if (!(a->mlx = mlx_init()))
		ft_error(__FILE__, (char*)__func__, __LINE__, NULL);
	if (!(a->win = mlx_new_window(a->mlx, a->width, a->height, "fdf")))
		ft_error(__FILE__, (char*)__func__, __LINE__, NULL);
	if (!(a->img.img = mlx_new_image(a->mlx, a->width, a->height)))
		ft_error(__FILE__, (char*)__func__, __LINE__, NULL);
	if (!(a->img.str = mlx_get_data_addr(a->img.img, &a->img.bpp, &a->img.sz_ln,
			&a->img.endian)))
		ft_error(__FILE__, (char*)__func__, __LINE__, NULL);
}
