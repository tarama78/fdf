/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:29:15 by tnicolas          #+#    #+#             */
/*   Updated: 2018/01/07 19:41:17 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <libft.h>
# include <unistd.h>
# include <fdf_struct.h>

void		ft_init_a(t_a *a);
void		ft_put_px(t_a *a, int x, int y, unsigned int color);
void		ft_print_win(t_a *a);
int			ft_key_event(int keycode, t_a *a);

#endif
