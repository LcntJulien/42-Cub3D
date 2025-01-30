/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlecorne <jlecorne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:18:27 by nlence-l          #+#    #+#             */
/*   Updated: 2024/01/08 22:35:35 by jlecorne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	error(t_data *d, int i)
{
	if (i == 0)
		printf("\033[31mError\033[0m\n\033[90mCannot allocate space\033[0m\n");
	else
		printf("%s\n", mlx_strerror(mlx_errno));
	free_data(d, i);
	exit(1);
}

void	draw_sprite(t_data *d)
{
	float	time;
	float	elapsed_time;

	time = mlx_get_time();
	elapsed_time = time - d->time;
	if (elapsed_time >= 0.0 && elapsed_time < 0.2)
		draw_torch(d);
	else if (elapsed_time >= 0.2 && elapsed_time < 0.4)
		draw_torch1(d);
	else if (elapsed_time >= 0.4 && elapsed_time < 0.6)
		draw_torch2(d);
	else if (elapsed_time >= 0.6 && elapsed_time < 0.8)
		draw_torch3(d);
	else if (elapsed_time >= 0.8 && elapsed_time < 1.0)
	{
		draw_torch4(d);
		d->time = mlx_get_time();
	}
}

void	open_doors(t_data *d)
{
	int	xo;
	int	yo;

	if (mlx_is_key_down(d->mlx, MLX_KEY_F))
	{
		if (d->pdx < 0)
			xo = -25;
		else
			xo = 25;
		if (d->pdy < 0)
			yo = -25;
		else
			yo = 25;
		if (d->map[(int)((d->py + yo) / 64.0)*d->mapWidth
			+ (int)((d->px - xo) / 64.0)] == '4')
			d->map[(int)((d->py + yo) / 64.0)*d->mapWidth
				+ (int)((d->px - xo) / 64.0)] = '0';
	}
}

void	move_player(void *param)
{
	t_data	*d;

	d = param;
	if (mlx_is_key_down(d->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(d->mlx);
	open_doors(d);
	move_forward(d);
	move_backwards(d);
	move_left(d);
	move_right(d);
	change_player_direction(d);
	draw_map(d);
	draw_rays(d);
	draw_minimap(d);
	draw_player(d);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	draw_sprite(d);
}

int	main(int ac, char **av)
{
	t_data	d;

	check_cub(ac, av[1]);
	init_cub(&d, av[1]);
	init_data(&d);
	init_texture(&d);
	mlx_loop_hook(d.mlx, move_player, &d);
	mlx_loop(d.mlx);
	free_data(&d, 13);
	return (EXIT_SUCCESS);
}
