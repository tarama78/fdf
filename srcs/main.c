/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 12:01:38 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/08 18:32:48 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | main.c                                                   |
**   |     main(7 lines)                                        |
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

	(void)ac;
	(void)av;
	if (ac == 2)
	{
		ft_init_a(&a);
		ft_init_file(&a, av[1]);
		mlx_key_hook(a.win, ft_key_event, &a);
		mlx_mouse_hook(a.win, ft_mouse_event, &a);
		ft_print_result(&a);
		mlx_loop(a.mlx);
	}
	else
		ft_printf("usage: fdf map\n");
	return (0);
}
