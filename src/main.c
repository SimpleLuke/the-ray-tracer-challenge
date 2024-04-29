/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:43:24 by llai              #+#    #+#             */
/*   Updated: 2024/04/29 23:40:37 by llai             ###   ########.fr       */
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

void	test8(void)
{
	// t_tuple	p = point(-3, 4, 5);
	t_tuple	v = vector(-3, 4, 5);
	t_matrix	t = translation(5, -3, 2);
	
	// t = inverse(t);

	t_tuple	res = matrix_tuple_multiply(t, v);
	print_tuple(res);
}

void	test9(void)
{
	// t_tuple p = point(2, 3, 4);
	t_tuple v = vector(-4, 6, 8);
	t_matrix t = scaling(2, 3, 4);

	t = inverse(t);
	t_tuple res = matrix_tuple_multiply(t, v);
	print_tuple(res);
}

void	test10(void)
{
	t_tuple	p = point(0, 1, 0);

	t_matrix	t = rotation_x(M_PI / 4);
	t = inverse(t);
	t_tuple res = matrix_tuple_multiply(t, p);
	print_tuple(res);
}

void	test11(void)
{
	t_tuple	p = point(0, 0, 1);

	t_matrix	t = rotation_y(M_PI / 4);
	t_tuple res = matrix_tuple_multiply(t, p);
	print_tuple(res);
}

void	test12(void)
{
	t_tuple	p = point(0, 1, 0);

	t_matrix	t = rotation_z(M_PI / 4);
	t_tuple res = matrix_tuple_multiply(t, p);
	print_tuple(res);
}

void	test13(void)
{
	t_tuple	p = point(2, 3, 4);

	t_matrix	t = shearing(0, 1, 0, 0, 0, 0);
	t_tuple res = matrix_tuple_multiply(t, p);
	print_tuple(res);
}

void	print_clock(t_data *data)
{
	// double radius = 100.0;
	t_tuple	p = point(0, 0, 0);

    // Calculate the angle between each hour (in radians)
    double hourAngle = 2 * M_PI / 12;

    // Apply transformations for each hour
    for (int hour = 0; hour < 12; hour++) {
        // Calculate the rotation angle for the current hour
        double angle = hour * hourAngle;

        // Create the rotation matrix for the current hour
        t_matrix rotation = rotation_z(angle);
		t_matrix translate = translation(0, 100, 0);

        // Transform the center point using the rotation matrix
        t_tuple rotatedPoint = matrix_tuple_multiply(rotation, matrix_tuple_multiply(translate, p));
		print_tuple(rotatedPoint);
		put_pixel(data->base_image, rotatedPoint.x, rotatedPoint.y, color(0, 1, 0, 0));
	}
}

void	test14(void)
{
	t_ray r = ray(point(1, 2, 3), vector(4, 5, 6));
	print_tuple(r.origin);
	print_tuple(r.direction);
}

void	test15(void)
{
	t_ray	r = ray(point(2, 3, 4), vector(1, 0, 0));
	print_tuple(position(r, 0));
	print_tuple(position(r, 1));
	print_tuple(position(r, -1));
	print_tuple(position(r, 2.5));
}

// void	test16(void)
// {
// 	t_ray	r = ray(point(0, 0, -5), vector(0, 0, 1));
// 	t_shpere	s = shpere(point(0, 0, 0), 1);
// 	// t_tuple_list xs = intersect(s, r);
//
// 	printf("xs: count: %d 0: %f 1:%f\n", xs.count, xs.t1, xs.t2);
// }

void	test17(void)
{
	t_ray	r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_shpere	s = shpere(point(0, 0, 0), 1);
	// t_tuple_list xs = intersect(s, r);
	t_list *xs = intersect(s, r);

	// printf("xs: count: %d 0: %f 1:%f\n", xs.count, xs.t1, xs.t2);
	printf("count: %d\n",ft_lstsize(xs));
	while (xs != NULL)
	{
		t_intersection	*i = xs->content;
		printf("t: %f\n", i->t);
		xs = xs->next;
	}
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
	// test7();
	// test8();
	// test9();
	// test10();
	// test11();
	// test12();
	// test13();
	// print_clock(&data);
	// test14();
	// test15();
	// test16();
	test17();

	put_pixel(data.base_image, 0, 0, color(0, 1, 0, 0));

	mlx_put_image_to_window(data.base_image.win.mlx,
		data.base_image.win.win_ptr, data.base_image.img_ptr, 0, 0);
	mlx_hook(win.win_ptr, 2, 1L << 0, esc_close_win, &data);
	mlx_hook(win.win_ptr, 17, 0, cross_close_win, &data);
	mlx_loop(data. base_image.win.mlx);
}
