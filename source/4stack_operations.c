/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:19:28 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/06/24 12:30:40 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// FUNCTION SWAPS THE TWO FIRST ELEMENTS OF THE STACK
void	ft_sab(t_stack **stack, char mode)
{
	t_stack	*tmp;

	if ((*stack) && ((*stack)->next))
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *(stack);
		*stack = tmp;
		if (mode == 1)
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
	}
}

// FUNCTION ADDS AT THE TOP OF THE STACK_DEST THE FIRST ITEM OF STACK_ORIGIN
void	ft_pab(t_stack **stack_dest, t_stack **stack_origin, char mode)
{
	t_stack	*tmp;

	if (*stack_origin && *stack_dest)
	{
		tmp = *stack_origin;
		(*stack_origin) = (*stack_origin)->next;
		tmp->next = *stack_dest;
		*stack_dest = tmp;
	}
	else if (*stack_origin && !(*stack_dest))
	{
		*stack_dest = *stack_origin;
		*stack_origin = (*stack_origin)->next;
		(*stack_dest)->next = NULL;
	}
	if (mode == 1)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

// FUNCTION TO SHIFT UP ALL THE ELEMENTS OF THE STACK
void	ft_rab(t_stack **stack, char mode)
{
	t_stack	*tmp;

	if (*stack && ((*stack)->next))
	{
		tmp = *stack;
		*stack = (*stack)->next;
		add_at_end(stack, tmp);
		tmp->next = NULL;
	}

	if (mode == 50)
		write(1, "rr\n", 3);
	else if (mode == 1)
		write(1, "ra\n", 3);
	else if (mode == 0)
		write(1, "rb\n", 3);
}

// FUNCTION TO SHIFT DOWN ALL THE ELEMENTS OF THE STACK
void	ft_rrab(t_stack **stack, char mode)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*stack && ((*stack)->next))
	{
		tmp = *stack;
		tmp2 = tmp->next;
		while (tmp2->next)
		{
			tmp = tmp->next;
			tmp2 = tmp->next;
		}
		tmp->next = NULL;
		tmp2->next = *stack;
		*stack = tmp2;
	}
	if (mode == 1)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}
