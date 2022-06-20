#include "push_swap.h"

void	print_error(int flag)
{
	char *error;

	if (flag == 1)
	{
		error = "Error\nPlease enter only numbers\n";
		write(2, error, ft_strlen(error));
	}
}

// //create a new node
// t_listy	new_lst(int content, int index)
// {
// 	t_listy	new;

// 	new.content = content;
// 	new.index = index;
// 	new.next = NULL;
// 	return (new);
// }

// //adds a new node to the end of the list
// void	lst_add_front(t_listy **lst, t_listy *new)
// {
// 	if (!lst)
// 		return ;
// 	new->next = *lst;
// 	*lst = new;
// }

// //adds a node to the front of the list
// void	lst_add_back(t_listy **lst, t_listy *node)
// {
// 	t_listy *temp;

// 	temp = lst;
// 	if (!lst)
// 		return ;
// 	if (!*lst)
// 	{
// 		*lst = node;
// 		node->next = NULL;
// 		return;
// 	}
// 	while (temp->next)
// 	{
// 		temp = temp->next;
// 	}
// 	temp->next = node;
// 	node->next = NULL;
// }