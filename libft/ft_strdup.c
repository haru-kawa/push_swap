/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakawamo <hakawamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:02:50 by hakawamo          #+#    #+#             */
/*   Updated: 2024/10/22 16:20:34 by hakawamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	s_length;
	char	*sc;

	s_length = ft_strlen(s) + 1;
	sc = (char *)malloc(sizeof(*s) * s_length);
	if (sc == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		sc[i] = s[i];
		i++;
	}
	sc[i] = 0;
	return (sc);
}
