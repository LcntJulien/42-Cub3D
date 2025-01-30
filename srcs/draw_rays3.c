/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlence-l <nlence-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:17:52 by nlence-l          #+#    #+#             */
/*   Updated: 2023/12/19 15:20:29 by nlence-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	draw_door_texture(t_data *d)
{
	int	i;
	int	y;
	int	pixel;

	i = 0;
	y = 0;
	while (y < d->lineH)
	{
		pixel = ((int)d->ty * 32 + (int)d->tx) * 4;
		while (i++ < WIDTH / 120)
		{
			if ((pixel + 3) < 4096)
				mlx_put_pixel(d->world, d->r + d->cpt + i, y + (int)d->lineO,
					get_rgba(d->t->DO_img->pixels[pixel + 0],
						d->t->DO_img->pixels[pixel + 1],
						d->t->DO_img->pixels[pixel + 2],
						d->t->DO_img->pixels[pixel + 3]));
		}
		d->ty += d->ty_step;
		i = 0;
		y++;
	}
}

void	draw_north_texture(t_data *d)
{
	int	i;
	int	y;
	int	pixel;

	i = 0;
	y = 0;
	while (y < d->lineH)
	{
		pixel = ((int)d->ty * 32 + (int)d->tx) * 4;
		while (i++ < WIDTH / 120)
		{
			if ((pixel + 3) < 4096)
				mlx_put_pixel(d->world, d->r + d->cpt + i, y + (int)d->lineO,
					get_rgba(d->t->NO_img->pixels[pixel + 0],
						d->t->NO_img->pixels[pixel + 1],
						d->t->NO_img->pixels[pixel + 2],
						d->t->NO_img->pixels[pixel + 3]));
		}
		d->ty += d->ty_step;
		i = 0;
		y++;
	}
}

void	draw_south_texture(t_data *d)
{
	int	i;
	int	y;
	int	pixel;

	i = 0;
	y = 0;
	while (y < d->lineH)
	{
		pixel = ((int)d->ty * 32 + (int)d->tx) * 4;
		while (i++ < WIDTH / 120)
		{
			if ((pixel + 3) < 4096)
				mlx_put_pixel(d->world, d->r + d->cpt + i, y + (int)d->lineO,
					get_rgba(d->t->SO_img->pixels[pixel + 0],
						d->t->SO_img->pixels[pixel + 1],
						d->t->SO_img->pixels[pixel + 2],
						d->t->SO_img->pixels[pixel + 3]));
		}
		d->ty += d->ty_step;
		i = 0;
		y++;
	}
}

void	draw_east_texture(t_data *d)
{
	int	i;
	int	y;
	int	pixel;

	i = 0;
	y = 0;
	while (y < d->lineH)
	{
		pixel = ((int)d->ty * 32 + (int)d->tx) * 4;
		while (i++ < WIDTH / 120)
		{
			if ((pixel + 3) < 4096)
				mlx_put_pixel(d->world, d->r + d->cpt + i, y + (int)d->lineO,
					get_rgba(d->t->EA_img->pixels[pixel + 0],
						d->t->EA_img->pixels[pixel + 1],
						d->t->EA_img->pixels[pixel + 2],
						d->t->EA_img->pixels[pixel + 3]));
		}
		d->ty += d->ty_step;
		i = 0;
		y++;
	}
}

void	draw_west_texture(t_data *d)
{
	int	i;
	int	y;
	int	pixel;

	i = 0;
	y = 0;
	while (y < d->lineH)
	{
		pixel = ((int)d->ty * 32 + (int)d->tx) * 4;
		while (i++ < WIDTH / 120)
		{
			if ((pixel + 3) < 4096)
				mlx_put_pixel(d->world, d->r + d->cpt + i, y + (int)d->lineO,
					get_rgba(d->t->WE_img->pixels[pixel + 0],
						d->t->WE_img->pixels[pixel + 1],
						d->t->WE_img->pixels[pixel + 2],
						d->t->WE_img->pixels[pixel + 3]));
		}
		d->ty += d->ty_step;
		i = 0;
		y++;
	}
}
