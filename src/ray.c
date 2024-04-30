/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:32:54 by llai              #+#    #+#             */
/*   Updated: 2024/04/30 14:58:55 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ray.h"


t_ray	ray(t_tuple origin, t_tuple direction)
{
	t_ray r;

	r.origin = origin;
	r.direction = direction;
	return (r);
}

t_tuple	position(t_ray ray, double t)
{
	return (add_tuples(ray.origin, (scalar_mul_tuple(t, ray.direction))));
}

t_ray transform(t_ray r, t_matrix m)
{
    t_ray r2;

	r2.origin = matrix_tuple_multiply(m, r.origin);
	r2.direction = matrix_tuple_multiply(m, r.direction);
    return (r2);
}
