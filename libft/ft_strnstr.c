/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakawamo <hakawamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:03:20 by hakawamo          #+#    #+#             */
/*   Updated: 2024/10/22 16:39:37 by hakawamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;

	if (needle[0] == '\0')
		return ((char *)(haystack));
	i = 0;
	n_len = ft_strlen(needle);
	while (i < len && haystack[i] != 0)
	{
		if (haystack[i] == needle[0])
		{
			if (n_len > len - i)
				return (NULL);
			if (ft_strncmp(&haystack[i], needle, n_len) == 0)
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
