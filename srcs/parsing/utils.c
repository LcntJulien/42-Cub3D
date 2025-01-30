/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:15:44 by jlecorne          #+#    #+#             */
/*   Updated: 2024/01/09 16:48:35 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	get_nline(char *fl)
{
	int		i;
	int		fd;
	char	*ln;

	i = 0;
	fd = open(fl, O_RDONLY);
	if (fd == -1)
		return (-1);
	ln = get_next_line(fd);
	while (ln)
	{
		i++;
		free(ln);
		ln = get_next_line(fd);
	}
	if (ln)
		free(ln);
	close(fd);
	return (i);
}

int	is_map(char *ln)
{
	int	i;

	i = -1;
	if (!ln || ln[0] == '\n')
		return (0);
	while (ln && ln[++i])
	{
		if (ln[i] != '0' && ln[i] != '1' && ln[i] != '4' && ln[i] != 'N'
			&& ln[i] != 'S' && ln[i] != 'W' && ln[i] != 'E'
			&& ln[i] != ' ' && ln[i] != '\n')
			return (0);
	}
	return (1);
}

int	get_height(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i] && !is_map(tab[i]))
		i++;
	while (tab[i] && tab[i + j] && tab[i + j][0] != '\n')
		j++;
	return (j);
}

void	cmp_path(char *ln, int *enu)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_substr(ln, 0, 3);
	tmp2 = ft_substr(ln, 0, 2);
	if (!tmp1 || !tmp2)
		return ;
	if (ft_memcmp(tmp1, "NO ", 3) == 0 || ft_memcmp(tmp2, "N ", 2) == 0)
		enu[0]++;
	else if (ft_memcmp(tmp1, "SO ", 3) == 0 || ft_memcmp(tmp2, "S ", 2) == 0)
		enu[1]++;
	else if (ft_memcmp(tmp1, "WE ", 3) == 0 || ft_memcmp(tmp2, "W ", 2) == 0)
		enu[2]++;
	else if (ft_memcmp(tmp1, "EA ", 3) == 0 || ft_memcmp(tmp2, "E ", 2) == 0)
		enu[3]++;
	else if (ft_memcmp(tmp2, "F ", 2) == 0)
		enu[4]++;
	else if (ft_memcmp(tmp2, "C ", 2) == 0)
		enu[5]++;
	free(tmp1);
	free(tmp2);
	return ;
}

char	**nmap(char **tab)
{
	char	**map;
	int		i;
	int		j;

	if (get_height(tab) == 0)
		return (NULL);
	map = ft_calloc(sizeof(char *), (get_height(tab) + 1));
	if (!map)
		return (NULL);
	i = 0;
	j = -1;
	while (tab[i] && !is_map(tab[i]))
		i++;
	while (tab[i] && tab[i][0] != '\n')
	{
		map[++j] = ft_strdup(tab[i++]);
		if (!map[j])
		{
			freetab(map);
			return (NULL);
		}
	}
	return (map);
}
