/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:26:00 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/11 16:24:11 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   ____________________________________________________________
**   | ft_check_error.c                                         |
**   |     ft_check_error(1 lines)                              |
**   |     ft_check_error_line(24 lines)                        |
**   ------------------------------------------------------------
**           __n__n__  /
**    .------`-\00/-'/
**   /  ##  ## (oo)
**  / \## __   ./
**     |//YY \|/
**     |||   |||
*/

#include <fdf.h>

void		ft_check_error(t_a *a)
{
	a->max_z = (a->max_z == 0) ? 1 : a->max_z;
}

void		ft_check_error_line(char *line)
{
	int		i;

	while (*line == ' ')
		++line;
	line += (*line == '-') ? 1 : 0;
	while (ft_isdigit(*line))
		++line;
	if (*line == ',')
	{
		if (*(++line) == '0' && ft_tolower(*(++line)) == 'x')
		{
			i = 0;
			while (*(++line) != 0 && ft_strchr("0123456789abcdef",
						ft_tolower(*line)))
				++i;
			if (i > 6 && *line != '\0')
				*line = 'e';
		}
		else
			*line = 'e';
	}
	if (*line == ' ')
		ft_check_error_line(line);
	else if (*line != '\0')
		ft_error(__FILE__, (char*)__func__, __LINE__, "File not well formated");
}
