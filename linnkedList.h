#ifndef LINNKEDLIST_H
# define LINNKEDLIST_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
	struct s_list	*prev;
} t_list;

//-=workWithList=-
void    startWork(void);

//-=linnkedList.c=-
t_list  *ls_addelem(int data);
void	ls_cleaner(t_list **start_list);
#endif