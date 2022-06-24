#include "push_swap.h"

t_listy	*push_b(t_listy **a_head, t_listy **b_head, t_listy *node)
{
	t_listy	*temp;

	if (!a_head || !b_head || !node)
		ft_printf("you lost something in push_b");
	temp = *a_head;
	a_head = &temp->next;
	lst_add_front(b_head, node);
	return (*a_head);
}

void	sorting(t_listy *a)
{
	t_listy	*b;
	t_listy	*current;

	b = (t_listy *)malloc(sizeof(t_listy *));
	b = NULL;
	current = a;
	a = push_b(&a, &b, current);
	while (a)
	{
		ft_printf("%d\n", a->content);
		a = a->next;
	}
}