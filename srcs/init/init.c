/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 19:35:34 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/09 18:57:53 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | init.c                                                   |
**   |     ft_init_a_2(18 lines)                                |
**   |     ft_init_a(10 lines)                                  |
**   |     ft_add_last(15 lines)                                |
**   |     ft_set_color(8 lines)                                |
**   |     ft_init_file_2(25 lines)                             |
**   |     ft_init_file(18 lines)                               |
**   | MEUUUU too many functions                                |
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
	a->start_x = START_X;
	a->start_y = START_Y;
	a->zoom = ZOOM;
	a->zoom_speed = ZOOM_SPEED;
	a->move_speed = MOVE_SPEED;
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
		ft_error();
	if (!(a->win = mlx_new_window(a->mlx, a->width, a->height, "fdf")))
		ft_error();
	if (!(a->img.img = mlx_new_image(a->mlx, a->width, a->height)))
		ft_error();
	if (!(a->img.str = mlx_get_data_addr(a->img.img, &a->img.bpp, &a->img.sz_ln,
			&a->img.endian)))
		ft_error();
}

static void		ft_add_last(t_map **map, t_map *new)
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

static int		ft_set_color(t_a *a, char *s)
{
	int			ret;

	while (ft_isdigit(*s))
		s++;
	ret = ft_atoi_base(++s, "0123456789abcdef");
	if (ret == 0)
		ret = 0xFFFFFF;
	return (ret);
}

static t_map	*ft_init_file_2(t_a *a, char *line)
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
	if (!(new_map->color = malloc(sizeof(new_map->color) * i)))
		ft_error();
	new_map->w = i;
	i = -1;
	while (++i < new_map->w)
	{
		new_map->m[i] = ft_atoi(tab[i]);
		new_map->color[i] = ft_set_color(a, tab[i]);
		if (new_map->m[i] > a->max_z)
			a->max_z = new_map->m[i];
	}
	free(tab);
	return (new_map);
}

void			ft_init_file(t_a *a, char *file)
{
	char	*line;
	int		fd;
	t_map	*new_map;

	a->map_h = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error();
	while (get_next_line(fd, &line) == GNL_LINE_READ)
	{
		new_map = ft_init_file_2(a, line);
		a->map_h++;
		ft_add_last(&a->map, new_map);
		free(line);
	}
	ft_set_cte(a);
	close(fd);
}
