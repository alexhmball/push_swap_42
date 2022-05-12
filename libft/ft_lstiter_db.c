#include "libft.h"

void	ft_lstiter_db(t_dlist *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}