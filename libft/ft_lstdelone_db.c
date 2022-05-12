#include "libft.h"

void	ft_lstdelone_db(t_dlist **head, t_dlist *node, void (*del)(void *))
{
	if (*head && node)
	{
		if (*head == node)
			*head = node->next;
		if (node->next)
			node->next->prev = node->prev;
		if (node->prev)
			node->prev->next = node->next;
		del(node);
	}
}