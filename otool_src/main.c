/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 11:58:21 by ysoto             #+#    #+#             */
/*   Updated: 2014/04/27 19:58:40 by ysoto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

static void		ft_otool_obj(void *start, unsigned int i, void *ptr)
{
	struct section_64			*section64;
	struct segment_command_64	*segcmd64;
	struct load_command			*loadcmd;
	struct mach_header_64		*mcheader64;
	void						*new_ptr;

	mcheader64 = start;
	ptr = mcheader64 + sizeof(*start);
	while (i++ < mcheader64->ncmds)
	{
		loadcmd = (struct load_command *)ptr;
		if (loadcmd->cmd == LC_SEGMENT_64)
		{
			segcmd64 = (struct segment_command_64 *)ptr;
			new_ptr = segcmd64 + sizeof(*ptr);
			section64 = (struct section_64 *)new_ptr;
			if (ft_strcmp(section64->sectname, "__text") == 0)
				ft_print_otool(section64, mcheader64);
		}
		ptr += loadcmd->cmdsize;
	}
}

static void		ft_otool_exe(void *start, unsigned int i, void *ptr)
{
	struct section_64			*section64;
	struct segment_command_64	*segcmd64;
	struct load_command			*loadcmd;
	struct mach_header_64		*mcheader64;
	void						*new_ptr;

	mcheader64 = start;
	ptr = mcheader64 + sizeof(*start);
	while (i++ < mcheader64->ncmds)
	{
		loadcmd = (struct load_command *)ptr;
		if (loadcmd->cmd == LC_SEGMENT_64)
		{
			segcmd64 = (struct segment_command_64 *)ptr;
			if (ft_strcmp(segcmd64->segname, "__TEXT") == 0)
			{
				new_ptr = segcmd64 + sizeof(*ptr);
				section64 = (struct section_64 *)new_ptr;
				if (ft_strcmp(section64->sectname, "__text") == 0)
					ft_print_otool(section64, mcheader64);
			}
		}
		ptr += loadcmd->cmdsize;
	}
}

static void		*map_file(char *fname)
{
	int				fd;
	void			*map;
	struct stat		buf;

	if ((fd = open(fname, O_RDONLY)) < 0)
	{
		ft_putendl("open failed");
		return (0);
	}
	if (fstat(fd, &buf) == -1)
	{
		ft_putendl("fstat failed");
		return (0);
	}
	map = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (map == MAP_FAILED)
	{
		ft_putendl("mmap failed");
		return (0);
	}
	return (map);
}

static void		ft_init(char *fname)
{
	struct mach_header_64	*mch;
	void					*ptr;

	ptr = NULL;
	if (!(mch = map_file(fname)))
		return ;
	if (mch->magic == MH_MAGIC_64 || mch->magic == MH_CIGAM_64)
	{
		if (mch->filetype == MH_OBJECT)
			ft_otool_obj(mch, 0, ptr);
		else
			ft_otool_exe(mch, 0, ptr);
	}
	else
		ft_putendl("The file isn't a file.object");
}

int				main(int ac, char *av[])
{
	int		i;

	i = 1;
	if (ac == 1)
	{
		ft_putendl("Argument required");
		return (0);
	}
	else
	{
		while (i < ac)
		{
			ft_init(av[i]);
			i++;
		}
	}
	return (0);
}
