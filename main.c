#include "push_swap.h"

void	error_int(t_dlist *node, t_dlist **head)
{
	while(node)
	{
		free(node->content);
		node = node->next;
	}
	ft_printf("error\nint out of bounds");
	ft_lstclear_db(head, free);
	free (head);
	exit(1);
}

void	*str_to_int(char *c, t_dlist **head)
{
	int				s;
	long int		r;
	int				i;
	int				*ret;
	char			*x;
	t_dlist			*node;

	r = 0;
	s = 1;
	i = 0;
	x = c;
	node = *head;
	if (x[i] == '-')
	{
		s *= -1;
		i++;
	}
	while (x[i] >= '0' && x[i] <= '9')
	{
		r *= 10;
		r += x[i] - '0';
		i++;
		if (r > INT_MAX || r < INT_MIN)
			error_int(node, head);
	}
	ret = (int *)malloc(sizeof(int *));
	*ret = r * s;
	return (ret);
}

void	push_b(t_dlist **B_head, t_dlist **A_head, t_dlist *node)
{
	t_dlist *new;
	int		*content;

	content = (int *)malloc(sizeof(int *));
	content = node->content;
	new = ft_lstnew_db(content);
	// free(node->content);
	ft_lstdelone_db(A_head, node, free);
	ft_lstadd_front_db(B_head, new);
}

int	main(int ac, char **av)
{
	t_dlist		**A_head;
	t_dlist		**B_head;
	t_dlist		*current;
	t_dlist 	*last;
	long int	m;
	int			i;

	A_head = (t_dlist **)malloc(sizeof(t_dlist **));
	B_head = (t_dlist **)malloc(sizeof(t_dlist **));
	i = 1;
	if (ac < 2)
		return (0);
	while(i < ac)
	{
		current = ft_lstnew_db(str_to_int(av[i], A_head));
		m += *(int *)current->content;
		if (i == 1)
			*A_head = last = current;
		else
			ft_lstadd_back_db(&last, current);
		i++;
	}
	m /= ac;
	current = *A_head;
	while (current)
	{
		if (m < *(int *)current->content)
			push_b(B_head, A_head, current);
		ft_printf("%d\n", *(int *)current->content);
		// last = current;
		current = current->next;
	}
	current = *A_head;
	while (current)
	{
		ft_printf("%d\n", *(int *)current->content);
		free(current->content);
		current = current->prev;
	}
	current = *A_head;
	ft_lstclear_db(A_head, free);
	free(A_head);
	return (0);
}