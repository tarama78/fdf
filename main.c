/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 12:01:38 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/07 15:50:29 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | main.c                                                   |
**   |     main(10 lines)                                       |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <mlx.h>
#include <libft.h>

typedef struct s_a
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
}				t_a;

int			ft_key_event(int keycode, void *param)
{
	t_a		*a;

	a = (t_a*)param;
	ft_printf("%d\n", keycode);
	return (0);
}

int			main(int ac, char **av)
{
	t_a		a;

	a.mlx = mlx_init();
	a.win = mlx_new_window(a.mlx, 800, 800, "equanime");
	a.x = 12;
	a.y = 65;
	while (++a.y < 180)
	{
		if (a.y % 2 == 0)
			a.x++;
		mlx_pixel_put(a.mlx, a.win, a.x, a.y, 0x00FFFFFF);
	}
	mlx_key_hook(a.win, ft_key_event, a)
	mlx_loop(a.mlx);
	return (0);
}
