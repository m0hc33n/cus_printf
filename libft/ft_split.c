/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:14:55 by mamazian          #+#    #+#             */
/*   Updated: 2024/10/25 16:45:33 by mamazian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char sep)
{
	size_t	count;
	int		flag;

	flag = 0;
	count = 0;
	while (*s)
	{
		if (*s != sep && !flag)
		{
			count++;
			flag = 1;
		}
		else if (*s == sep)
			flag = 0;
		s++;
	}
	return (count);
}

static char	*copy_word(const char *s, char c)
{
	size_t	len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(len + 1);
	if (!word)
		return (0);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

static void	free_result(char **result)
{
	size_t	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	size_t	i;
	char	**result;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (0);
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		result[i] = copy_word(s, c);
		if (!result[i])
			return (free_result(result), NULL);
		s += ft_strlen(result[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}
