/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakawamo <hakawamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:02:42 by hakawamo          #+#    #+#             */
/*   Updated: 2025/07/07 05:02:52 by hakawamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_split(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	if (s[i] == '\0')
		return (0);
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	**split_words(char **split, char const *s, char c)
{
	size_t	split_len;
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != '\0')
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			split_len = i - start;
			split[j++] = ft_substr(s, start, split_len);
		}
	}
	split[j] = NULL;
	return (split);
}

void	free_split(char **split, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	**result;

	if (s == NULL)
		return (NULL);
	split = (char **)malloc((sizeof(char *) * (ft_count_split(s, c) + 1)));
	if (split == NULL)
		return (NULL);
	result = split_words(split, s, c);
	if (!result)
	{
		free_split(split, ft_count_split(s, c));
		return (NULL);
	}
	return (result);
}
