/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlence-l <nlence-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:29:54 by nlence-l          #+#    #+#             */
/*   Updated: 2023/12/31 14:42:03 by nlence-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	init_texture(t_data *d)
{
	init_texture1(d);
	init_texture2(d);
	init_texture3(d);
	init_texture4(d);
}

void	init_texture1(t_data *d)
{
	mlx_texture_t	*temp;

	temp = mlx_load_png("./textures/eagle.png");
	if (!temp)
		error(d, 3);
	d->t->DO_img = mlx_texture_to_image(d->mlx, temp);
	if (!d->t->DO_img)
		error(d, 3);
	mlx_delete_texture(temp);
	temp = mlx_load_png(d->t->NO_path);
	if (!temp)
		error(d, 4);
	d->t->NO_img = mlx_texture_to_image(d->mlx, temp);
	if (!d->t->NO_img)
		error(d, 4);
	mlx_delete_texture(temp);
	temp = mlx_load_png(d->t->SO_path);
	if (!temp)
		error(d, 5);
	d->t->SO_img = mlx_texture_to_image(d->mlx, temp);
	if (!d->t->SO_img)
		error(d, 5);
	mlx_delete_texture(temp);
}

void	init_texture2(t_data *d)
{
	mlx_texture_t	*temp;

	temp = mlx_load_png("./textures/torch.png");
	if (!temp)
		error(d, 6);
	d->t->torch = mlx_texture_to_image(d->mlx, temp);
	if (!d->t->torch)
		error(d, 6);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./textures/torch1.png");
	if (!temp)
		error(d, 7);
	d->t->torch1 = mlx_texture_to_image(d->mlx, temp);
	if (!d->t->torch1)
		error(d, 7);
	mlx_delete_texture(temp);
	temp = mlx_load_png(d->t->WE_path);
	if (!temp)
		error(d, 8);
	d->t->WE_img = mlx_texture_to_image(d->mlx, temp);
	if (!d->t->WE_img)
		error(d, 8);
	mlx_delete_texture(temp);
}

void	init_texture3(t_data *d)
{
	mlx_texture_t	*temp;

	temp = mlx_load_png("./textures/torch2.png");
	if (!temp)
		error(d, 9);
	d->t->torch2 = mlx_texture_to_image(d->mlx, temp);
	if (!d->t->torch2)
		error(d, 9);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./textures/torch3.png");
	if (!temp)
		error(d, 10);
	d->t->torch3 = mlx_texture_to_image(d->mlx, temp);
	if (!d->t->torch3)
		error(d, 10);
	mlx_delete_texture(temp);
}

void	init_texture4(t_data *d)
{
	mlx_texture_t	*temp;

	temp = mlx_load_png(d->t->EA_path);
	if (!temp)
		error(d, 11);
	d->t->EA_img = mlx_texture_to_image(d->mlx, temp);
	if (!d->t->EA_img)
		error(d, 11);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./textures/torch4.png");
	if (!temp)
		error(d, 12);
	d->t->torch4 = mlx_texture_to_image(d->mlx, temp);
	if (!d->t->torch4)
		error(d, 12);
	mlx_delete_texture(temp);
}
