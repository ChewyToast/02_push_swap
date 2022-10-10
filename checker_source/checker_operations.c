/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:19:03 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/10/07 18:19:19 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../source/push_swap.h"

// FUNCTION SWAPS THE TWO FIRST ELEMENTS OF THE STACK
size_t	ck_sab(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return (0);
	if ((*stack) && ((*stack)->next))
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *(stack);
		*stack = tmp;
	}
	return (1);
}

// FUNCTION ADDS AT THE TOP OF THE STACK_DEST THE FIRST ITEM OF STACK_ORIGIN
size_t	ck_pab(t_stack **stack_dest, t_stack **stack_origin)
{
	t_stack	*tmp;

	if (!stack_origin || !(*stack_origin))
		return (0);
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
	return (1);
}

// FUNCTION TO SHIFT UP ALL THE ELEMENTS OF THE STACK
size_t	ck_rab(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return (0);
	if (*stack && ((*stack)->next))
	{
		tmp = *stack;
		*stack = (*stack)->next;
		add_at_end(stack, tmp);
		tmp->next = NULL;
	}
	return (1);
}

// FUNCTION TO SHIFT DOWN ALL THE ELEMENTS OF THE STACK
size_t	ck_rrab(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!stack || !(*stack))
		return (0);
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
	return (1);
}
