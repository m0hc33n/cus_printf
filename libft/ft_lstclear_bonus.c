/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:23:22 by mamazian          #+#    #+#             */
/*   Updated: 2024/10/25 12:18:22 by mamazian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*backup;

	if (lst)
	{
		if (*lst)
		{
			while (*lst)
			{
				backup = (*lst)->next;
				ft_lstdelone(*lst, del);
				*lst = backup;
			}
			*lst = 0;
		}
	}
}
