/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_vec2_ops.c                                      :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/12/16 00:00:00 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/16 00:00:00 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

#define FT_EPSILON 1e-10

double	ft_vec2_dot(t_vec2 a, t_vec2 b)
{
	return (a.x * b.x + a.y * b.y);
}

double	ft_vec2_len(t_vec2 v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}

double	ft_vec2_len_sq(t_vec2 v)
{
	return (v.x * v.x + v.y * v.y);
}

t_vec2	ft_vec2_norm(t_vec2 v)
{
	double	len;
	t_vec2	result;

	len = ft_vec2_len(v);
	if (len < FT_EPSILON && len > -FT_EPSILON)
		return (ft_vec2_new(0, 0));
	result.x = v.x / len;
	result.y = v.y / len;
	return (result);
}

double	ft_vec2_dist(t_vec2 a, t_vec2 b)
{
	return (ft_vec2_len(ft_vec2_sub(b, a)));
}
