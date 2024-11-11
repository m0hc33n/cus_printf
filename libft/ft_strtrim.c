
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	char	*end;
	size_t	len;

	if (!s1 && !set)
		return (0);
	if (!set && s1)
		return ((char *)s1);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	end = (char *)s1 + len;
	while (end > s1 && ft_strchr(set, *(end - 1)))
		end--;
	len = end - s1;
	if (!len)
		return (ft_strdup(""));
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1, len + 1);
	return (ptr);
}
