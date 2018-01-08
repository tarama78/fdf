/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:29:15 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/08 17:38:09 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <libft.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <fdf_struct.h>

void		ft_error();
void		ft_init_a(t_a *a);
void		ft_init_file(t_a *a, char *file);

t_coord		ft_set_coord(int x1, int y1, int x2, int y2);
void		ft_put_px(t_a *a, int x, int y, t_ui color);
void		ft_put_line(t_a *a, t_coord c, t_ui color);
void		ft_print_win(t_a *a);

int			ft_key_event(int keycode, t_a *a);
void		ft_print_result(t_a *a);

#endif
