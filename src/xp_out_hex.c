/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xp_out_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:45:48 by mamazian          #+#    #+#             */
/*   Updated: 2024/11/11 11:59:29 by mamazian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/common.h"

static void	out_hex_ptr(uintptr_t nbr)
{
	if (nbr < (uintptr_t)BASE16_LEN)
	{
		ft_putchar_fd(BASE16[nbr % BASE16_LEN], STDOUT_FILENO);
	}
	else
	{
		out_hex_ptr(nbr / BASE16_LEN);
		ft_putchar_fd(BASE16[nbr % BASE16_LEN], STDOUT_FILENO);
	}
}

void	out_hex(t_format_specifier *pfs, uint32_t nbr)
{
	if (nbr < (uint32_t)BASE16_LEN)
	{
		if (pfs->is_uper_x)
			ft_putchar_fd(BASE16U[nbr % BASE16_LEN], STDOUT_FILENO);
		else
			ft_putchar_fd(BASE16[nbr % BASE16_LEN], STDOUT_FILENO);
	}
	else
	{
		out_hex(pfs, nbr / BASE16_LEN);
		out_hex(pfs, nbr % BASE16_LEN);
	}
}

static void	xp_out_hex(t_format_specifier *pfs, void *value, int32_t type)
{
	uint32_t	uint32_nbr;
	uintptr_t	uintptr_nbr;

	if (type == COUNT_HEX)
	{
		uint32_nbr = *(uint32_t *)value;
		out_hex(pfs, uint32_nbr);
	}
	else if (type == COUNT_PTR)
	{
		uintptr_nbr = *(uintptr_t *)value;
		out_hex_ptr(uintptr_nbr);
	}
}

/*
	# `out_padded_hex`
		## set the padding
		## origin_len : the hexed value length
		## pad_len : the padded length
		## xp_out_hex() : func that write the hexed value to stdout 
	# `origin_len >= pfs->precision.precision`
		## if so , then no need for padding zeros
	# `pfs->flag.is_hash && pfs->precision.is_precision
		&& (pfs->width.width - pfs->precision.precision == 1)
		&& (pfs->precision.precision > origin_len)`
		# if so , then the '0x' (len('0x') == 2 > (w - p == 1)) 
		-> we should add 1	to return value ;
		-> exp : ("%#5.4x", 10) -> "0x000a" ret : 6; 
*/
void	xp_out_padded_hex(
			t_format_specifier *pfs,
			void *value,
			int32_t type
)
{
	int32_t		pad_len;
	int32_t		origin_len;

	origin_len = 0;
	get_xp_origin_len(value, &origin_len, type);
	pad_len = get_pad_len(pfs, origin_len);
	if (pfs->flag.is_hash)
		pfs->ft_ret.ft_return += 2;
	if (pfs->flag.is_hash && pfs->precision.is_precision
		&& (pfs->width.width - pfs->precision.precision == 1)
		&& (pfs->precision.precision > origin_len))
		pfs->ft_ret.ft_return++;
	if (pad_len > 0)
		pfs->ft_ret.ft_return += pad_len + origin_len;
	else
		pfs->ft_ret.ft_return += origin_len;
	if (pad_len >= 0 && !pfs->flag.is_minus)
		out_padding(pfs, pad_len, origin_len);
	else if (pad_len <= 0 && !pfs->flag.is_minus)
		sign_handle(pfs);
	if (pfs->flag.is_minus)
		xp_minus_pad(pfs, origin_len, &pad_len);
	xp_out_hex(pfs, value, type);
	if (pfs->flag.is_minus && pad_len > 0)
		pad(SPACE, pad_len);
}

/*
	# `xp_no_pad`
		## a shared func between x and p specifiers
		## if origin_len == 0 -> the value is 0 or nullptr
		## -> then zero must be count as 1 in origin_len
*/
void	xp_no_pad(t_format_specifier *pfs, void *value, int32_t type)
{
	int32_t	origin_len;

	origin_len = 0;
	get_xp_origin_len(value, &origin_len, type);
	if (!origin_len)
		origin_len++;
	if (pfs->flag.is_hash)
	{
		if (pfs->is_uper_x)
			ft_putstr_fd(HEX_SIGN_U, STDOUT_FILENO);
		else
			ft_putstr_fd(HEX_SIGN, STDOUT_FILENO);
		origin_len += 2;
	}
	xp_out_hex(pfs, value, type);
	pfs->ft_ret.ft_return += origin_len;
}
