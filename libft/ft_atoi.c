
#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	check(const char *start, int len)
{
	char	*max;

	max = "9223372036854775807";
	while (*start == '0')
	{
		start++;
		len--;
	}
	if (len > 19)
		return (0);
	else if (len < 19)
		return (1);
	if (ft_strncmp(start, max, len) > 0)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	res;
	char		*start;

	res = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	start = (char *)str;
	while (ft_isdigit(*str))
	{
		res = (*str - '0') + (res * 10);
		str++;
	}
	if (!check(start, str - start) && sign == 1)
		return (-1);
	else if (!check(start, str - start) && sign == -1)
		return (0);
	return (res * sign);
}
