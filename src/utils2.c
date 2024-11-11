
#include "../inc/common.h"

/* 
	`di_space_flag`:
	 * `pfs->precision.precision >= pfs->width.width`
	 	** if so then the space not count with precision padding
		** else space count with width padding len -> pad_len--;
	* `if (pfs->width.width <= ol)`
		** if so , then no width padding and space flag inc ft_return
*/
void	di_space_flag(t_format_specifier *pfs, int32_t *pl, int32_t ol)
{
	ft_putchar_fd(SPACE, STDOUT_FILENO);
	if (pfs->precision.precision >= pfs->width.width)
		pfs->ft_ret.ft_return++;
	else
	{
		(*pl)--;
		if (pfs->width.width <= ol)
			pfs->ft_ret.ft_return++;
	}
}

/*
	d spec with print '+' in this case ("%+.d", 0) unlike x spec-
	dont print '0x' if '#' like in case ("%#.x", 0)
	# `if (!pfs->width.width) pfs->ft_ret.ft_return += 1;`
	## ft_return handled if zer_val_x_prec : 
	### `pad_len = pfs->width.width ; pfs->ft_ret.ft_return += pad_len;`
	### if !width and + flag exist then we should add 1 (len('+'))
*/
static void	home_sign_handle(t_format_specifier *pfs)
{
	if (pfs->specifier == P_SPEC && (pfs->flag.is_hash))
		ft_putstr_fd(HEX_SIGN, STDOUT_FILENO);
	else if (ft_strchr(DISPEC, pfs->specifier) && (pfs->flag.is_plus))
	{
		ft_putchar_fd(PLUS, STDOUT_FILENO);
		if (!pfs->width.width)
			pfs->ft_ret.ft_return += 1;
	}
}

static void	zero_val_x_prec_cont(t_format_specifier *pfs, int32_t pad_len)
{
	if (!pfs->flag.is_minus)
	{
		if (pad_len > 0)
			pad(SPACE, pad_len);
		home_sign_handle(pfs);
	}
	else
	{
		home_sign_handle(pfs);
		if (pad_len > 0)
			pad(SPACE, pad_len);
	}
}

/*
	# 
*/
void	zero_val_x_prec(t_format_specifier *pfs)
{
	int32_t	pad_len;

	pad_len = pfs->width.width;
	pfs->ft_ret.ft_return += pad_len;
	if (pfs->flag.is_plus && ft_strchr(DISPEC, pfs->specifier))
		pad_len--;
	else if (pfs->flag.is_hash && pfs->specifier == P_SPEC)
		pad_len -= 2;
	if (pfs->flag.is_space && !(pfs->flag.is_plus || pfs->is_value_neg))
	{
		ft_putchar_fd(SPACE, STDOUT_FILENO);
		pad_len--;
		if (!pfs->width.width)
			pfs->ft_ret.ft_return++;
	}
	zero_val_x_prec_cont(pfs, pad_len);
}

/*
	# check if * is specified in flags then get arg from va_arg
	# if width < 0 then a minus flag should be set
*/
void	check_asterisk(t_format_specifier *pfs, va_list args)
{
	if (pfs->width.is_asterisk)
	{
		pfs->width.width = va_arg(args, int32_t);
		if (pfs->width.width < 0)
		{
			pfs->flag.is_minus = 1;
			pfs->width.width *= -1;
		}
	}
}
