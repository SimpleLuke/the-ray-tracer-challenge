/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:55:50 by llai              #+#    #+#             */
/*   Updated: 2024/04/29 23:35:34 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

#include "tuples.h"
#include "ray.h"
#include "../libft/libft.h"

typedef struct s_tuple_list
{
	int		count;
	double	t1;
	double	t2;
}	t_tuple_list;

typedef struct s_shpere
{
	t_tuple	center;
	double	radius;
}	t_shpere;

typedef struct s_intersection
{
	double		t;
	t_shpere	object;
}	t_intersection;

t_shpere	shpere(t_tuple center, double radius);
// t_tuple_list intersect(t_shpere sphere, t_ray ray);
t_list *intersect(t_shpere sphere, t_ray ray);

#endif // !SHAPES_H
