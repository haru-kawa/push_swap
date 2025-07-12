/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakawamo <hakawamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:03:27 by hakawamo          #+#    #+#             */
/*   Updated: 2024/10/22 16:40:31 by hakawamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	head;
	size_t	tail;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	head = 0;
	while (s1[head] != '\0' && ft_find_set(s1[head], set))
		head++;
	tail = ft_strlen(s1);
	while (tail > head && ft_find_set(s1[tail - 1], set))
		tail--;
	str = ft_substr(s1, head, tail - head);
	if (str == NULL)
		return (NULL);
	return (str);
}
