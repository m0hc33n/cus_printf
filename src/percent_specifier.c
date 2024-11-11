/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_specifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:20:02 by mamazian          #+#    #+#             */
/*   Updated: 2024/11/08 10:55:44 by mamazian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/common.h"

void	percent_specifier(va_list args, t_format_specifier *pfs)
{
	c_specifier(args, pfs, PERCENT);
}
