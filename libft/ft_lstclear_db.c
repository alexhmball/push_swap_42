#include "libft.h"

void	ft_lstclear_db(t_dlist **lst, void (*del)(void *))
{
	t_dlist *clear;

	while (*lst)
	{
		clear = (*lst)->next;
		ft_lstdelone_db(lst, *lst, del);
		*lst = clear;
	}
}