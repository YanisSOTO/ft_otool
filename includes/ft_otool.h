/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 11:55:12 by ysoto             #+#    #+#             */
/*   Updated: 2014/04/27 20:03:39 by ysoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OTOOL_H
# define FT_OTOOL_H

# include "../libft/libft.h"
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>

void	ft_print_addr(long unsigned int addr);
char	*ft_itoa_base_16(int nbr);
void	ft_print_otool(struct section_64 *sc, struct mach_header_64 *mc);
void	ft_print_ft(struct fat_arch *section64, struct fat_header *mcheader64);

#endif
