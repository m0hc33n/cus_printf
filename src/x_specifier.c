
#include "../inc/common.h"

/*
	# `x_specifier`
		## print hex value , '0x' suffixed if hash flag setted
	# `padding`
		run xp_out_padded_hex
	# `ft_return`
		##	is the len of the outputed hexed value
		##  +2 if hash flag setted 
		
*/
void	x_specifier(va_list args, t_format_specifier *pfs)
{
	uint32_t	value;

	check_asterisk(pfs, args);
	value = va_arg(args, uint32_t);
	if (!value && !pfs->width.width && (pfs->precision.is_precision
			&& !pfs->precision.precision))
		return ;
	if (!value && (pfs->precision.is_precision && !pfs->precision.precision))
	{
		zero_val_x_prec(pfs);
		return ;
	}
	if (!value && pfs->flag.is_hash)
		pfs->flag.is_hash = 0;
	if (pfs->width.width || pfs->precision.is_precision)
		xp_out_padded_hex(pfs, &value, COUNT_HEX);
	else
		xp_no_pad(pfs, &value, COUNT_HEX);
}
