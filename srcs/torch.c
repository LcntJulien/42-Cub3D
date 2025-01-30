/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlence-l <nlence-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:17:22 by nlence-l          #+#    #+#             */
/*   Updated: 2023/12/13 19:53:08 by nlence-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	draw_torch(t_data *d)
{
	int	ty;
	int	tx;

	ty = 0;
	tx = 0;
	d->offset = 0;
	while (ty < 200)
	{
		while (tx < 200)
		{
			if (d->t->torch->pixels[d->offset + 0] != 0
				|| d->t->torch->pixels[d->offset + 1] != 0
				|| d->t->torch->pixels[d->offset + 2] != 0
				|| d->t->torch->pixels[d->offset + 3] != 0)
				mlx_put_pixel(d->world, tx, ty,
					get_rgba(d->t->torch->pixels[d->offset + 0],
						d->t->torch->pixels[d->offset + 1],
						d->t->torch->pixels[d->offset + 2],
						d->t->torch->pixels[d->offset + 3]));
			tx++;
			d->offset += 4;
		}
		tx = 0;
		ty++;
	}
}

void	draw_torch1(t_data *d)
{
	int	ty;
	int	tx;

	ty = 0;
	tx = 0;
	d->offset = 0;
	while (ty < 200)
	{
		while (tx < 200)
		{
			if (d->t->torch1->pixels[d->offset + 0] != 0
				|| d->t->torch1->pixels[d->offset + 1] != 0
				|| d->t->torch1->pixels[d->offset + 2] != 0
				|| d->t->torch1->pixels[d->offset + 3] != 0)
				mlx_put_pixel(d->world, tx, ty,
					get_rgba(d->t->torch1->pixels[d->offset + 0],
						d->t->torch1->pixels[d->offset + 1],
						d->t->torch1->pixels[d->offset + 2],
						d->t->torch1->pixels[d->offset + 3]));
			tx++;
			d->offset += 4;
		}
		tx = 0;
		ty++;
	}
}

void	draw_torch2(t_data *d)
{
	int	ty;
	int	tx;

	ty = 0;
	tx = 0;
	d->offset = 0;
	while (ty < 200)
	{
		while (tx < 200)
		{
			if (d->t->torch2->pixels[d->offset + 0] != 0
				|| d->t->torch2->pixels[d->offset + 1] != 0
				|| d->t->torch2->pixels[d->offset + 2] != 0
				|| d->t->torch2->pixels[d->offset + 3] != 0)
				mlx_put_pixel(d->world, tx, ty,
					get_rgba(d->t->torch2->pixels[d->offset + 0],
						d->t->torch2->pixels[d->offset + 1],
						d->t->torch2->pixels[d->offset + 2],
						d->t->torch2->pixels[d->offset + 3]));
			tx++;
			d->offset += 4;
		}
		tx = 0;
		ty++;
	}
}

void	draw_torch3(t_data *d)
{
	int	ty;
	int	tx;

	ty = 0;
	tx = 0;
	d->offset = 0;
	while (ty < 200)
	{
		while (tx < 200)
		{
			if (d->t->torch3->pixels[d->offset + 0] != 0
				|| d->t->torch3->pixels[d->offset + 1] != 0
				|| d->t->torch3->pixels[d->offset + 2] != 0
				|| d->t->torch3->pixels[d->offset + 3] != 0)
				mlx_put_pixel(d->world, tx, ty,
					get_rgba(d->t->torch3->pixels[d->offset + 0],
						d->t->torch3->pixels[d->offset + 1],
						d->t->torch3->pixels[d->offset + 2],
						d->t->torch3->pixels[d->offset + 3]));
			tx++;
			d->offset += 4;
		}
		tx = 0;
		ty++;
	}
}

void	draw_torch4(t_data *d)
{
	int	ty;
	int	tx;

	ty = 0;
	tx = 0;
	d->offset = 0;
	while (ty < 200)
	{
		while (tx < 200)
		{
			if (d->t->torch4->pixels[d->offset + 0] != 0
				|| d->t->torch4->pixels[d->offset + 1] != 0
				|| d->t->torch4->pixels[d->offset + 2] != 0
				|| d->t->torch4->pixels[d->offset + 3] != 0)
				mlx_put_pixel(d->world, tx, ty,
					get_rgba(d->t->torch4->pixels[d->offset + 0],
						d->t->torch4->pixels[d->offset + 1],
						d->t->torch4->pixels[d->offset + 2],
						d->t->torch4->pixels[d->offset + 3]));
			tx++;
			d->offset += 4;
		}
		tx = 0;
		ty++;
	}
}
