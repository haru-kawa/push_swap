/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakawamo <hakawamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:01:00 by hakawamo          #+#    #+#             */
/*   Updated: 2024/10/22 17:15:30 by hakawamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(int n)
{
	size_t	digits;

	digits = 0;
	if (n < 0)
	{
		n = n * (-1);
		digits++;
	}
	if (n == 0)
		digits++;
	while (n > 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	size_t	digits;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digits = count_digits(n);
	str = (char *)malloc(sizeof(char) * (digits + 1));
	if (str == NULL)
		return (NULL);
	str[digits--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		n = n * (-1);
		str[0] = '-';
	}
	while (n > 0)
	{
		str[digits--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
