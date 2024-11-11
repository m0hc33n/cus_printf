/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:44:36 by mamazian          #+#    #+#             */
/*   Updated: 2024/10/27 11:53:10 by mamazian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	if (fd < 0)
		return ;
	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd(45, fd);
		nbr = -nbr;
	}
	if (nbr <= 9)
	{
		ft_putchar_fd(nbr + 48, fd);
	}
	else
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd((nbr % 10) + 48, fd);
	}
}
