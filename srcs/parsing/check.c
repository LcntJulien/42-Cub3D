/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:46:46 by jlecorne          #+#    #+#             */
/*   Updated: 2024/01/09 12:39:29 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	check_map(char **tab)
{
	int		r;
	char	**map;

	r = 0;
	map = nmap(tab);
	if (!map)
		return (1);
	r += check_start(map);
	r += scan_map(map);
	r += map_leaks(map);
	freetab(map);
	return (r);
}

int	check_paths(char **tab)
{
	int	*enu;
	int	i;

	i = 0;
	enu = ft_calloc(sizeof(int), 6);
	if (!enu)
		return (1);
	while (tab[i] && !is_map(tab[i]))
		cmp_path(tab[i++], enu);
	i = -1;
	while (++i < 6)
	{
		if (enu[i] != 1)
		{
			free(enu);
			return (1);
		}
	}
	free(enu);
	return (0);
}

int	check_fl(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] && !is_map(tab[i]))
		i++;
	while (tab[i] && is_map(tab[i]))
		i++;
	while (tab[i])
	{
		if (tab[i] != NULL && tab[i][0] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	check_ext(char *fl)
{
	char		*tmp;
	char const	*cmp;
	int			i;

	if (!fl)
		return (1);
	tmp = ft_substr(fl, ft_strlen(fl) - 4, 4);
	if (!tmp)
		return (1);
	cmp = ".cub";
	i = ft_memcmp(tmp, cmp, 4);
	free(tmp);
	return (i);
}

void	check_cub(int ac, char *fl)
{
	char	**ftab;

	if (ac != 2)
		err_manager(1, NULL);
	ftab = nfile(fl);
	if (!ftab)
		err_manager(1, NULL);
	if (check_ext(fl) != 0)
		err_manager(2, ftab);
	if (check_fl(ftab))
		err_manager(3, ftab);
	if (check_paths(ftab))
		err_manager(4, ftab);
	if (check_colors(ftab))
		err_manager(5, ftab);
	if (check_map(ftab))
		err_manager(6, ftab);
	freetab(ftab);
}
