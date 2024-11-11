/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:06:01 by mamazian          #+#    #+#             */
/*   Updated: 2024/10/25 16:47:57 by mamazian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	src_index;
	size_t	offset;
	size_t	dest_len;
	size_t	src_len;

	src_index = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	offset = dest_len;
	if (!dstsize || dstsize <= dest_len)
		return (src_len + dstsize);
	while (*(src + src_index) && offset < dstsize - 1)
	{
		*(dest + offset) = *(src + src_index);
		offset++;
		src_index++;
	}
	*(dest + offset) = '\0';
	return (dest_len + src_len);
}