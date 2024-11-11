/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:57:11 by mamazian          #+#    #+#             */
/*   Updated: 2024/10/25 15:16:09 by mamazian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	slen1;
	size_t	slen2;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	str = (char *)malloc(slen1 + slen2 + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s1, slen1 + 1);
	ft_strlcat(str + slen1, s2, slen2 + 1);
	return (str);
}
