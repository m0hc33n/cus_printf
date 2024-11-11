/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 09:10:04 by mamazian          #+#    #+#             */
/*   Updated: 2024/11/11 14:14:46 by mamazian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/common.h"

void	get_xp_origin_len(void *nbr, int32_t *len, int32_t type)
{
	uint32_t	uint32_nbr;
	uintptr_t	uintptr_nbr;

	if (type == COUNT_HEX)
	{
		uint32_nbr = *(uint32_t *)nbr;
		while (uint32_nbr)
		{
			uint32_nbr /= BASE16_LEN;
			(*len)++;
		}
	}
	else if (type == COUNT_PTR)
	{
		uintptr_nbr = *(uintptr_t *)nbr;
		while (uintptr_nbr)
		{
			uintptr_nbr /= BASE16_LEN;
			(*len)++;
		}
	}
	if (*len == 0)
		(*len)++;
}

void	put_u_nbr(uint32_t n, int fd)
{
	uint32_t	nbr;

	if (fd < 0)
		return ;
	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd(45, fd);
		nbr = -nbr;
	}
	if (nbr <= 9)
		ft_putchar_fd(nbr + 48, fd);
	else
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd((nbr % 10) + 48, fd);
	}
}

void	sign_handle(t_format_specifier *pfs)
{
	if (ft_strchr(HEXSPEC, pfs->specifier) && (pfs->flag.is_hash))
	{
		if (pfs->is_uper_x)
			ft_putstr_fd(HEX_SIGN_U, STDOUT_FILENO);
		else
			ft_putstr_fd(HEX_SIGN, STDOUT_FILENO);
	}
	else if (ft_strchr(DISPEC, pfs->specifier)
		&& (pfs->flag.is_plus || pfs->is_value_neg))
	{
		if (!pfs->is_value_neg)
			ft_putchar_fd(PLUS, STDOUT_FILENO);
		else
			ft_putchar_fd(MINUS, STDOUT_FILENO);
	}
}

uint32_t	get_max(uint32_t one, uint32_t two)
{
	if (one > two)
		return (one);
	return (two);
}

void	pad(char pad, uint32_t pad_len)
{
	while (pad_len--)
		ft_putchar_fd(pad, STDOUT_FILENO);
}
