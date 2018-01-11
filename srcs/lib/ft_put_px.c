/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_px.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 19:33:04 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/11 16:10:35 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_put_px.c                                              |
**   |     ft_put_px(15 lines)                                  |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <fdf.h>

void		ft_put_px(t_a *a, int x, int y, t_ui color)
{
	int		i;
	t_rgb	rgb;

	rgb = *(t_rgb*)&color;
	i = x * 4 + y * a->width * 4;
	if (x < 0 || x >= a->width || y < 0 || y >= a->height || i < 0 ||
			i > a->height * a->width * 4)
	{
//		ft_printf("{red}%s: %s(x = %d, y = %d) -> print out of windows{eoc}\n",
//				__FILE__, __func__, x, y);
		return ;
	}
	a->img.str[i] = (char)rgb.b;
	a->img.str[i + 1] = (char)rgb.g;
	a->img.str[i + 2] = (char)rgb.r;
}
