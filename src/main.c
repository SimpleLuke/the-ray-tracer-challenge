/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:43:24 by llai              #+#    #+#             */
/*   Updated: 2024/04/29 15:47:42 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt.h"

int	main(void)
{
	t_data	data;
	t_win	win;

	data.base_image.win = new_window(WIDTH, HEIGHT, "miniRT");
	win = data.base_image.win;
	data.base_image = new_img(WIDTH, HEIGHT, data.base_image.win);

	// t_tuple	v1 = {1, 2, 3, VECTOR};
	// t_tuple	v2 = {2, 3, 4, VECTOR};
	// t_tuple norm = normalize(v1);
	// printf("vec: x:%f y:%f z:%f\n", norm.x, norm.y, norm.z);
	// printf("dot: %f\n", dot(v1, v2));
	// t_tuple	res = cross(v1, v2);
	// t_tuple	res = cross(v2, v1);
	// printf("vec: x:%f y:%f z:%f\n", res.x, res.y, res.z);

	put_pixel(data.base_image, 0, 0, color(0, 1, 0, 0));
	mlx_put_image_to_window(data.base_image.win.mlx,
		data.base_image.win.win_ptr, data.base_image.img_ptr, 0, 0);
	mlx_hook(win.win_ptr, 2, 1L << 0, esc_close_win, &data);
	mlx_hook(win.win_ptr, 17, 0, cross_close_win, &data);
	mlx_loop(data. base_image.win.mlx);
}
