/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:18:47 by nlence-l          #+#    #+#             */
/*   Updated: 2023/12/18 18:09:05 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int32_t	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	find_player_px_and_py(t_data *d)
{
	int	x;
	int	y;

	find_player_x_and_y(d, &x, &y);
	d->px = x * 64 + 32;
	d->py = y * 64 + 32;
}

void	find_player_x_and_y(t_data *d, int *coord_x, int *coord_y)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < d->mapHeight)
	{
		while (x < d->mapWidth)
		{
			if (d->map[y * d->mapWidth + x] == 'S'
				|| d->map[y * d->mapWidth + x] == 'N'
				|| d->map[y * d->mapWidth + x] == 'E'
				|| d->map[y * d->mapWidth + x] == 'W')
			{
				*coord_x = x;
				*coord_y = y;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

float	find_player_angle(char *map)
{
	while (*map)
	{
		if (*map == 'N')
			return (PI / 2);
		else if (*map == 'S')
			return (P3);
		else if (*map == 'W')
			return (0);
		else if (*map == 'E')
			return (PI);
		map++;
	}
	return (-1);
}

void	reset_pi(float *angle)
{
	if (*angle < 0)
		*angle += 2 * PI;
	if (*angle > 2 * PI)
		*angle -= 2 * PI;
}
