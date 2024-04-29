/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:57:41 by llai              #+#    #+#             */
/*   Updated: 2024/04/29 23:06:48 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shapes.h"
#include "../includes/ray.h"
#include <math.h>

t_tuple_list	tuple_list(int count, double t1, double t2)
{
	return ((t_tuple_list){count, t1, t2});
}

t_shpere	shpere(t_tuple center, double radius)
{
	t_shpere	s;

	s.center = center;
	s.radius = radius;
	return (s);
}

t_tuple_list intersect(t_shpere sphere, t_ray ray) {
    // Calculate the vector from the sphere's center to the ray origin
    t_tuple sphere_to_ray = sub_tuples(ray.origin, sphere.center);

    // Calculate coefficients for quadratic equation
    double a = dot(ray.direction, ray.direction);
    double b = 2 * dot(ray.direction, sphere_to_ray);
    double c = dot(sphere_to_ray, sphere_to_ray) - (sphere.radius * sphere.radius);

    // Calculate the discriminant
    double discriminant = b * b - 4 * a * c;

    // If the discriminant is negative, the ray misses the sphere
    if (discriminant < 0) {
        return tuple_list(true, -1, -1); // Return an empty list
    }

    // Calculate the intersections
    double t1 = (-b - sqrt(discriminant)) / (2 * a);
    double t2 = (-b + sqrt(discriminant)) / (2 * a);

    // Return the intersections in increasing order
    return tuple_list(2, t1, t2); // Assuming tuple_list creates a list of tuples
}
