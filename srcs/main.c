/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 12:01:38 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 15:22:19 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | main.c                                                   |
**   |     main(20 lines)                                       |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <fdf.h>

int			main(int ac, char **av)
{
	t_a		a;

	if (ac >= 2)
	{
		ft_init_a(&a, (av + 2), ac - 2);
		ft_init_file(&a, av[1]);
		mlx_hook(a.win, 2, 0, ft_key_event, &a);
		mlx_mouse_hook(a.win, ft_mouse_event, &a);
		ft_key_event(49, &a);
		mlx_loop(a.mlx);
	}
	else
	{
		ft_printf("usage: fdf map [width=%d] [height=%d] [z=%d]\n"
				"\tmove with <up> <down> <right> <left>\n"
				"\tzoom with <+> and <->\n\tchange projection with <space>\n"
				"\tchange z size with <a> and <x>\n",
				WIDTH, HEIGHT, MULT_CTE);
	}
	return (0);
}
