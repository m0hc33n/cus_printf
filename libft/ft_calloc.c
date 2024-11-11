/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:31:56 by mamazian          #+#    #+#             */
/*   Updated: 2024/10/29 10:35:30 by mamazian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if ((int)count < 0 && (int)size < 0)
		return (0);
	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}
