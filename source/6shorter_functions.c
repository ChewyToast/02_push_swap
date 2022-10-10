/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6shorter_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 22:10:56 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/06/29 22:11:15 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// FUNCTION TO FIND THE SMALLEST NUM OF THE STACK
size_t	find_smallest(t_stack **stack)
{
	size_t	smallest;
	t_stack	*stk;

	stk = *stack;
	smallest = 0;
	while (stk)
	{
		if (stk->indx == 0)
			break ;
		smallest++;
		stk = stk->next;
	}
	return (smallest);
}

// FUNCTION TO FIND THE BIGGER NUM OF THE STACK
size_t	find_bigger(t_stack **stack)
{
	char	contr;
	size_t	bigger;
	t_stack	*tmp;
	t_stack	*tmp2;

	bigger = 0;
	tmp = *stack;
	while (tmp)
	{
		contr = 0;
		tmp2 = *stack;
		while (tmp2)
		{
			if (tmp->indx < tmp2->indx)
				contr = 1;
			tmp2 = tmp2->next;
		}
		if (!contr)
			break ;
		bigger++;
		tmp = tmp->next;
	}
	return (bigger);
}

// FUNCTION TO FIND THE SECOND BIGGER NUMBER OF A STACK
int	find_second_bigger(t_stack **stack, size_t bigger_pos)
{
	int		rtrn;
	t_stack	*bigger_stack;
	t_stack	*tmp;

	tmp = *stack;
	rtrn = -2147483648;
	bigger_stack = *stack;
	while (bigger_pos)
	{
		bigger_stack = bigger_stack->next;
		bigger_pos--;
	}
	while (tmp)
	{
		if (tmp->num > rtrn && tmp->num < bigger_stack->num)
			rtrn = tmp->num;
		tmp = tmp->next;
	}
	return (rtrn);
}

// FUNCTION TO FIND THE THIRD BIGGER NUMBER OF A STACK
int	find_third_bigger(t_stack **stack, int scnd_bigg)
{
	int		numb;
	t_stack	*tmp;

	numb = -2147483648;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->num < scnd_bigg && tmp->num > numb)
			numb = tmp->num;
		tmp = tmp->next;
	}
	return (numb);
}
