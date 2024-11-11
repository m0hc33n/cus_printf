
#include "../inc/common.h"

/*
	# run : 
		## reset pfs to zero to overwrite previous info;
		## set new info;
		## print formatted value;
*/
static void	run(t_format_specifier *pfs, va_list args, char *f)
{
	while (*f)
	{
		if (*f != PERCENT)
			ft_putchar_fd(*f, STDOUT_FILENO);
		else
		{
			ft_memset(pfs, 0, sizeof(t_format_specifier) - sizeof(t_return));
			init_specifier(pfs, &f);
			print_arg(args, pfs);
			continue ;
		}
		pfs->ft_ret.ft_return++;
		f++;
	}
}

/*
	# ft_printf :
		## main func
		## iterate the format && if (specifter) -> run();
	# return :
		## number of characters written;
*/
int	ft_printf(const char *format, ...)
{
	char				*f;
	va_list				args;
	t_format_specifier	*pfs;
	int32_t				ret;

	va_start(args, format);
	f = (char *)format;
	pfs = (t_format_specifier *)malloc(sizeof(t_format_specifier));
	if (!pfs)
		return (-1);
	ft_memset(pfs, 0, sizeof(t_format_specifier));
	run(pfs, args, f);
	va_end(args);
	ret = pfs->ft_ret.ft_return;
	free(pfs);
	return (ret);
}
