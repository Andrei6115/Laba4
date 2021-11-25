#include "linnkedList.h"

t_list  *ls_addelem(int data)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
	{
		printf("Memory error\n");
		exit(0);
	}
	list->data = data;
	list->next = NULL;
	list->prev = NULL;
	return(list);
}

void	ls_cleaner(t_list **start_list)
{
	if (!start_list)
	{
		printf("NULL POINTER\n");
		return ;
	}
	if (!(*start_list))
	{
		printf("List empty\n");
		return ;
	}
	while ((*start_list)->next)
	{
		(*start_list) = (*start_list)->next;
		free((*start_list)->prev);
	}
	free((*start_list));
	*start_list = NULL;
}