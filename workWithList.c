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
	if (!temp)
		return ;
	if (!*list)
		*list = temp;
	else
	{
		if ((*list)->prev)
		{
			temp->prev = (*list)->prev;
			temp->prev->next = temp;
			(*list)->prev = temp;
			temp->next = (*list);
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
	printf("\t[%d]", list->data);
}

void	print(t_list *start_list, t_list *list)
{
	if (!start_list)
	{
				printf("empty list\n");
				return;
	}
	vivod(start_list);
	if (start_list == list)
			printf("*");
	while (start_list->next)
	{
		start_list = start_list->next;
		printf("->");
		vivod(start_list);
		if (start_list == list)
			printf("*");
	}
	printf("\n");
	while (start_list->prev)
	{
		
		vivod(start_list);
		if (start_list == list)
			printf("*");
		printf("<-");
		start_list = start_list->prev;
	}
	vivod(start_list);
	if (start_list == list)
			printf("*");
	printf("\n");
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
	start_list = NULL;
	//printf("⠄⠄⢀⡋⣡⣴⣶⣶⡀⠄⠄⠙⢿⣿⣿⣿⣿⣿⣴⣿⣿⣿⢃⣤⣄⣀⣥⣿⣿⠄\n⠄⠄⢸⣇⠻⣿⣿⣿⣧⣀⢀⣠⡌⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⣿⣿⣿⠄\n⠄⢀⢸⣿⣷⣤⣤⣤⣬⣙⣛⢿⣿⣿⣿⣿⣿⣿⡿⣿⣿⡍⠄⠄⢀⣤⣄⠉⠋⣰\n⠄⣼⣖⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⢇⣿⣿⡷⠶⠶⢿⣿⣿⠇⢀⣤\n⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⣿⣿⣿⡇⣿⣿⣿⣿⣿⣿⣷⣶⣥⣴⣿⡗\n⢀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠄\n⢸⣿⣦⣌⣛⣻⣿⣿⣧⠙⠛⠛⡭⠅⠒⠦⠭⣭⡻⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠄\n⠘⣿⣿⣿⣿⣿⣿⣿⣿⡆⠄⠄⠄⠄⠄⠄⠄⠄⠹⠈⢋⣽⣿⣿⣿⣿⣵⣾⠃⠄\n⠄⠘⣿⣿⣿⣿⣿⣿⣿⣿⠄⣴⣿⣶⣄⠄⣴⣶⠄⢀⣾⣿⣿⣿⣿⣿⣿⠃⠄\n⠄⠄⠈⠻⣿⣿⣿⣿⣿⣿⡄⢻⣿⣿⣿⠄⣿⣿⡀⣾⣿⣿⣿⣿⣛⠛⠁⠄⠄\n⠄⠄⠄⠄⠈⠛⢿⣿⣿⣿⠁⠞⢿⣿⣿⡄⢿⣿⡇⣸⣿⣿⠿⠛⠁⠄⠄\n");
	printf("Are U ready?\n1.\t\tLet's go\nAny key.\tExit\n");
	scanf("%d", &switch_flag);
	fflush(stdin);
	system("clear");
	if (switch_flag != 1)
		exit(0);
	while (1)
	{
		print(start_list, list);
		printf("\n⠄⠄⢀⡋⣡⣴⣶⣶⡀⠄⠄⠙⢿⣿⣿⣿⣿⣿⣴⣿⣿⣿⢃⣤⣄⣀⣥⣿⣿⠄\n⠄⠄⢸⣇⠻⣿⣿⣿⣧⣀⢀⣠⡌⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⣿⣿⣿⠄\n⠄⢀⢸⣿⣷⣤⣤⣤⣬⣙⣛⢿⣿⣿⣿⣿⣿⣿⡿⣿⣿⡍⠄⠄⢀⣤⣄⠉⠋⣰\n⠄⣼⣖⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⢇⣿⣿⡷⠶⠶⢿⣿⣿⠇⢀⣤\n⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⣿⣿⣿⡇⣿⣿⣿⣿⣿⣿⣷⣶⣥⣴⣿⡗\n⢀⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠄\n⢸⣿⣦⣌⣛⣻⣿⣿⣧⠙⠛⠛⡭⠅⠒⠦⠭⣭⡻⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠄\n⠘⣿⣿⣿⣿⣿⣿⣿⣿⡆⠄⠄⠄⠄⠄⠄⠄⠄⠹⠈⢋⣽⣿⣿⣿⣿⣵⣾⠃⠄\n⠄⠘⣿⣿⣿⣿⣿⣿⣿⣿⠄⣴⣿⣶⣄⠄⣴⣶⠄⢀⣾⣿⣿⣿⣿⣿⣿⠃⠄\n⠄⠄⠈⠻⣿⣿⣿⣿⣿⣿⡄⢻⣿⣿⣿⠄⣿⣿⡀⣾⣿⣿⣿⣿⣛⠛⠁⠄⠄\n⠄⠄⠄⠄⠈⠛⢿⣿⣿⣿⠁⠞⢿⣿⣿⡄⢿⣿⡇⣸⣿⣿⠿⠛⠁⠄⠄\n");
		printf("\n1. Cleaner\n2. List clear?\n3. Pointer to start\n4. Pointer to end\n5. Pointer at start?\n6. Pointer at end?\n7. Pointer next\n8. Pointer prev\n9. Value after pointer\n10.Value before pointer\n11.Delete after pointer\n12.Delete before pointer\n13.Take after pointer\n14.Take before pointer\n15.Change after pointer\n16.Change before pointer\n17.Create after ponter\n18.Create before pointer\n19.Print list\n20.Exit\n\tU entered:");
		scanf("%d", &switch_flag);
		fflush(stdin);
		system("clear");
		switch (switch_flag)
		{
		case 1:
			if (list)
			{
				ls_cleaner(&start_list);
				list = NULL;
			}
			else
			{
				printf("List clear\n");
			}
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
				printf("List clear\n");
			}
			break;
		case 4:
			if (!list)
			{
				printf("List clear\n");
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
				printf("List clear\n");
			}	
			else if (!list->prev)
					printf("Pointer in start\n");
				else
					printf("Pointer not in start\n");
			break;
		case 6:
			if (!list)
			{
				printf("List clear\n");
			}
			else if (!list->next)
					printf("Pointer in end\n");
				else
					printf("Pointer not in end\n");
			break;
		case 7:	
			if (!list)
			{
				printf("List clear\n");
			}
			else if (list->next)
				list=list->next;
			break;
		case 8:
			if (!list)
			{
				printf("List clear\n");
				
			}	
			else
				if (list->prev)
					list=list->prev;
				else
					printf("no el\n");
			break;
		case 9:
			if (!list)
			{
				printf("List clear");
			}	
			else if (list->next)
				vivod(list->next);
			else
				printf("No element");
				printf("\n");
			break;
		case 10:
			if (!list)
			{
				printf("List clear");
			}	
			else if (list->prev)
				vivod(list->prev);
			else
				printf("No element");
				printf("\n");
			break;
		case 11:
			if (!list)
			{
				printf("List clear\n");
			}	
			else
				delete_after_pointer(&list);
			break;
		case 12:
			if (!list)
			{
				printf("List clear\n");
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
				printf("List clear\n");
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
				printf("Taked el: ");
				vivod(taked_el);
				printf("\n");
			}
			else
			{
				printf("No element\n");
			}
			break;
		case 14:
			if (!list)
			{
				printf("List clear\n");
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
				printf("Taked el: ");
				vivod(taked_el);
				printf("\n");
			}
			else
			{
				printf("No element\n");
			}
			break;
		case 15:
			if (!list)
			{
				printf("List clear\n");
			}	
			else if (list->next)
			{
				printf("Enter data for el:");
				scanf("%d", &data);
				fflush(stdin);
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
				printf("List clear\n");
			}	
			else if (list->prev)
			{
				printf("Enter data for el:");
				scanf("%d", &data);
				fflush(stdin);
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
			fflush(stdin);
			printf("\n");
			create_after_pointer(&list, data);
			if(!list)
			{
				printf("memmory not alocate\n");
			}
			else
			{
				start_list = list;
				while (start_list->prev)
				{
					start_list=start_list->prev;
				}
			}
			break;
		case 18:
			printf("Enter data for el:");
			scanf("%d", &data);
			fflush(stdin);
			printf("\n");
			create_before_pointer(&list, data);
			if(!list)
			{
				printf("memmory not alocate\n");
			}
			else
			{
				start_list = list;
				while (start_list->prev)
				{
					start_list=start_list->prev;
				}
			}
			break;
		case 19:
			//print(start_list, list);
			break;
		case 20:
			ls_cleaner(&start_list);
			return ;	
		default:
			printf("ERROR 404\n");
			break;
		}
	}
}
