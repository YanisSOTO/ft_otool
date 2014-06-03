/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_adress_to_string.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 20:30:41 by ysoto             #+#    #+#             */
/*   Updated: 2014/04/27 20:06:47 by ysoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_convert_adress_to_string(long unsigned int addr)
{
	int			size;
	char		*str;
	static char	tmp[] = "00000000000000000000000000000000";
	char		c;
	char		*carac;

	carac = "0123456789abcdefghijklmnopqrstuvwxyz";
	size = 31;
	while (addr != 0)
	{
		c = carac[(addr % 16)];
		tmp[size] = c;
		size--;
		addr = addr / 16;
	}
	str = ft_strsub(tmp, (size + 1), ft_strlen(&tmp[size]));
	return (str);
}
