/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:14:49 by tnicolas          #+#    #+#             */
/*   Updated: 2017/12/04 15:47:01 by tnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char		*ft_convert_base(char *n, char *base_in, char *base_out)
{
	long long	int_nb;
	char		*ret;

	int_nb = ft_base_to_int(n, base_in);
	if (!(ret = ft_int_to_base(int_nb, base_out)))
		return (NULL);
	return (ret);
}
