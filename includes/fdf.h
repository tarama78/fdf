/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:29:15 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/14 16:27:11 by tnicolas         ###   ########.fr       */
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

void		ft_error(char *file, char *func, int line, char *msg);
void		ft_init_a(t_a *a, char **arg, int nb_arg);
void		ft_check_error(t_a *a);
void		ft_check_error_line(char *line);
void		ft_init_file(t_a *a, char *file);
int			ft_set_cte(t_a *a);

t_coord		ft_set_coord(int x1, int y1, int x2, int y2);
t_coord		ft_set_coord_color(long long xy1, int c1, long long xy2, int c2);
void		ft_put_px(t_a *a, int x, int y, t_ui color);
void		ft_put_line(t_a *a, t_coord c, t_ui color);
void		ft_put_line_color(t_a *a, t_coord c);
void		ft_reset_win(t_a *a);
void		ft_print_win(t_a *a);

void		ft_close(t_a *a);
int			ft_key_event(int keycode, t_a *a);
int			ft_mouse_event(int keycode, t_a *a);
void		ft_print_result(t_a *a);

#endif
