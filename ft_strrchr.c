/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabahass <sabahass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 23:07:45 by sabahass          #+#    #+#             */
/*   Updated: 2025/08/17 23:53:06 by sabahass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	last;

	last = ft_strlen(s);
	while (last >= 0)
	{
		if (s[last] == (char)c)
			return ((char *)(s + last));
		last--;
	}
	return (NULL);
}
