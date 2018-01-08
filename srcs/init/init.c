/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 19:35:34 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/09 00:16:52 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | init.c                                                   |
**   |     ft_init_a_2(19 lines)                                |
**   |     ft_init_a(10 lines)                                  |
**   |     ft_add_last(15 lines)                                |
**   |     ft_init_file_2(18 lines)                             |
**   |     ft_init_file(15 lines)                               |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <fdf.h>

static void	ft_init_a_2(t_a *a)
{
	a->width = WIDTH;
	a->height = HEIGHT;
	a->start_x = START_X;
	a->start_y = START_Y;
	a->zoom = ZOOM;
	a->zoom_speed = ZOOM_SPEED;
	a->move_speed = MOVE_SPEED;
	a->def.zoom = a->zoom;
	a->def.start_x = a->start_x;
	a->def.start_y = a->start_y;
	a->para_cte = PARA_CTE;
	a->isom_cte1 = ISOM_CTE1;
	a->isom_cte2 = ISOM_CTE2;
	a->img.bpp = 32;
	a->img.sz_ln = a->width * 4;
	a->img.endian = 0;
	a->map = NULL;
	a->proj = PARA;
	a->color.c = 0x00FF00;
}

void		ft_init_a(t_a *a)
{
	ft_init_a_2(a);
	if (!(a->mlx = mlx_init()))
		ft_error();
	if (!(a->win = mlx_new_window(a->mlx, a->width, a->height, "fdf")))
		ft_error();
	if (!(a->img.img = mlx_new_image(a->mlx, a->width, a->height)))
		ft_error();
	if (!(a->img.str = mlx_get_data_addr(a->img.img, &a->img.bpp, &a->img.sz_ln,
			&a->img.endian)))
		ft_error();
}

static void	ft_add_last(t_map **map, t_map *new)
{
	t_map	*tmp;

	tmp = *map;
	if (new == NULL)
		return ;
	if (tmp == NULL)
	{
		*map = new;
		new->next = NULL;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}

static t_map	*ft_init_file_2(char *line)
{
	t_map	*new_map;
	char	**tab;
	int		i;

	tab = ft_strsplit(line, ' ');
	i = -1;
	while (tab[++i] != 0)
		;
	if (!(new_map = malloc(sizeof(t_map))))
		ft_error();
	if (!(new_map->m = malloc(sizeof(new_map->m) * i)))
		ft_error();
	new_map->w = i;
	i = -1;
	while (++i < new_map->w)
		new_map->m[i] = ft_atoi(tab[i]);
	free(tab);
	return (new_map);
}

void		ft_init_file(t_a *a, char *file)
{
	char	*line;
	int		fd;
	t_map	*new_map;

	a->map_h = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error();
	while (get_next_line(fd, &line) == GNL_LINE_READ)
	{
		new_map = ft_init_file_2(line);
		a->map_h++;
		ft_add_last(&a->map, new_map);
		free(line);
	}
	close(fd);
}
