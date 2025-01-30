/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:18:06 by nlence-l          #+#    #+#             */
/*   Updated: 2024/01/04 19:48:00 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	draw_map(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < WIDTH)
	{
		while (j < HEIGHT)
		{
			mlx_put_pixel(d->world, i, j, get_rgba(0, 0, 0, 0));
			j++;
		}
		j = 0;
		i++;
	}
}

void	init_ceil_and_floor_color(t_data *d)
{
	d->RC = get_rgb(d->ccolor, 1);
	if (d->RC == -1)
		error(d, 0);
	d->GC = get_rgb(d->ccolor, 2);
	if (d->GC == -1)
		error(d, 0);
	d->BC = get_rgb(d->ccolor, 3);
	if (d->BC == -1)
		error(d, 0);
	d->TC = 255;
	d->RF = get_rgb(d->fcolor, 1);
	if (d->RF == -1)
		error(d, 0);
	d->GF = get_rgb(d->fcolor, 2);
	if (d->GF == -1)
		error(d, 0);
	d->BF = get_rgb(d->fcolor, 3);
	if (d->BF == -1)
		error(d, 0);
	d->TF = 255;
}

void	init_data(t_data *d)
{
	init_ceil_and_floor_color(d);
	d->time = 0.0;
	d->vertical = 1;
	d->north = 1;
	d->east = 1;
	d->door = 0;
	find_player_px_and_py(d);
	d->pa = find_player_angle(d->map);
	d->pdx = cos(d->pa) * 5;
	d->pdy = sin(d->pa) * 5;
	d->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!d->mlx)
		error(d, 1);
	d->world = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	if (!d->world)
		error(d, 2);
	memset(d->world->pixels, 0,
		d->world->width * d->world->height * sizeof(int32_t));
	mlx_image_to_window(d->mlx, d->world, 0, 0);
}
