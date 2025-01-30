/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:50:00 by jlecorne          #+#    #+#             */
/*   Updated: 2024/01/08 23:51:09 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	check_rgb(char **tab, char *s)
{
	char	*tmp;
	int		ck;
	int		i;

	i = 0;
	tmp = get_color(tab, s);
	if (!tmp)
		return (1);
	while (++i < 4)
	{
		ck = get_rgb(tmp, i);
		if (ck < 0 || ck > 255)
		{
			free(tmp);
			return (1);
		}
	}
	free(tmp);
	return (0);
}

int	check_line(char *s)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	if (!s)
		return (1);
	while (s[i] && s[i] == ' ')
		i++;
	i--;
	while (s[++i] && s[i] != ' ' && s[i] != '\n')
	{
		if (!ft_isdigit(s[i]) && s[i] != ',')
			return (1);
		if (n == 1 && s[i] == ',' && (!s[i + 1] || !ft_isdigit(s[i + 1])))
			return (1);
		if (s[i] == ',')
			n++;
	}
	while (s[i] && s[i] != '\n')
		if (s[i++] != ' ')
			return (1);
	if (n != 2)
		return (1);
	return (0);
}

int	check_colors(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] && ft_strncmp(tab[i], "F ", 2))
		i++;
	if (check_line(tab[i]))
		return (1);
	i++;
	while (tab[i] && ft_strncmp(tab[i], "C ", 2))
		i++;
	if (check_line(tab[i]))
		return (1);
	if (check_rgb(tab, "F ") || check_rgb(tab, "C "))
		return (1);
	return (0);
}
