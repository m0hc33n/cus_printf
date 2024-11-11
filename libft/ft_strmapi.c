
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			slen;
	unsigned int	i;
	char			*ret;

	if (!s || !f)
		return (0);
	slen = ft_strlen(s);
	ret = (char *)malloc(slen + 1);
	if (!ret)
		return (0);
	i = 0;
	while (s[i])
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
