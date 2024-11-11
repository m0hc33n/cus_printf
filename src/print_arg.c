/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 09:09:24 by mamazian          #+#    #+#             */
/*   Updated: 2024/11/08 13:29:31 by mamazian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/common.h"

void	print_arg(va_list args, t_format_specifier *pfs)
{
	if (pfs->specifier == X_SPEC)
		x_specifier(args, pfs);
	else if (pfs->specifier == X_SPEC_U)
	{
		pfs->is_uper_x = 1;
		x_specifier(args, pfs);
	}
	else if (pfs->specifier == I_SPEC || pfs->specifier == D_SPEC)
		di_specifier(args, pfs);
	else if (pfs->specifier == U_SPEC)
		u_specifier(args, pfs);
	else if (pfs->specifier == C_SPEC)
		c_specifier(args, pfs, FALSE);
	else if (pfs->specifier == S_SPEC)
		s_specifier(args, pfs);
	else if (pfs->specifier == P_SPEC)
		p_specifier(args, pfs);
	else if (pfs->specifier == PERCENT)
		percent_specifier(args, pfs);
	else if (pfs->no_specifier)
		no_specifier(args, pfs);
}
