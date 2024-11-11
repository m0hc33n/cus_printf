
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	if (*needle == '\0')
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (*haystack && needle_len <= len && len--)
	{
		if ((*haystack == *needle) && !ft_strncmp(haystack, needle, needle_len))
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
