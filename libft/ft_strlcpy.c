/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:05:26 by mamazian          #+#    #+#             */
/*   Updated: 2024/10/25 16:48:03 by mamazian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;
	char	*s;

	i = 0;
	s = (char *)src;
	src_len = ft_strlen(src);
	while (dstsize != 0 && i < dstsize - 1 && *(s + i))
	{
		*(dst + i) = *(s + i);
		i++;
	}
	if (dstsize != 0)
		*(dst + i) = '\0';
	return (src_len);
}