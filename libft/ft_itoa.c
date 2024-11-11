
#include "libft.h"

static int	get_len(int n)
{
	int	count;

	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	copy_digits(char *d, long long n)
{
	if (n <= 9)
		*d = n + 48;
	else
	{
		*d = n % 10 + 48;
		copy_digits(d - 1, n / 10);
	}
}

char	*ft_itoa(int n)
{
	char		*digits;
	int			len;
	long long	long_nbr;

	if (!n)
		return (ft_strdup("0"));
	len = get_len(n);
	if (n < 0)
	{
		long_nbr = n ;
		long_nbr *= -1;
		len++;
	}
	else
		long_nbr = n;
	digits = (char *)malloc(len + 1);
	if (!digits)
		return (0);
	copy_digits(digits + len - 1, long_nbr);
	if (n < 0)
		*digits = '-';
	digits[len] = '\0';
	return (digits);
}
