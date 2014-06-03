/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 20:41:25 by ysoto             #+#    #+#             */
/*   Updated: 2014/04/27 20:01:15 by ysoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

char			*ft_itoa_base_16(int nbr)
{
	char			*ascii_tab;
	char			buff[3];
	char			*ret;
	unsigned int	unsigned_nbr;

	ascii_tab = "0123456789abcdefghijklmnopqrstuvwxyz";
	unsigned_nbr = (unsigned int)nbr;
	buff[2] = 0;
	ret = buff + 1;
	*ret = '0';
	while (unsigned_nbr > 0)
	{
		*ret-- = ascii_tab[(unsigned_nbr % 16)];
		unsigned_nbr = unsigned_nbr / 16;
		if (ret < buff)
			break ;
	}
	ret++;
	while (ret > buff)
	{
		ret--;
		*ret = '0';
	}
	return (ft_strdup(ret));
}

void			ft_print_addr(long unsigned int addr)
{
	char	*addr_str;
	int		len_addr;
	int		i;
	int		j;

	len_addr = 0;
	i = 0;
	j = 0;
	addr_str = ft_convert_adress_to_string(addr);
	len_addr = ft_strlen(addr_str);
	i = 16 - len_addr;
	while (j < i)
	{
		ft_putstr("0");
		j++;
	}
	write(1, addr_str, 9);
	write(1, " ", 1);
}

void			ft_print_otool(struct section_64 *sc, struct mach_header_64 *mc)
{
	char					*ptr;
	char					*tmp;
	unsigned long long		i;
	long unsigned int		addr;

	i = 0;
	ft_putendl("(__TEXT,__text) section");
	ptr = (char *)mc + sc->offset;
	addr = sc->addr;
	while (i < sc->size)
	{
		if (i == 0 || (i % 16) == 0)
		{
			if (i != 0)
				addr += 16;
			ft_print_addr(addr);
		}
		tmp = ft_itoa_base_16(ptr[i]);
		ft_putstr(tmp);
		write(1, " ", 1);
		if ((i + 1) % 16 == 0)
			write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}
