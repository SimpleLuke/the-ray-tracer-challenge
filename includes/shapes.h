/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:55:50 by llai              #+#    #+#             */
/*   Updated: 2024/04/30 15:51:48 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

#include "matrix.h"
#include "tuples.h"
#include "ray.h"
#include "../libft/libft.h"

typedef struct s_tuple_list
{
	int		count;
	double	t1;
	double	t2;
}	t_tuple_list;

typedef struct s_sphere
{
	t_tuple	center;
	double	radius;
	t_matrix	transform;
}	t_sphere;

typedef struct s_intersection
{
	double		t;
	t_sphere	object;
}	t_intersection;

t_sphere		sphere(t_tuple center, double radius);
void			set_transform(t_sphere *shpere, t_matrix t);
// t_tuple_list intersect(t_shpere sphere, t_ray ray);
t_intersection	*intersection(double t, t_sphere object);
t_list			*intersect(t_sphere sphere, t_ray ray);
t_intersection	*hit(t_list *xs);

#endif // !SHAPES_H
