
#include "ft_ls.h"

int					greater(char *i, char *j)
{
	return (ft_strcmp(i, j) > 0);
}

int							time_compare(t_node *i, t_node *j)
{
	if (i->time < j->time)
		return (1);
	if (i->time > j->time)
		return (0);
	if (i->time == j->time)
		return (greater(i->name, j->name));
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
	if ( (T_ON) ? time_compare(current, node) : greater(current->name, node->name) )
	{
		insert_before(list, node);
		return (node);
	}
	else
	{
		while (current->next != NULL && ( (T_ON) ? time_compare(node, current->next) : greater(node->name, current->next->name) ) )
			current = current->next;
		insert_after(current, node);
	}
	return (list);
}
