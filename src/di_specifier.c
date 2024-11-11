
#include "../inc/common.h"

static void	get_di_origin_len(int32_t nbr, int32_t *len)
{
	while (nbr)
	{
		nbr /= BASE10_LEN;
		(*len)++;
	}
	if (*len == 0)
		(*len)++;
}

/*
	# handle sign and zeros from precision when - flag is there
*/
static void	di_minus_pad(
			t_format_specifier *pfs,
			int32_t origin_len,
			int32_t *pad_len)
{
	if (pfs->precision.is_precision)
	{
		sign_handle(pfs);
		if (pfs->precision.precision > origin_len)
		{
			pad(ZERO, pfs->precision.precision - origin_len);
			*pad_len -= pfs->precision.precision - origin_len;
		}
	}
	else if (pfs->flag.is_plus || pfs->is_value_neg)
		sign_handle(pfs);
}

/*
	# `pad_len >= 0`
	## to handle sign in out_padding even if !pad_len 
*/
static void	set_padded_int(uint32_t	value, t_format_specifier *pfs)
{
	int32_t			pad_len;
	int32_t			origin_len;

	origin_len = 0;
	get_di_origin_len(value, &origin_len);
	pad_len = get_pad_len(pfs, origin_len);
	if (pfs->flag.is_plus || pfs->is_value_neg)
		pfs->ft_ret.ft_return += 1;
	if (pad_len > 0)
		pfs->ft_ret.ft_return += pad_len + origin_len;
	else
		pfs->ft_ret.ft_return += origin_len;
	if (pfs->flag.is_space && !(pfs->flag.is_plus || pfs->is_value_neg))
		di_space_flag(pfs, &pad_len, origin_len);
	if (pad_len >= 0 && !pfs->flag.is_minus)
		out_padding(pfs, pad_len, origin_len);
	else if (!pfs->flag.is_minus)
		sign_handle(pfs);
	if (pfs->flag.is_minus)
		di_minus_pad(pfs, origin_len, &pad_len);
	put_u_nbr(value, STDOUT_FILENO);
	if (pfs->flag.is_minus && pad_len > 0)
		pad(SPACE, pad_len);
}

/*
	# `di_no_width`
		## write value to stdout when no padding require
	# `if (!origin_len)`
	## when value 0, the len is 1 but the func get_di_origin_len-
	### gonna return 0; then we should add this 1 to ft_return
*/
static void	di_no_pad(t_format_specifier *pfs, uint32_t value)
{
	int32_t	origin_len;

	if (pfs->flag.is_space && !(pfs->flag.is_plus || pfs->is_value_neg))
	{
		ft_putchar_fd(SPACE, STDOUT_FILENO);
		pfs->ft_ret.ft_return++;
	}
	sign_handle(pfs);
	put_u_nbr(value, STDOUT_FILENO);
	origin_len = 0;
	get_di_origin_len(value, &origin_len);
	if (!origin_len)
		origin_len++;
	if (pfs->is_value_neg || pfs->flag.is_plus)
		origin_len++;
	pfs->ft_ret.ft_return += origin_len;
}

/*
	u_value : if value < 0 , it may contain INT_MIN -> (-value) > MAX_INT
*/
void	di_specifier(va_list args, t_format_specifier *pfs)
{
	int32_t		value;
	uint32_t	u_value;

	check_asterisk(pfs, args);
	value = va_arg(args, int32_t);
	if (!value && !pfs->width.width && (pfs->precision.is_precision
			&& !pfs->precision.precision) && !pfs->flag.is_plus
		&& !pfs->flag.is_space)
		return ;
	if (!value && (pfs->precision.is_precision && !pfs->precision.precision))
		return (zero_val_x_prec(pfs));
	u_value = value;
	if (value < 0)
	{
		pfs->is_value_neg = 1;
		u_value = value * (-1);
	}
	if (pfs->width.width || pfs->precision.precision)
		set_padded_int(u_value, pfs);
	else
		di_no_pad(pfs, u_value);
}
