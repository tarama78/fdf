/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:54:17 by tnicolas          #+#    #+#             */
/*   Updated: 2017/12/05 17:30:18 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

void		ft_putstr(const char *s)
{
	if (s == NULL)
		return ;
	write(STDOUT_FILENO, s, ft_strlen(s));
}
