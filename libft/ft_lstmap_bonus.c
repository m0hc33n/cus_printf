
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;

	if (lst && f)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
			return (0);
		head = new;
		lst = lst->next;
		while (lst)
		{
			new->next = ft_lstnew(f(lst->content));
			if (!new->next)
			{
				ft_lstclear(&head, del);
				return (0);
			}
			lst = lst->next;
			new = new->next;
		}
		new->next = 0;
		return (head);
	}
	return (NULL);
}
