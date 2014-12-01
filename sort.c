
#include "ft_ls.h"

int					greater(char *i, char *j)
{
	return (ft_strcmp(i, j) > 0);
}

int							int_greater(int i, int j)
{
	return (i > j);
}

static t_node				*insert_after(t_node *list, t_node *node)
{
	t_node			*tmp;

	tmp = list->next;
	list->next = node;
	node->next = tmp;
	return (list);
}

static t_node				*insert_before(t_node *list, t_node *node)
{
	node->next = list;
	return (node);
}

t_node				*sort_insert(t_node *list, t_node *node, int flags)
{
	t_node			*current;

	current = list;
	if ( (T_ON) ? int_greater(current->time, node->time) : greater(current->name, node->name) )
	{
		insert_before(list, node);
		return (node);
	}
	else
	{
		while (current->next != NULL && ( (T_ON) ? int_greater(node->time, current->next->time) : greater(node->name, current->next->name) ) )
			current = current->next;
		insert_after(current, node);
	}
	return (list);
}
