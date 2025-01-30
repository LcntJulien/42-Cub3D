/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:28:48 by jlecorne          #+#    #+#             */
/*   Updated: 2024/01/09 15:32:37 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	freetab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	err_manager(int err, char **tab)
{
	printf("\033[31mError\033[0m\n");
	if (err == 1)
		printf("\033[33mUsage:\033[90m ./cub3D `file.cub`\033[0m\n");
	else if (err == 2)
		printf("\033[33mExpected arg:\033[90m `file.cub`\033[0m\n");
	else if (err == 3)
		printf("\033[33mMap must be the last element of the file\033[0m\n");
	else if (err == 4)
		printf("\033[33mWrong texture path name(s)\033[0m\n");
	else if (err == 5)
		printf("\033[33mWrong colors format\033[0m\n");
	else if (err == 6)
		printf("\033[33mWrong map format\033[0m\n");
	if (tab)
		freetab(tab);
	exit(1);
}
