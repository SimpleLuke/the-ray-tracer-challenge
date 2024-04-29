/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:43:24 by llai              #+#    #+#             */
/*   Updated: 2024/04/29 21:06:08 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt.h"
#include <stdio.h>

void	test1(void)
{
	t_matrix	M1 = create_matrix(4, 4);
	t_matrix	M2 = create_matrix(4, 4);

	M1.data[0][0] = 1;
	M1.data[0][1] = 2;
	M1.data[0][2] = 3;
	M1.data[0][3] = 4;
	M1.data[1][0] = 5;
	M1.data[1][1] = 6;
	M1.data[1][2] = 7;
	M1.data[1][3] = 8;
	M1.data[2][0] = 9;
	M1.data[2][1] = 8;
	M1.data[2][2] = 7;
	M1.data[2][3] = 6;
	M1.data[3][0] = 5;
	M1.data[3][1] = 4;
	M1.data[3][2] = 3;
	M1.data[3][3] = 2;

	M2.data[0][0] = -2;
	M2.data[0][1] = 1;
	M2.data[0][2] = 2;
	M2.data[0][3] = 3;
	M2.data[1][0] = 3;
	M2.data[1][1] = 2;
	M2.data[1][2] = 1;
	M2.data[1][3] = -1;
	M2.data[2][0] = 4;
	M2.data[2][1] = 3;
	M2.data[2][2] = 6;
	M2.data[2][3] = 5;
	M2.data[3][0] = 1;
	M2.data[3][1] = 2;
	M2.data[3][2] = 7;
	M2.data[3][3] = 8;

	t_matrix M3 = matrix_multiply(M1, M2);
	print_matrix(M3);
}

void	test2(void)
{
	t_matrix	M1 = create_matrix(4, 4);

	M1.data[0][0] = 1;
	M1.data[0][1] = 2;
	M1.data[0][2] = 3;
	M1.data[0][3] = 4;
	M1.data[1][0] = 2;
	M1.data[1][1] = 4;
	M1.data[1][2] = 4;
	M1.data[1][3] = 2;
	M1.data[2][0] = 8;
	M1.data[2][1] = 6;
	M1.data[2][2] = 4;
	M1.data[2][3] = 1;
	M1.data[3][0] = 0;
	M1.data[3][1] = 0;
	M1.data[3][2] = 0;
	M1.data[3][3] = 1;
	t_tuple b = point(1, 2, 3);
	t_tuple a = matrix_tuple_multiply(M1, b);
	print_tuple(a);
}

void	test3(void)
{
	t_matrix	M1 = create_matrix(4, 4);

	M1.data[0][0] = 0;
	M1.data[0][1] = 9;
	M1.data[0][2] = 3;
	M1.data[0][3] = 0;
	M1.data[1][0] = 9;
	M1.data[1][1] = 8;
	M1.data[1][2] = 0;
	M1.data[1][3] = 8;
	M1.data[2][0] = 1;
	M1.data[2][1] = 8;
	M1.data[2][2] = 5;
	M1.data[2][3] = 3;
	M1.data[3][0] = 0;
	M1.data[3][1] = 0;
	M1.data[3][2] = 5;
	M1.data[3][3] = 8;

	t_matrix res = transpose(M1);
	print_matrix(res);
}

void	test4(void)
{
	t_matrix	M1 = create_matrix(3, 3);

	M1.data[0][0] = 3;
	M1.data[0][1] = 5;
	M1.data[0][2] = 0;
	M1.data[1][0] = 2;
	M1.data[1][1] = -1;
	M1.data[1][2] = -7;
	M1.data[2][0] = 6;
	M1.data[2][1] = -1;
	M1.data[2][2] = 5;

	t_matrix B = submatrix(M1, 1, 0);
	printf("dom: %.2f\n", determinant(B));
	printf("min: %.2f\n", minor(M1, 1, 0));
	printf("co1: %.2f\n", cofactor(M1, 0, 0));
	printf("co1: %.2f\n", cofactor(M1, 1, 0));
}

void	test5(void)
{
	t_matrix	M1 = create_matrix(4, 4);

	M1.data[0][0] = -2;
	M1.data[0][1] = -8;
	M1.data[0][2] = 3;
	M1.data[0][3] = 5;
	M1.data[1][0] = -3;
	M1.data[1][1] = 1;
	M1.data[1][2] = 7;
	M1.data[1][3] = 3;
	M1.data[2][0] = 1;
	M1.data[2][1] = 2;
	M1.data[2][2] = -9;
	M1.data[2][3] = 6;
	M1.data[3][0] = -6;
	M1.data[3][1] = 7;
	M1.data[3][2] = 7;
	M1.data[3][3] = -9;

	printf("co: %.2f\n", cofactor(M1, 0, 0));
	printf("co: %.2f\n", cofactor(M1, 0, 1));
	printf("co: %.2f\n", cofactor(M1, 0, 2));
	printf("co: %.2f\n", cofactor(M1, 0, 3));
	printf("det: %.2f\n", determinant(M1));
}

void	test6(void)
{
	t_matrix	M1 = create_matrix(4, 4);

	M1.data[0][0] = -5;
	M1.data[0][1] = 2;
	M1.data[0][2] = 6;
	M1.data[0][3] = -8;
	M1.data[1][0] = 1;
	M1.data[1][1] = -5;
	M1.data[1][2] = 1;
	M1.data[1][3] = 8;
	M1.data[2][0] = 7;
	M1.data[2][1] = 7;
	M1.data[2][2] = -6;
	M1.data[2][3] = -7;
	M1.data[3][0] = 1;
	M1.data[3][1] = -3;
	M1.data[3][2] = 7;
	M1.data[3][3] = 4;

	t_matrix res = inverse(M1);
	print_matrix(res);
}

void	test7(void)
{
	t_matrix	M1 = create_matrix(4, 4);

	M1.data[0][0] = 9;
	M1.data[0][1] = 3;
	M1.data[0][2] = 0;
	M1.data[0][3] = 9;
	M1.data[1][0] = -5;
	M1.data[1][1] = -2;
	M1.data[1][2] = -6;
	M1.data[1][3] = -3;
	M1.data[2][0] = -4;
	M1.data[2][1] = 9;
	M1.data[2][2] = 6;
	M1.data[2][3] = 4;
	M1.data[3][0] = -7;
	M1.data[3][1] = 6;
	M1.data[3][2] = 6;
	M1.data[3][3] = 2;

	t_matrix res = inverse(M1);
	print_matrix(res);
}

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
	// test1();
	// test2();
	// test3();
	// test4();
	// test5();
	// test6();
	test7();

	put_pixel(data.base_image, 0, 0, color(0, 1, 0, 0));
	mlx_put_image_to_window(data.base_image.win.mlx,
		data.base_image.win.win_ptr, data.base_image.img_ptr, 0, 0);
	mlx_hook(win.win_ptr, 2, 1L << 0, esc_close_win, &data);
	mlx_hook(win.win_ptr, 17, 0, cross_close_win, &data);
	mlx_loop(data. base_image.win.mlx);
}
