/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:26:01 by jlecorne          #+#    #+#             */
/*   Updated: 2024/01/09 16:56:49 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

char	*get_path(char **tab, char *cmp1, char *cmp2)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 2;
	k = 0;
	if (!tab)
		return (NULL);
	while (tab[i] && ft_strncmp(tab[i], cmp1, 3) && ft_strncmp(tab[i], cmp2, 2))
		i++;
	if (!tab[i])
		return (NULL);
	if (ft_strncmp(tab[i], cmp1, 3) == 0)
		j++;
	while (tab[i][j] && tab[i][j] == ' ')
		j++;
	k = j;
	while (tab[i][j] && tab[i][j] != '\n' && tab[i][j] != ' ')
		j++;
	return (ft_substr(tab[i], k, (j - k)));
}

char	*get_color(char **tab, char *cmp)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 2;
	k = 0;
	if (!tab)
		return (NULL);
	while (tab[i] && ft_strncmp(tab[i], cmp, 2))
		i++;
	if (!tab[i])
		return (NULL);
	while (tab[i][j] == ' ')
		j++;
	k = j;
	while (tab[i][j] && (ft_isdigit(tab[i][j]) || tab[i][j] == ','))
		j++;
	return (ft_substr(tab[i], k, (j - k)));
}

char	*get_map(t_data *cub, char **tab)
{
	char	*map;
	int		i;
	int		j;
	int		k;

	map = ft_calloc(sizeof(char), (cub->mapHeight * cub->mapWidth) + 1);
	if (!map)
		return (NULL);
	i = -1;
	j = 0;
	k = 0;
	while (tab[++i])
	{
		j = -1;
		while (++j < cub->mapWidth)
		{
			if (!is_eol(tab[i], j) && tab[i][j] && tab[i][j] != 0
				&& tab[i][j] != ' ' && tab[i][j] != '\n')
				map[k++] = tab[i][j];
			else
				map[k++] = '1';
		}
	}
	return (map);
}

int	get_cub(t_data *cub, char **ftab, char **tmp)
{
	cub->squareSize = 64;
	cub->mapHeight = map_h(tmp);
	cub->mapWidth = map_w(tmp);
	cub->map = get_map(cub, tmp);
	if (!cub->map)
		return (1);
	cub->ccolor = get_color(ftab, "C ");
	if (!cub->ccolor)
		return (1);
	cub->fcolor = get_color(ftab, "F ");
	if (!cub->fcolor)
		return (1);
	cub->t->NO_path = get_path(ftab, "NO ", "N ");
	if (!cub->t->NO_path)
		return (1);
	cub->t->SO_path = get_path(ftab, "SO ", "S ");
	if (!cub->t->SO_path)
		return (1);
	cub->t->WE_path = get_path(ftab, "WE ", "W ");
	if (!cub->t->WE_path)
		return (1);
	cub->t->EA_path = get_path(ftab, "EA ", "E ");
	if (!cub->t->EA_path)
		return (1);
	return (0);
}

void	init_cub(t_data *cub, char *fl)
{
	char	**ftab;
	char	**tmp;

	ftab = nfile(fl);
	if (!ftab)
		error(cub, 0);
	tmp = nmap(ftab);
	if (!tmp)
	{
		free(ftab);
		error(cub, 0);
	}
	cub->t = malloc(sizeof(t_textures));
	if (!cub->t)
	{
		freetab(ftab);
		freetab(tmp);
		error(cub, 0);
	}
	if (get_cub(cub, ftab, tmp))
		error(cub, 1);
	freetab(ftab);
	freetab(tmp);
	return ;
}
