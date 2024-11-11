
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
