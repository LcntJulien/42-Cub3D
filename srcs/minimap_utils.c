/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlence-l <nlence-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:44:12 by nlence-l          #+#    #+#             */
/*   Updated: 2023/12/31 14:44:38 by nlence-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	draw_player(t_data *d)
{
	int	i;
	int	j;

	i = 1150;
	j = 50;
	while (i < 1155)
	{
		while (j < 55)
		{
			mlx_put_pixel(d->world, i, j, get_rgba(255, 255, 0, 255));
			j++;
		}
		j = 50;
		i++;
	}
}

void	draw_wall(t_data *d)
{
	int	i;
	int	j;

	i = d->x_start;
	j = d->y_start;
	while (i < (d->x_start + 20))
	{
		while (j < (d->y_start + 20))
		{
			mlx_put_pixel(d->world, i, j, get_rgba(0, 0, 0, 255));
			j++;
		}
		j = d->y_start;
		i++;
	}
	d->x_start = i;
}

void	draw_empty(t_data *d)
{
	int	i;
	int	j;

	i = d->x_start;
	j = d->y_start;
	while (i < (d->x_start + 20))
	{
		while (j < (d->y_start + 20))
		{
			mlx_put_pixel(d->world, i, j, get_rgba(0, 0, 0, 0));
			j++;
		}
		j = d->y_start;
		i++;
	}
	d->x_start = i;
}

void	check_minimap(t_data *d)
{
	if (d->x_start == 1200)
	{
		d->x_start -= 100;
		d->y_start += 20;
	}
}

void	init_minimap(t_data *d)
{
	d->pos = ((int)((int)d->py / 64)) * d->mapWidth + (int)(d->px / 64);
	d->pos_start = d->pos - (2 * d->mapWidth) - 2;
	d->pos_end = d->pos + (2 * d->mapWidth) + 2;
	d->x_start = 1100;
	d->y_start = 0;
}
