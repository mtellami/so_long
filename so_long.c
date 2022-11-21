/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:17:37 by mtellami          #+#    #+#             */
/*   Updated: 2022/11/20 16:15:07 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

int main(int ac, char **av)
{
	t_game	*so_long;
	t_map	*map;

	if (ac != 2)
	{
		invalid_number_of_argument();
		return (0);
	}
	map = map_render(av[1]);
	if(!map)
	{
		fail_rendering_map();
		return (0);
	}
	so_long = setting_up(map);
	display(so_long);
	mlx_key_hook(so_long->win, &event, so_long);
	mlx_loop(so_long->mlx);
}
