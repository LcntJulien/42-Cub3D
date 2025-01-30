/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:17:58 by nlence-l          #+#    #+#             */
/*   Updated: 2023/12/19 14:30:41 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	draw_rays_init(t_data *d)
{
	d->dof = 0;
	d->disH = 1000000;
	d->hx = d->px;
	d->hy = d->py;
	d->aTan = -1 / tan(d->ra);
}

void	draw_rays_init2(t_data *d)
{
	d->dof = 0;
	d->disV = 1000000;
	d->vx = d->px;
	d->vy = d->py;
	d->nTan = -tan(d->ra);
}

void	init_for_textures(t_data *d)
{
	d->ca = d->pa - d->ra;
	reset_pi(&d->ca);
	d->disT = d->disT * cos(d->ca);
	d->lineH = (d->squareSize * HEIGHT) / d->disT;
	d->ty_step = 32.0 / d->lineH;
	d->ty_off = 0;
}

void	checks_for_textures(t_data *d)
{
	if (d->lineH > HEIGHT)
	{
		d->ty_off = (d->lineH - HEIGHT) / 2.0;
		d->lineH = HEIGHT;
	}
	d->lineO = (HEIGHT / 2) - d->lineH / 2;
	d->ty = d->ty_off * d->ty_step;
	if (d->vertical)
	{
		d->tx = (int)(d->ry / 2.0) % 32;
		if (d->ra > 90 && d->ra < 270)
			d->tx = 31 - d->tx;
	}
	else
	{
		d->tx = (int)(d->rx / 2.0) % 32;
		if (d->ra > 180)
			d->tx = 31 - d->tx;
	}
}

void	check_wall_hit(t_data *d)
{
	d->vertical = 1;
	d->north = 1;
	d->east = 1;
	if (d->disV < d->disH)
	{
		if (d->vx < d->px)
			d->east = 0;
		d->rx = d->vx;
		d->ry = d->vy;
		d->disT = d->disV;
	}
	if (d->disH < d->disV)
	{
		if (d->hy < d->py)
			d->north = 0;
		d->vertical = 0;
		d->rx = d->hx;
		d->ry = d->hy;
		d->disT = d->disH;
	}
}
