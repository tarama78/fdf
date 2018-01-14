/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:11:38 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 15:34:51 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_close.c                                               |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <fdf.h>

void		ft_del_map(t_a *a)
{
	t_map	*list;
	t_map	*free_list;

	if (a->map != NULL)
	{
		list = a->map;
		while (list->next)
		{
			free(list->m);
			free(list->color);
			free_list = list;
			list = list->next;
			free(free_list);
			free_list = NULL;
		}
		free(list->m);
		free(list->color);
		free(list);
		list = NULL;
		a->map = NULL;
	}
}

void		ft_close(t_a *a)
{
	mlx_destroy_image(a->mlx, a->img.img);
	ft_del_map(a);
}
