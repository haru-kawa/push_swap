/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakawamo <hakawamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:03:05 by hakawamo          #+#    #+#             */
/*   Updated: 2024/10/22 17:08:31 by hakawamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i])
		i++;
	j = 0;
	if (size > 0)
	{
		while (src[j] && j < (size - 1))
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = 0;
	}
	return (i);
}
