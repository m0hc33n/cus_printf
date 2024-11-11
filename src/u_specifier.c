
#include "../inc/common.h"

static void	get_u_origin_len(uint32_t nbr, uint32_t nbase, int32_t *len)
{
	while (nbr)
	{
		nbr /= nbase;
		(*len)++;
	}
	if (*len == 0)
		(*len)++;
}

static void	set_padded_uint(uint32_t value, t_format_specifier *pfs)
{
	int32_t		pad_len;
	int32_t		origin_len;

	origin_len = 0;
	get_u_origin_len(value, BASE10_LEN, &origin_len);
	pad_len = get_pad_len(pfs, origin_len);
	if (pad_len > 0)
		pfs->ft_ret.ft_return += pad_len + origin_len;
	else
		pfs->ft_ret.ft_return += origin_len;
	if (pad_len >= 0 && !pfs->flag.is_minus)
		out_padding(pfs, pad_len, origin_len);
	if (pfs->flag.is_minus && pfs->precision.is_precision)
	{
		if (pfs->precision.precision > origin_len)
		{
			pad(ZERO, pfs->precision.precision - origin_len);
			pad_len -= pfs->precision.precision - origin_len;
		}
	}
	put_u_nbr(value, STDOUT_FILENO);
	if (pfs->flag.is_minus && pad_len > 0)
		pad(SPACE, pad_len);
}

static void	u_no_pad(t_format_specifier *pfs, uint32_t value)
{
	int32_t		origin_len;

	put_u_nbr(value, STDOUT_FILENO);
	origin_len = 0;
	get_u_origin_len(value, BASE10_LEN, &origin_len);
	pfs->ft_ret.ft_return += origin_len;
}

void	u_specifier(va_list args, t_format_specifier *pfs)
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
	if (pfs->width.width || pfs->precision.is_precision)
		set_padded_uint(value, pfs);
	else
		u_no_pad(pfs, value);
}
