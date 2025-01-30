/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:12:38 by jlecorne          #+#    #+#             */
/*   Updated: 2024/01/09 15:38:20 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	get_rgb(char *s, int k)
{
	char	*tmp;
	int		i;
	int		j;
	int		x;

	tmp = NULL;
	i = 0;
	j = 0;
	x = k;
	while (s[i] && x > 0)
	{
		if (s[i + 1] && s[i + 1] == ',')
			x--;
		i++;
	}
	j = i - 1;
	while ((j - 1) >= 0 && s[j] && s[j - 1] != ',')
		j--;
	tmp = ft_substr(s, j, i - j);
	if (!tmp)
		return (-1);
	x = ft_atoi(tmp);
	free(tmp);
	return (x);
}

int	fill_file(char **tab, int fd)
{
	int		i;
	char	*ln;

	i = -1;
	ln = get_next_line(fd);
	while (ln)
	{
		if (!ln)
			return (0);
		tab[++i] = ft_strdup(ln);
		if (!tab[i])
			return (0);
		free(ln);
		ln = get_next_line(fd);
	}
	close(fd);
	return (1);
}

char	**nfile(char *fl)
{
	int		fd;
	char	**tab;

	fd = open(fl, O_RDONLY);
	if (fd == -1)
		return (NULL);
	tab = ft_calloc(sizeof(char *), (get_nline(fl) + 1));
	if (!tab)
	{
		close(fd);
		return (NULL);
	}
	if (!fill_file(tab, fd))
	{
		close(fd);
		freetab(tab);
		return (NULL);
	}
	return (tab);
}

int	is_eol(char *line, int iter)
{
	int	i;

	i = 0;
	while (i++ < iter)
		if (line[i] == 0 || line[i] == '\n')
			return (1);
	return (0);
}
