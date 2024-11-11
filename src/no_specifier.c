/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:09:38 by mamazian          #+#    #+#             */
/*   Updated: 2024/11/09 16:27:57 by mamazian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/common.h"

void	no_specifier(va_list args, t_format_specifier *pfs)
{
	check_asterisk(pfs, args);
	if (pfs->width.width)
	{
		if (pfs->flag.is_minus)
		{
			pfs->ft_ret.ft_return += pfs->width.width - 1;
			return ;
		}
		if (pfs->flag.is_zero)
			pad(ZERO, pfs->width.width - 1);
		else
			pad(SPACE, pfs->width.width - 1);
		pfs->ft_ret.ft_return += pfs->width.width - 1;
	}
}
