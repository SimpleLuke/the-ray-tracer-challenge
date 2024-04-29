/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llai <llai@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:22:50 by llai              #+#    #+#             */
/*   Updated: 2024/04/29 15:35:29 by llai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
#define COLOR_H

typedef struct s_color
{
	double	transparent;
	double	red;
	double	green;
	double	blue;
}	t_color;

t_color	color(double transparent, double red, double green, double blue);
t_color	add_colors(t_color c1, t_color c2);
t_color	sub_colors(t_color c1, t_color c2);
t_color	mul_color(t_color c, double scalar);
t_color	hadamard_product(t_color c1, t_color c2);

#endif // !COLOR_H
