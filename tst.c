

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

void	rra(t_infsa *infa)
{
	t_data	data;

	if (infa->len > 1)
	{
		data.tmp = infa->head;
		data.tmp2 = infa->tail;
		infa->tail = infa->tail->prev;
		data.tmp2->next = data.tmp;
		data.tmp->prev = data.tmp2;
		infa->head = data.tmp2;
		infa->tail->next = NULL;
	}
	ft_printf("rra\n");
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


stack_node *ft_peek(stack_node *head);
stack_node *ft_end(stack_node *head);
void ft_add_after(struct stack_node *prv_node, int data);
void ft_add_before(struct stack_node **head, struct stack_node *nxt_node, int data);
void ft_add_end(struct stack_node **head, int data);
void ft_pop(struct stack_node **head, struct stack_node *node);

stack_node *ft_peek(stack_node *head)
{
    stack_node *first;

    first = (struct stack_node*)malloc(sizeof(struct stack_node));
    if(head == NULL)
        return (NULL);
    if(head->prev == NULL)
    {
        first->prev = NULL;
        first->data = head->data;
        first->next = NULL;
    }
    return(first);
}

stack_node *ft_end(stack_node *head)
{
    stack_node *last;

    last = (struct stack_node*)malloc(sizeof(struct stack_node));
    if(head == NULL)
        return (NULL);
    last = head;
    while (last->next != NULL)
        last = last->next;
    return(last);
}

void ft_add_after(struct stack_node *prv_node, int data)
{
    if (prv_node == NULL)
        return ;
    struct stack_node *new_node;

    new_node = (struct stack_node*)malloc(sizeof(struct stack_node));
    new_node->data = data;
    new_node->next = prv_node->next;
    prv_node->next = new_node;
    new_node->prev = prv_node;

    if(new_node->next != NULL)
        new_node->next->prev = new_node;
}

void ft_add_before(struct stack_node **head, struct stack_node *nxt_node, int data)
{
    if(nxt_node == NULL)
        return ;
    struct stack_node *new_node;

    new_node = (struct stack_node*)malloc(sizeof(struct stack_node));
    new_node->data = data;
    new_node->prev = nxt_node->prev;
    nxt_node->prev = new_node;
    new_node->next = nxt_node;

    if(new_node->prev != NULL)
        new_node->prev->next = new_node;
    else
        (*head) = new_node;
}

void ft_add_end(struct stack_node **head, int data)
{
    struct stack_node *new_node;
    struct stack_node *last;

    new_node = (struct stack_node*)malloc(sizeof(struct stack_node));
    last = *head;
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        return ;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
    return ; 
}

void ft_pop(struct stack_node **head, struct stack_node *node)
{
    if((*head) == NULL || node == NULL)
        return ;
    if((*head) == node)
        (*head) = node->next;
    if(node->next != NULL)
        node->next->prev = node->prev;
    if(node->prev != NULL)
        node->prev->next = node->next;
    free(node);
    return;
}


// t_stack_node *get_stack_node_by_index(t_stack_node *stack_node, int index)
// {
//     int i;

//     i = 0;
//     while (i++ != index && stack_node)
//         stack_node = stack_node->next;
//     return (stack_node);
// }

// void ft_LIS(t_stack_node *stack_a)
// {
//     t_stack_node  *tmp_node;
//     t_stack_node  *head;

//     head = stack_a;
//     tmp_node = stack_a;

//     stack_a = stack_a->next;
//     while (stack_a)
//     {
//         if (tmp_node->lenth < stack_a->lenth)
//             tmp_node = stack_a;
//         stack_a = stack_a->next;
//     }
//     stack_a = tmp_node;
//     while (tmp_node->subsequence >= 0)
//     {
//         tmp_node->chk = 1;
//         tmp_node = get_stack_node_by_index(head, tmp_node->subsequence);
//     }
//     tmp_node->chk = 1;   
// }

// void ft_push_b(t_stack *stack_a,t_stack *stack_b)
// {
//     t_stack_node *current;
//     current = stack_a->head;

//     int half_stack;
//     half_stack = stack_a->size / 2;

//     while (current)
//     {
//         half_stack = stack_a->size / 2;
//         if (current->chk == 0 && current->index < half_stack)
//         {
//             if (current->nmbr_of_instr == 0)
//                 ft_pb(stack_a,stack_b);
//             else
//             {
//                 int i;
//                 i = 0;
//                 while (i++ < current->nmbr_of_instr)
//                 {
//                     ft_ra(stack_a);
//                 }
//                 ft_pb(stack_a,stack_b);
//                 continue ;
//             }
//         }
//         current = current->next;
//     }
// }









  //puch b 
  		// if (current->chk == 0 && current->index < (stack_a->size / 2))
        // {
        //     int i;
        //     i = 0;
        //     while (i++ < current->nmbr_of_instr)
        //         ft_ra(stack_a);
        //     ft_pb(stack_a,stack_b);
        //     ft_index(stack_a);
        //     ft_instructions_number(stack_a);
        //     current = stack_a->head;
        // }
        // else if (current->chk == 0 && current->index > (stack_a->size / 2))
        // {
        //     int j;
        //     j = 0;
        //     while (j++ < current->nmbr_of_instr)
        //         ft_rra(stack_a);
        //     ft_pb(stack_a,stack_b);
        //     ft_index(stack_a);
        //     ft_instructions_number(stack_a);
        //     current = stack_a->head;
        // }
        // else
        //     current = current->next;




// int ft_first_mv(t_stack *stack_a)
// {
//     t_stack_node *head;
//     t_stack_node *tail;
//     int frst_mv;
//     int frst_mv_head;
//     int frst_mv_tail;

//     head = stack_a->head;
//     frst_mv_head = head->nmbr_of_instr;
//     while (head->index < (stack_a->size / 2))
//     {
//         if(head->nmbr_of_instr < frst_mv_head)
//             frst_mv_head = head->nmbr_of_instr;
//         head = head->next;
//     }
//     tail = stack_a->tail;
//     frst_mv_tail = tail->nmbr_of_instr;
//     while(tail->index >= (stack_a->size / 2))
//     {
//         if(tail->nmbr_of_instr < frst_mv_tail)
//             frst_mv_tail = tail->nmbr_of_instr;
//         tail = tail->prev;
//     }
//     if (frst_mv_head < frst_mv_tail)
//         frst_mv = frst_mv_head;
//     else
//         frst_mv = frst_mv_tail;
//     return (frst_mv);
// }



current_b = stack_b->head;
while(current_b)
{
	while (current_head_a)
	{
		if (current_b->data > current_head_a->data && current_b->data < current_head_a->next->data)
			printf("%d\n",current_b->data);
		current_head_a = current_head_a->next;
	}
	current_b = current_b->next;
}

 if (ft_is_betwen_head_tail(current_b,stack_a))
{
	printf("|%d|ghaitkhcha bin lfo9 wltht\n",current_b->data);
}
if (ft_is_betwen_head_hs(current_b,stack_a))
{
	printf("|%d|ghaitkhcha lfo9\n",current_b->data);
}
if (ft_is_betwen_tail_hs(current_b,stack_a))
{
	printf("|%d|ghaitkhcha ltaht\n",current_b->data);
}
else
{
	printf("|%d|ghaitkhcha wra lmax\n",current_b->data);
}



void ft_best_element_in_b(t_stack *stack_a,t_stack *stack_b)
{
    t_stack_node *current_b;

    ft_index(stack_b);
    ft_instructions_number(stack_b);
    current_b = stack_b->head;
    while(current_b)
    {
        if (ft_is_betwen_head_tail(current_b,stack_a))
        {
            printf("|%d|ghaitkhcha bin lfo9 wltht\n",current_b->data);
        }
        else if (ft_is_betwen_head_hs(current_b,stack_a))
        {
            printf("|%d|ghaitkhcha lfo9\n",current_b->data);
        }
        else if (ft_is_betwen_tail_hs(current_b,stack_a))
        {
            printf("|%d|ghaitkhcha ltaht\n",current_b->data);
        }
        else
        {
            ft_max_of_stacks(current_b,stack_a);
            printf("|%d|ghaitkhcha wra lmax\n",current_b->data);
        }
        current_b = current_b->next;
    }
    ft_first_mv_sb(stack_b);
    // ft_push_a(stack_a,stack_b);
    ft_printlist(stack_b);
    // ft_first_mv(stack_b);
}








// void ft_is_betwen_head_hs(t_stack_node *stack_b,t_stack *stack_a)
// {
//     t_stack_node *current_head_a;
//     t_stack_node *current_next_a;

//     int i;
//     i = 0;
//     current_head_a = stack_a->head;
//     while(current_head_a && ++i < (stack_a->size / 2))
//     {
//         current_next_a = current_head_a->next;
//         while (current_next_a && i < (stack_a->size / 2))
//         {
//             if (stack_b->data > current_head_a->data && stack_b->data < current_next_a->data)
//             {
//                 stack_b->tmp[0] = current_head_a->next->nmbr_of_instr;
//                 stack_b->tmp[1] = stack_b->nmbr_of_instr;
//             }
//             current_next_a = current_next_a->next;
//             break;
//         }
//         current_head_a = current_head_a->next;
//     }
// }

// void ft_is_betwen_tail_hs(t_stack_node *stack_b,t_stack *stack_a)
// {
//     t_stack_node *current_tail_a;
//     t_stack_node *current_prev_a;

//     int i;
//     i = stack_a->size;
//     current_tail_a = stack_a->tail;
//     while(current_tail_a && --i > (stack_a->size / 2))
//     {
//         current_prev_a = current_tail_a->prev;
//         while (current_prev_a && i > (stack_a->size / 2))
//         {
//             if (stack_b->data > current_prev_a->data && stack_b->data < current_tail_a->data)
//             {
//                 stack_b->tmp[0] = current_prev_a->nmbr_of_instr;
//                 stack_b->tmp[1] = stack_b->nmbr_of_instr;
//             }
//             current_prev_a = current_prev_a->prev;
//             break;
//         }
//         current_tail_a = current_tail_a->prev;
//     }
// }



// void ft_max_of_stacks(t_stack_node *stack_b,t_stack *stack_a)
// {
//     t_stack_node *current_head_a;

//     current_head_a = stack_a->head;
//     while(current_head_a)
//     {
//         if(current_head_a->data == ft_max_data(stack_a))
//         {
//             stack_b->tmp[0] = current_head_a->nmbr_of_instr;
//             stack_b->tmp[1] = stack_b->nmbr_of_instr;
//         }
//         current_head_a = current_head_a->next;
//     }
// }



void ft_first_mv_sb(t_stack *stack_a,t_stack *stack_b, t_best_mv *best)
{
    int node_instr;
    t_stack_node    *tmp_node;
    int             i;
    
    ft_max_data_nbr_istr(stack_a);
    ft_instructions_number(stack_a);
    ft_best_element_in_b(stack_a,stack_b);
    tmp_node = stack_b->head;
    node_instr = my_abs(tmp_node->tmp[0]) + my_abs(tmp_node->tmp[1]);
    
    best->data = tmp_node->data;
    best->index = tmp_node->index;
    best->nmb_inst = tmp_node->tmp[0];
    i = -1;
    while (++i < stack_b->size)
    {
        if ((my_abs(tmp_node->tmp[0]) + my_abs(tmp_node->tmp[1])) < my_abs(node_instr))
        {
            node_instr = my_abs(tmp_node->tmp[0]) + my_abs(tmp_node->tmp[1]);
            best->data = tmp_node->data;
            best->index = tmp_node->index;
            best->nmb_inst = tmp_node->tmp[0];
        }
        tmp_node = tmp_node->next;
    }
}

void ft_push_a(t_stack *stack_a,t_stack *stack_b)
{
    t_best_mv best; 
    t_stack_node *current_b;
    current_b = stack_b->head;

    ft_max_data_nbr_istr(stack_a);
    ft_best_element_in_b(stack_a,stack_b);
    ft_first_mv_sb(stack_a,stack_b, &best);
    while(current_b->data != best.data)
    {
        if(best.index < (stack_b->size / 2))
            ft_rb(stack_b);
        else
            ft_rrb(stack_b);
        current_b = stack_b->head;
    }
    while(stack_b->size != 0)
    {
        if(best.nmb_inst >= 0)
        {
            while(best.nmb_inst != 0)
            {
                ft_ra(stack_a);
                best.nmb_inst--;
            }
            ft_pa(stack_a, stack_b);
        }
        else if (best.nmb_inst < 0)
        {
            int j = my_abs(best.nmb_inst);
            while ( j != 0)
            {
                ft_rra(stack_a);
                j--;
            }
            ft_pa(stack_a, stack_b);
        }
        if(stack_b->size == 0)
            break ;
        ft_max_data_nbr_istr(stack_a);
        ft_best_element_in_b(stack_a,stack_b);
        ft_first_mv_sb(stack_a,stack_b, &best);
        // break ; 
        while(current_b->data != best.data)
        {
            if (best.index < (stack_b->size / 2))
                ft_rb(stack_b);
            else
                ft_rrb(stack_b);
            current_b = stack_b->head;
        }
    }
    // ft_printlist(stack_b);
}


// void ft_rra(t_stack *rra)
// {
//     t_stack_node *tmp;

//     if (rra->size <= 1)
//         return ;
//     tmp = rra->tail;
//     tmp->next = rra->head;
//     rra->head->prev = tmp;
//     rra->tail->prev->next = NULL;
//     rra->head = tmp;
//     rra->head->prev = NULL;
//     ft_putstr_fd("rra\n", 1);
// }