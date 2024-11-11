
#include "../inc/common.h"

/*
	# `p_specifier`
		## if no padding , it print the ptr to stdout
		## if padding , it run out_padded_hex()
	# `ft_return`
		## p_specifier inc ft_retrun with ptr len + 2 '0x'
	# `(pfs->ft_ret.ft_return += 2, sign_handle(pfs));`
		## p spec print '0x' and return 2 if the value 0 and width x prec 0
		### ex : ("%.p", 0) -> '0x'
*/
void	p_specifier(va_list args, t_format_specifier *pfs)
{
	uintptr_t	value;

	check_asterisk(pfs, args);
	value = (uintptr_t)va_arg(args, uintptr_t);
	if (!value && !pfs->width.width && (pfs->precision.is_precision
			&& !pfs->precision.precision))
		return (pfs->ft_ret.ft_return += 2, sign_handle(pfs));
	if (!value && (pfs->precision.is_precision && !pfs->precision.precision))
	{
		zero_val_x_prec(pfs);
		return ;
	}
	if (pfs->width.width || pfs->precision.is_precision)
		xp_out_padded_hex(pfs, &value, COUNT_PTR);
	else
		xp_no_pad(pfs, &value, COUNT_PTR);
}
