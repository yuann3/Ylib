/* ************************************************************************** */
/*                                                                            */
/*                                                          :::      ::::::   */
/*   ft_vec3_norm.c                                     :+:      :+:    :+:   */
/*                                                  +:+ +:+           +:+     */
/*   By: yiyuli <yy@eyuan.me>                     +#+  +:+         +#+        */
/*                                              +#+#+#+#+#+      +#+          */
/*   Created: 2025/12/16 00:00:00 by yiyuli           #+#      #+#            */
/*   Updated: 2025/12/16 00:00:00 by yiyuli         ###      ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define FT_EPSILON 1e-10

t_vec3	ft_vec3_norm(t_vec3 v)
{
	double	len;
	t_vec3	result;

	len = ft_vec3_len(v);
	if (len < FT_EPSILON && len > -FT_EPSILON)
		return (ft_vec3_new(0, 0, 0));
	result.x = v.x / len;
	result.y = v.y / len;
	result.z = v.z / len;
	return (result);
}
