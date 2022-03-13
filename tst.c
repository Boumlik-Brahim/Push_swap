

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