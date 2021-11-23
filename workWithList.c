#include "linnkedList.h"
void	delete_after_pointer(t_list **list)
{
	t_list	*temp;

	if (!(*list)->next)
		return;
	temp = (*list)->next;
	if (temp->next)
	{
		(*list)->next = temp->next;
		temp->next->prev = *list;
	}
	else
	{
		(*list)->next = NULL;
	}
	free(temp);
}

void	delete_before_pointer(t_list **list)
{
	t_list	*temp;

	if (!(*list)->prev)
		return;
	temp = (*list)->prev;
	if (temp->prev)
	{
		(*list)->prev = temp->prev;
		temp->prev->next = *list;
	}
	else
	{
		(*list)->prev = NULL;
	}
	free(temp);
}

void	create_after_pointer(t_list **list, int data)
{
	t_list	*temp;

	if (!list)
	{
		printf("DELETE NULL POINTER!\n");
		return ;
	}
	temp = ls_addelem(data);
	if (!*list)
		*list = temp;
	else
	{
		if ((*list)->next)
		{
			temp->next = (*list)->next;
			temp->next->prev = temp;
			(*list)->next = temp;
			temp->prev = (*list);
		}
		else
		{
			(*list)->next = temp;
			temp->prev = (*list);
		}
	}
}

void	create_before_pointer(t_list **list, int data)
{
	t_list	*temp;

	if (!list)
	{
		printf("DELETE NULL POINTER!\n");
		return ;
	}
	temp = ls_addelem(data);
	if (!*list)
		*list = temp;
	else
	{
		if ((*list)->prev)
		{
			(*list)->prev = temp->prev;
			temp->prev->next = temp;
			temp->next = (*list);
			(*list)->prev = temp;
		}
		else
		{
			(*list)->prev = temp;
			temp->next = (*list);
		}
	}
}

void	vivod(t_list *list)
{
	printf("\tdata: %d\n", list->data);
	printf("\tnext: %p\n", list->next);
	printf("\tprev: %p\n", list->prev);
}

void    startWork(void)
{
	int switch_flag;
	t_list  *list;
	t_list	*start_list;
	t_list	*taked_el;
	int		data;

	taked_el = NULL;
	list = NULL;
	printf("U are ready?\n1.\t\tLet's go\nAny key.\tExit\n");
	scanf("%d", &switch_flag);
	if (switch_flag != 1)
		return ;
	while (1)
	{
		printf("1. Cleaner\n2. List clear?\n3. Pointer to start\n4. Pointer to end\n5. Pointer at start?\n6. Pointer at end?\n7. Pointer next\n8. Pointer prev\n9. Value after pointer\n10.Value before pointer\n11.Delete after pointer\n12.Delete before pointer\n13.Take after pointer\n14.Take before pointer\n15.Change after pointer\n16.Change before pointer\n17.Create after ponter\n18.Create before pointer\n19.Print list\n20.Exit\n\tU entered:");
		scanf("%d", &switch_flag);
		system("clear");
		switch (switch_flag)
		{
		case 1:
			ls_cleaner(&start_list);
			free(start_list);
			free(list);
			break;
		case 2:
			if (list == NULL)
				printf("List empty\n");
			else
				printf("List not empty\n");
			break;
		case 3:
			if(list)
			{
				list = start_list;
			}
			else
			{
				printf("List do not created\n");
			}
			break;
		case 4:
			if (!list)
			{
				printf("List do not created\n");
			}
			else
			{
				while (list->next)
					list = list->next;
			}
			break;
		case 5:
			if (!list)
			{
				printf("List do not created\n");
			}	
			else if (list == start_list)
					printf("Pointer in start\n");
				else
					printf("Pointer not in start\n");
			break;
		case 6:
			if (!list)
			{
				printf("List do not created\n");
			}
			else if (!list->prev)
					printf("Pointer in end\n");
				else
					printf("Pointer not in end\n");
			break;
		case 7:
			if (!list)
			{
				printf("List do not created\n");
			}
			else if (list->next)
				list=list->next;
			break;
		case 8:
			if (!list)
			{
				printf("List do not created\n");
				
			}	
			else if (list->prev)
					list=list->prev;
			break;
		case 9:
			if (!list)
			{
				printf("List do not created\n");
			}	
			else if (list->next)
				vivod(list->next);
			else
				printf("No element\n");
			break;
		case 10:
			if (!list)
			{
				printf("List do not created\n");
			}	
			else if (list->prev)
				vivod(list->prev);
			else
				printf("No element\n");
			break;
		case 11:
			if (!list)
			{
				printf("List do not created\n");
			}	
			else
				delete_after_pointer(&list);
			break;
		case 12:
			if (!list)
			{
				printf("List do not created\n");
			}	
			else
			{
				delete_before_pointer(&list);
				start_list = list;
				while (start_list->prev)
					start_list = start_list->prev;
			}
			break;
		case 13:
			if (!list)
			{
				printf("List do not created\n");
			}	
			else if(list->next)
			{
				taked_el = list->next;
				if (taked_el->next)
				{
					list->next = taked_el->next;
					taked_el->next->prev = list;
				}
				else
				{
					list->next = NULL;
				}
			}
			else
			{
				printf("No element\n");
			}
			break;
		case 14:
			if (!list)
			{
				printf("List do not created\n");
			}	
			else if (list->prev)
			{
				taked_el = list->prev;
				if (taked_el->prev)
				{
					list->prev = taked_el->prev;
					taked_el->prev->next = list;
				}
				else
				{
					list->prev = NULL;
				}
			}
			break;
		case 15:
			if (!list)
			{
				printf("List do not created\n");
			}	
			else if (list->next)
			{
				printf("Enter data for el:");
				scanf("%d", &data);
				printf("\n");
				list->next->data = data;
			}
			else
			{
				printf("no elem\n");
			}
			break;
		case 16:
			if (!list)
			{
				printf("List do not created\n");
			}	
			else if (list->prev)
			{
				printf("Enter data for el:");
				scanf("%d", &data);
				printf("\n");
				list->prev->data = data;
			}
			else
			{
				printf("No elem\n");
			}
			break;
		case 17:
			printf("Enter data for el:");
			scanf("%d", &data);
			printf("\n");
			create_after_pointer(&list, data);
			start_list = list;
			break;
		case 18:
			printf("Enter data for el:");
			scanf("%d", &data);
			printf("\n");
			create_before_pointer(&list, data);
			start_list = list->prev;
			break;
		case 19:
			if (!start_list)
			{
				printf("empty list\n");
				break;
			}
			vivod(start_list);
			while (start_list->next)
			{
				printf("\t\t\\|/\n");
				start_list = start_list->next;
				vivod(start_list);
			}
			printf("Enter any sym:\n");
			scanf("%i", &data);
			while (start_list->prev)
			{
				vivod(start_list);
				printf("\t\t/|\\\n");
				start_list = start_list->prev;
			}
			vivod(start_list);
			printf("Enter any sym:\n");
			scanf("%i", &data);
			break;
		case 20:
			ls_cleaner(&start_list);
			free(list);
			exit(0);
			break;	
		default:
			printf("EROR 404\n");
			break;
		}
	}
}