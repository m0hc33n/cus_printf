
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if ((unsigned char)c == *(unsigned char *)s)
		{
			return ((void *)s);
		}
		s++;
	}
	return (0);
}
