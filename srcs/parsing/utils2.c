/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:51:47 by jlecorne          #+#    #+#             */
/*   Updated: 2024/01/09 15:12:18 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	start_num(int tab[88])
{
	if ((tab[78] > 1 || tab[83] > 1 || tab[87] > 1 || tab[69] > 1)
		|| ((tab[78] > 0 && (tab[83] > 0 || tab[87] > 0 || tab[69] > 0))
			|| (tab[83] > 0 && (tab[78] > 0 || tab[87] > 0 || tab[69] > 0))
			|| (tab[87] > 0 && (tab[78] > 0 || tab[83] > 0 || tab[69] > 0))
			|| (tab[69] > 0 && (tab[78] > 0 || tab[83] > 0 || tab[87] > 0))))
		return (1);
	return (0);
}

int	counter(char **map)
{
	int	i;
	int	j;
	int	tab[88];

	i = 0;
	j = -1;
	tab[78] = 0;
	tab[83] = 0;
	tab[87] = 0;
	tab[69] = 0;
	while (map[i] && is_map(map[i]))
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == 78 || map[i][j] == 83 || map[i][j] == 87
				|| map[i][j] == 69)
				tab[(int)map[i][j]] += 1;
		i++;
	}
	if (start_num(tab))
		return (1);
	return (0);
}

int	map_h(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
			j++;
		i++;
	}
	return (i);
}

int	map_w(char **tab)
{
	int	i;
	int	j;
	int	r;

	i = 0;
	j = 0;
	r = 0;
	while (tab[++i])
	{
		j = 0;
		while (tab[i][j])
			j++;
		if (j > r)
			r = j;
	}
	return (r - 1);
}
