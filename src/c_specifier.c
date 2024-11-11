
#include "../inc/common.h"

/*
	# set_padded_c :
		## print value with padding if set
	# cs_pad_handle :
		## handle the padding either spaces or zeros
	# ft_return : 
		## pad_len + 1 (len of the char) --> total len of the writen bytes
	## `sign_handle(pfs)`
		## this handle sign when c_handle is space
	
*/

static void	set_padded_c(char value, t_format_specifier *pfs)
{
	int32_t	pad_len;

	pad_len = pfs->width.width - 1;
	if (pad_len > 0 && !pfs->flag.is_minus)
		cs_pad_handle(pfs, pad_len);
	ft_putchar_fd(value, STDOUT_FILENO);
	if (pad_len >= 0 && pfs->flag.is_minus)
		cs_pad_handle(pfs, pad_len);
	if (pad_len > 0)
		pfs->ft_ret.ft_return += pad_len + 1;
	else
		pfs->ft_ret.ft_return += 1;
}

/*
	# c_specifier : 
		## print the character if no padding
		## otherwise run set_padded_c
	# checks is asterisk 
		## then update width 
	# if no padding add 1 (len of char) to ft_return
	# `is_percent`
		## use `%` percent specifier as a `c` specifier
	# `c_handle`
		# I used this trick to out custom char not in args like '%'
*/
void	c_specifier(va_list args, t_format_specifier *pfs, int32_t c_handle)
{
	int	value;

	check_asterisk(pfs, args);
	if (c_handle)
		value = c_handle;
	else
		value = va_arg(args, uint32_t);
	if (pfs->width.width || pfs->precision.is_precision)
		set_padded_c(value, pfs);
	else
	{
		ft_putchar_fd(value, STDOUT_FILENO);
		pfs->ft_ret.ft_return += 1;
	}
}
