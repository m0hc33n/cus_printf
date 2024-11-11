/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 09:10:00 by mamazian          #+#    #+#             */
/*   Updated: 2024/11/11 09:49:23 by mamazian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/common.h"

/*
	# `s specifier` :
		## truncate the string if the precision is lt the width specified ;
	# `I printed the string using a while loop` :
		## to control the truncated string if is_precision ;
		## `origin_len = pfs->precision.precision;`
		## ex : ft_printf("%.05s", "m0hc33n") -> "m0hc3" ;
	# `precision with s specifier && width = 0` :
		doesn't pad zeros or spaces when string len lt precision ;
	# ft_return : 
		## pad_len + origin_len (len of the str)
		## total len of the writen bytes
*/
static void	set_padded_s(char *value, t_format_specifier *pfs)
{
	int32_t		origin_len;
	int32_t		pad_len;
	int32_t		i;

	origin_len = ft_strlen(value);
	if (pfs->precision.is_precision && origin_len > pfs->precision.precision)
		origin_len = pfs->precision.precision;
	pad_len = pfs->width.width - origin_len;
	if (pad_len > 0 && !pfs->flag.is_minus)
		cs_pad_handle(pfs, pad_len);
	i = 0;
	while (i < origin_len)
		ft_putchar_fd(*(char *)(value + i++), STDOUT_FILENO);
	if (pfs->flag.is_minus && pad_len > 0)
		cs_pad_handle(pfs, pad_len);
	if (pad_len > 0)
		pfs->ft_ret.ft_return += origin_len + pad_len;
	else
		pfs->ft_ret.ft_return += origin_len;
}

/*
	# s_specifier : 
		## print the string if no padding
		## otherwise run set_padded_s
	# checks is asterisk  
		## then width should be set and minus flag if width negative
	# if no padding add ft_strlen(value) (len of string) to ft_return 
*/
void	s_specifier(va_list args, t_format_specifier *pfs)
{
	char	*value;

	check_asterisk(pfs, args);
	value = va_arg(args, char *);
	if (value == NULL)
		value = "(null)";
	if (pfs->width.width || pfs->precision.is_precision)
		set_padded_s(value, pfs);
	else
	{
		ft_putstr_fd(value, STDOUT_FILENO);
		pfs->ft_ret.ft_return += ft_strlen(value);
	}
}
