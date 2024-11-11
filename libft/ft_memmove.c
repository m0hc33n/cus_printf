/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:03:38 by mamazian          #+#    #+#             */
/*   Updated: 2024/10/25 11:59:00 by mamazian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (dst < src)
	{
		ft_memcpy(dst, src, n);
	}
	else if (dst > src)
	{
		while (n--)
		{
			*(unsigned char *)(dst + n) = *(unsigned char *)(src + n);
		}
	}
	return (dst);
}
