/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:44:10 by mamazian          #+#    #+#             */
/*   Updated: 2024/10/25 16:46:02 by mamazian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	size;
	char			*pbytes;
	size_t			i;

	size = ft_strlen(s) + 1;
	i = 0;
	pbytes = (char *)malloc(size);
	if (!pbytes)
		return (0);
	while (s[i])
	{
		pbytes[i] = s[i];
		i++;
	}
	pbytes[i] = '\0';
	return (pbytes);
}
