/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabahass <sabahass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:47:30 by sabahass          #+#    #+#             */
/*   Updated: 2025/07/21 17:54:59 by sabahass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t num_bytes)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;

	if (destination == NULL && source == NULL)
		return (NULL);
	dest_ptr = (unsigned char *)destination;
	src_ptr = (const unsigned char *)source;
	while (num_bytes > 0)
	{
		*dest_ptr = *src_ptr;
		dest_ptr++;
		src_ptr++;
		num_bytes--;
	}
	return (destination);
}