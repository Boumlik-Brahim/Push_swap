

void	sa(t_stack *stack, int i)
{
	t_node	*old_head;
	t_node	*new_head;

	if (stack->size <= 1)
		return ;
	old_head = return_first_node(stack);
	stack->size++;
	new_head = stack->head;
	if (stack->size > 2)
	{
		old_head->next = new_head->next;
		new_head->next->prev = old_head;
	}
	if (stack->size == 2)
		stack->last = old_head;
	old_head->prev = new_head;
	new_head->next = old_head;
	if (i == 1)
		ft_putstr_fd("sa\n", 1);
}

t_node	*add_back(t_stack *stack, t_node *new)
{
	t_node	*last;

	if (!new)
		return (NULL);
	if (!stack->head)
	{
		stack->head = new;
		stack->size = 0;
	}
	else
	{
		last = stack->last;
		last->next = new;
		new->prev = last;
	}
	stack->last = new;
	stack->size++;
	return (new);
}

void	ra(t_stack *stack, int i)
{
	t_node	*tmp;

	if (stack->head == NULL || stack->size <= 1)
		return ;
	tmp = return_first_node(stack);
	add_back(stack, tmp);
	if (i == 1)
		ft_putstr_fd("ra\n", 1);
}

void reverse(stack_node **head_ref)
{
    stack_node *temp = NULL;  
    stack_node *current = *head_ref;

    while (current !=  NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;              
        current = current->prev;
    }      
    
    if(temp != NULL )
    *head_ref = temp->prev;
}

void	pa(t_stack *stack_a, t_stack *stack_b, int i)
{
	t_node	*tmp;

	if (stack_b->head == NULL)
		return ;
	tmp = return_first_node(stack_b);
	add_front(stack_a, tmp);
	if (i == 1)
		ft_putstr_fd("pa\n", 1);
}

void	add_front(t_stack *stack, t_node *new)
{
	t_node	*old_head;

	old_head = stack->head;
	if (new == NULL)
		return ;
	if (stack->head == NULL)
	{
		stack->head = new;
		stack->size = 0;
		stack->last = stack->head;
	}
	else
	{
		old_head->prev = new;
		stack->head = new;
		new->next = old_head;
	}
	stack->size++;
}


// printf("\no                       o\n");
// printf("\no----------a------------o\n");
// printf("\no                       o\n");
// ft_printlist(stack_b);
// printf("\no                       o\n");
// printf("\no----------b------------o\n");
// printf("\no                       o\n");



// if (current->data < min_data)
// {
//     min_data = current->data;
//     if (current->index < (int)half_stack - 1)
//     {
//         indx = current->index;
//         int i;
//         i = 0;
//         while(i++ < indx)
//         {
//             ft_ra(head);
//         }
//     }
//     else
//     {
//         index = current->index;
//         int j;
//         j = 0;
//         while(j++ < index)
//         {
//             ft_rra(head);
//         }
//     }
// }





// stack_node *tmp;
// int min_instr_nmbr;
// tmp = (*stack_a);
// while (tmp)
// {
//     if (tmp->nmbr_of_instr != 0)
//         min_instr_nmbr = tmp->nmbr_of_instr;
//     tmp = tmp->next;
// }


// if (current->nmbr_of_instr != 0)
// {
//     if (current->nmbr_of_instr < min_instr_nmbr)
//     {
//         min_instr_nmbr = current->nmbr_of_instr;
//         printf("%d\n",min_instr_nmbr);
//         if (current->nmbr_of_instr == min_instr_nmbr)
//         {
//             int i;
//             i = 0;
//             while(i++ < min_instr_nmbr)
//                 ft_ra(stack_a);
//             ft_pb(stack_a,stack_b);
//         }
//     }
// }


void	ra(t_infsa *infa)
{
	t_data	data;

	if (infa->len > 1)
	{
		data.tmp = infa->head;
		infa->head = infa->head->next;
		data.tmp2 = infa->tail;
		data.tmp->prev = data.tmp2;
		data.tmp2->next = data.tmp;
		data.tmp->next = NULL;
		infa->tail = data.tmp;
	}
	ft_printf("ra\n");
}


while (current)
{
	printf("%d\n",current->data);
	if (current->index < (int)half_stack)
	{
		printf("les than half----->%d\n",current->data);
		if (current->chk == 0)
		{
			printf("current chk = ----->%d\n",current->data);
			printf("numbr of instructions = ----->%d\n",current->nmbr_of_instr);
			if (current->nmbr_of_instr == 0)
				ft_pb(stack_a,stack_b);
			else
			{
				int i;
				i = 0;
				while (i++ < current->nmbr_of_instr)
				{
					ft_ra(stack_a);
				}
				ft_pb(stack_a,stack_b);
				continue ;
			}
		}
	}
	current = current->next;
}


t_stack_node *get_next_node(t_stack_node *node, t_stack *stack)
{
    if (node == stack->tail)
        return (stack->head)
    return (node->next);
}

// void ft_push(struct stack_node **head, int data)
// {
//     struct stack_node *new_node;

//     new_node = (struct stack_node*)malloc(sizeof(struct stack_node));
//     if(!new_node)
//     {
//         free(new_node);
//         return ;
//     }
//     new_node->data = data;

//     new_node->next = (*head);
//     new_node->prev = NULL;

//     if ((*head) != NULL)
//         (*head)->prev = new_node;

//     (*head) = new_node;
// }

void ft_ra(t_stack *ra)
{
    if (ra->size <= 1)
        return ;
    ra->tail->next = ra->head;
    ra->head->prev = ra->tail;
    ra->head = ra->head->next;
    ra->tail = ra->tail->next;
    ra->head->prev = NULL;
    ra->tail->next = NULL;
    ft_putstr_fd("ra\n", 1);
}

void	sa(t_infsa *infa)
{
	t_data	data;

	if (infa->len > 2)
	{
		data.tmp = infa->head;
		data.tmp2 = data.tmp->next;
		data.tmp3 = data.tmp2->next;
		data.tmp2->next = data.tmp;
		data.tmp->prev = data.tmp2;
		data.tmp->next = data.tmp3;
		data.tmp3->prev = data.tmp;
		infa->head = data.tmp2;
	}
	else if (infa->len == 2)
	{
		data.tmp = infa->head;
		infa->tail = data.tmp;
		infa->head = data.tmp->next;
		infa->head->next = infa->tail;
		infa->tail->prev = infa->head;
		infa->tail->next = NULL;
	}
	ft_printf("sa\n");
}


void	pa(t_infsa *infa, t_infsb *infb)
{
	t_data	data;

	if (infb->len >= 1 && infa->len != 0)
	{
		data.tmp = infb->head;
		data.tmp2 = infa->head;
		infb->head = infb->head->next;
		data.tmp->next = data.tmp2;
		data.tmp2->prev = data.tmp;
		infa->head = data.tmp;
		infa->len++;
		infb->len--;
	}
	else if (infa->len == 0)
	{
		data.tmp = infb->head;
		infa->head = infb->head;
		infb->head = data.tmp->next;
		infa->head->data = data.tmp->data;
		infa->head->next = NULL;
		infa->tail = infa->head;
		infa->len++;
		infb->len--;
	}
	ft_printf("pa\n");
}