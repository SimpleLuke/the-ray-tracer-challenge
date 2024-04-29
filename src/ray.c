/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:32:54 by llai              #+#    #+#             */
/*   Updated: 2024/04/29 23:06:40 by llai             ###   ########.fr       */
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
