
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
