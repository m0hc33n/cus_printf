/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 09:09:54 by mamazian          #+#    #+#             */
/*   Updated: 2024/11/11 12:19:36 by mamazian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/common.h"

/*
	# `minus_present`
		## shared with x and p specifiers
		## print padding when minus flag is setted
		## print '0x' if hash flag is setted
	# `pfs->precision.precision - origin_len > 0`
		## pad zeros when precision gt origin_len
*/
void	xp_minus_pad(
				t_format_specifier *pfs,
				int32_t origin_len,
				int32_t *pad_len)
{
	if (pfs->precision.is_precision)
	{
		if (pfs->flag.is_hash)
			sign_handle(pfs);
		if (pfs->precision.precision > origin_len)
		{
			pad(ZERO, pfs->precision.precision - origin_len);
			*pad_len -= pfs->precision.precision - origin_len;
		}
	}
	else if (pfs->flag.is_minus && pfs->flag.is_hash)
		sign_handle(pfs);
}

void	cs_pad_handle(t_format_specifier *pfs, int32_t pad_len)
{
	if (pfs->flag.is_zero && !pfs->flag.is_minus)
		pad(ZERO, pad_len);
	else
		pad(SPACE, pad_len);
}

static void	pad_no_precision(
	t_format_specifier *pfs,
	int32_t pad_len)
{
	if (pfs->flag.is_zero)
	{
		if (pfs->flag.is_hash || pfs->flag.is_plus || pfs->is_value_neg)
			sign_handle(pfs);
		pad(ZERO, pad_len);
	}
	else
	{
		pad(SPACE, pad_len);
		sign_handle(pfs);
	}
}

/*
	
*/
void	out_padding(
			t_format_specifier *pfs,
			int32_t pl,
			int32_t og)
{
	if (!pfs->precision.is_precision)
		pad_no_precision(pfs, pl);
	else
	{
		if (pfs->precision.precision >= pfs->width.width)
		{
			sign_handle(pfs);
			pad(ZERO, pl);
		}
		else
		{
			if (og > pfs->precision.precision)
			{
				pad(SPACE, pl);
				sign_handle(pfs);
			}
			else
			{
				if (pl - (pfs->precision.precision - og) > 0)
					pad(SPACE, pl - (pfs->precision.precision - og));
				sign_handle(pfs);
				pad(ZERO, pfs->precision.precision - og);
			}
		}
	}
}

/*
	* get_pad_len : return the require pad len `pad_len`
	
	* `pfs->width.width > pfs->precision.precision` 
		make sure to not sub '0x' or '+'  len from pad_len
	--> reason : precision dont count '0x' or '+' as len of value;
		# exp : ft_printf("%#8.10x", 255) -> `0x00000000ff`
	--> when # or + is present and width gt precision , then '0x' or '+' 
		must be count with spaces
	--> EX : val = 255 ; ft_printf("%#15.10x", val) -> `  0x00000000ff`
*/

int32_t	get_pad_len(t_format_specifier *pfs, int32_t origin_len)
{
	int32_t	pad_len;

	if (pfs->precision.is_precision)
	{
		pad_len = get_max(pfs->precision.precision, pfs->width.width);
		pad_len -= origin_len;
		if (pfs->width.width > pfs->precision.precision)
		{
			if (pfs->flag.is_hash && ft_strchr(HEXSPEC, pfs->specifier))
				pad_len -= 2;
			else if ((pfs->flag.is_plus || pfs->is_value_neg)
				&& ft_strchr(DISPEC, pfs->specifier))
				pad_len -= 1;
		}
	}
	else
	{
		pad_len = pfs->width.width - origin_len;
		if (pfs->flag.is_hash && ft_strchr(HEXSPEC, pfs->specifier))
			pad_len -= 2;
		else if ((pfs->flag.is_plus || pfs->is_value_neg)
			&& ft_strchr(DISPEC, pfs->specifier))
			pad_len -= 1;
	}
	return (pad_len);
}
