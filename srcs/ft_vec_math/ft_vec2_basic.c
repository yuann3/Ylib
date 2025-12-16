/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_vec2_basic.c                                    :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/12/16 13:30:10 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/16 13:30:18 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec2	ft_vec2_new(double x, double y)
{
	t_vec2	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_vec2	ft_vec2_add(t_vec2 a, t_vec2 b)
{
	t_vec2	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return (result);
}

t_vec2	ft_vec2_sub(t_vec2 a, t_vec2 b)
{
	t_vec2	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	return (result);
}

t_vec2	ft_vec2_scale(t_vec2 v, double s)
{
	t_vec2	result;

	result.x = v.x * s;
	result.y = v.y * s;
	return (result);
}
