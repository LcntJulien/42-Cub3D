/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlence-l <nlence-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:18:53 by nlence-l          #+#    #+#             */
/*   Updated: 2023/12/31 15:38:31 by nlence-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	draw_line_ceil_check(t_point *pc1, t_point *pc2, t_data *d)
{
	d->dx = abs(pc2->x - pc1->x);
	if (pc1->x < pc2->x)
		d->sx = 1;
	else
		d->sx = -1;
	d->dy = -abs(pc2->y - pc1->y);
	if (pc1->y < pc2->y)
		d->sy = 1;
	else
		d->sy = -1;
	d->err = d->dx + d->dy;
}

void	draw_line_ceil(t_point *pc1, t_point *pc2, t_data *d)
{
	int	e2;

	draw_line_ceil_check(pc1, pc2, d);
	while (1)
	{
		if (pc1->x == pc2->x && pc1->y == pc2->y)
			break ;
		mlx_put_pixel(d->world, pc1->x, pc1->y,
			get_rgba(d->RC, d->GC, d->BC, d->TC));
		e2 = 2 * d->err;
		if (e2 >= d->dy)
		{
			d->err += d->dy;
			pc1->x += d->sx;
		}
		if (e2 <= d->dx)
		{
			d->err += d->dx;
			pc1->y += d->sy;
		}
	}
}

void	draw_line_floor_check(t_point *pf1, t_point *pf2, t_data *d)
{
	d->dx = abs(pf2->x - pf1->x);
	if (pf1->x < pf2->x)
		d->sx = 1;
	else
		d->sx = -1;
	d->dy = -abs(pf2->y - pf1->y);
	if (pf1->y < pf2->y)
		d->sy = 1;
	else
		d->sy = -1;
	d->err = d->dx + d->dy;
}

void	draw_line_floor(t_point *pf1, t_point *pf2, t_data *d)
{
	int	e2;

	draw_line_floor_check(pf1, pf2, d);
	while (1)
	{
		if (pf1->x == pf2->x && pf1->y == pf2->y)
			break ;
		mlx_put_pixel(d->world, pf1->x, pf1->y,
			get_rgba(d->RF, d->GF, d->BF, d->TF));
		e2 = 2 * d->err;
		if (e2 >= d->dy)
		{
			d->err += d->dy;
			pf1->x += d->sx;
		}
		if (e2 <= d->dx)
		{
			d->err += d->dx;
			pf1->y += d->sy;
		}
	}
}

float	dist(float ax, float ay, float bx, float by)
{
	float	res;

	res = sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
	return (res);
}
