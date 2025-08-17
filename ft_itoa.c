/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabahass <sabahass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 00:07:40 by sabahass          #+#    #+#             */
/*   Updated: 2025/08/17 23:53:52 by sabahass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	fill_number(char *str, int n, int len, int is_negative)
{
	int	i;

	if (is_negative)
		n = -n;
	i = len - 1;
	while (i >= is_negative)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	if (is_negative)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	int		len;
	char	*s;
	int		is_negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_negative = (n < 0);
	len = get_len(n);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[len] = '\0';
	fill_number(s, n, len, is_negative);
	return (s);
}
