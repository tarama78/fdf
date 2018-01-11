/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:20:33 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/11 17:02:40 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_init_file.c                                           |
**   |     ft_add_last(15 lines)                                |
**   |     ft_set_color(9 lines)                                |
**   |     ft_init_file_2(25 lines)                             |
**   |     ft_init_file(24 lines)                               |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <fdf.h>

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

	(void)a;
	while (ft_isdigit(*s) || *s == '-')
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
		ft_error(__FILE__, (char*)__func__, __LINE__, NULL);
	if (!(new_map->m = malloc(sizeof(new_map->m) * i)))
		ft_error(__FILE__, (char*)__func__, __LINE__, NULL);
	if (!(new_map->color = malloc(sizeof(new_map->color) * i)))
		ft_error(__FILE__, (char*)__func__, __LINE__, NULL);
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

static void		ft_set_max_z(t_a *a)
{
	t_map	*map;
	int		x;
	int		y;

	map = a->map;
	y = -1;
	while (++y < a->map_h)
	{
		x = -1;
		while (++x < map->w)
			map->m[x] = floor(map->m[x] * MAX_Z / (double)a->max_z);
		map = map->next;
	}
}

void			ft_init_file(t_a *a, char *file)
{
	char	*line;
	int		fd;
	int		ret_gnl;
	t_map	*new_map;

	a->map_h = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_error(__FILE__, (char*)__func__, __LINE__, NULL);
	while ((ret_gnl = get_next_line(fd, &line)) == GNL_LINE_READ)
	{
		ft_check_error_line(line);
		new_map = ft_init_file_2(a, line);
		a->map_h++;
		if (a->map != NULL && a->map->w != new_map->w)
			ft_error(__FILE__, (char*)__func__, __LINE__,
					"Map is not rectangle");
		ft_add_last(&a->map, new_map);
		free(line);
	}
	if (ret_gnl == GNL_ERROR)
		ft_error(__FILE__, (char*)__func__, __LINE__, NULL);
	ft_check_error(a);
	ft_set_max_z(a);
	ft_set_cte(a);
	close(fd);
}
