/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_vec2_transform.c                                :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/12/16 00:00:00 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/16 00:00:00 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

t_vec2	ft_vec2_lerp(t_vec2 a, t_vec2 b, double t)
{
	t_vec2	result;

	result.x = a.x + t * (b.x - a.x);
	result.y = a.y + t * (b.y - a.y);
	return (result);
}

t_vec2	ft_vec2_rotate(t_vec2 v, double angle)
{
	t_vec2	result;
	double	c;
	double	s;

	c = cos(angle);
	s = sin(angle);
	result.x = v.x * c - v.y * s;
	result.y = v.x * s + v.y * c;
	return (result);
}
