/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_vec3_transform.c                                :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/12/16 00:00:00 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/16 00:00:00 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec3	ft_vec3_lerp(t_vec3 a, t_vec3 b, double t)
{
	t_vec3	result;

	result.x = a.x + t * (b.x - a.x);
	result.y = a.y + t * (b.y - a.y);
	result.z = a.z + t * (b.z - a.z);
	return (result);
}

t_vec3	ft_vec3_reflect(t_vec3 v, t_vec3 normal)
{
	double	d;

	d = 2.0 * ft_vec3_dot(v, normal);
	return (ft_vec3_sub(v, ft_vec3_scale(normal, d)));
}
