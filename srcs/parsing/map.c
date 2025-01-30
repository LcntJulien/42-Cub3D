/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:11:19 by jlecorne          #+#    #+#             */
/*   Updated: 2023/12/22 13:51:32 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	floodfill(char **map, int i, int j)
{
	int	r;

	r = 0;
	if ((map[i] && (size_t)j > ft_strlen(map[i])) || !map[i] || !map[i][j])
		return (1);
	if (map[i][j] == '1' || map[i][j] == 'K')
		return (0);
	if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '4'
		&& map[i][j] != 'K' && map[i][j] != 'N' && map[i][j] != 'S'
		&& map[i][j] != 'W' && map[i][j] != 'E')
		return (1);
	map[i][j] = 'K';
	if (floodfill(map, i + 1, j) || floodfill(map, i - 1, j) || floodfill(map,
			i, j + 1) || floodfill(map, i, j - 1))
	{
		r = 1;
	}
	return (r);
}

int	map_leaks(char **map)
{
	int	r;
	int	i;
	int	j;

	r = 0;
	i = -1;
	j = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == '0')
				r += floodfill(map, i, j);
		if (r > 0)
			break ;
	}
	return (r);
}

int	forbiden(char *ln)
{
	int	i;

	i = -1;
	while (ln[++i])
	{
		if (ln[i] != '0' && ln[i] != '1' && ln[i] != '4' && ln[i] != ' '
			&& ln[i] != 'N' && ln[i] != 'S' && ln[i] != 'W' && ln[i] != 'E'
			&& ln[i] != '\n')
			return (1);
	}
	return (0);
}

int	scan_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		if ((map[i + 1] && map[i][0] == '\n') || forbiden(map[i]))
			return (1);
	return (0);
}

int	check_start(char **map)
{
	int	i;

	i = 0;
	while (map[i] && !is_map(map[i]))
		i++;
	if (counter(map))
		return (1);
	return (0);
}
