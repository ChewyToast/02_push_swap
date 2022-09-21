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
	int		n_to_compare;
	size_t	indx;
	size_t	rtrn;
	t_stack	*tmp;

	tmp = *stack;
	n_to_compare = 2147483647;
	indx = 0;
	rtrn = 0;
	while (tmp)
	{
		if (tmp->num < n_to_compare)
		{
			n_to_compare = tmp->num;
			rtrn = indx;
		}
		tmp = tmp->next;
		indx++;
	}
	return (rtrn);
}

// FUNCTION PASS THE STACK_A TO STACK_B IN DESCENDING ORDER
int	filling_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	size_t	indx;

	indx = find_smallest(stack_a);
	if (!indx)
		ft_pab(stack_b, stack_a, 2);
	else if (indx <= (stack_len(stack_a) / 2))
		ft_rab(stack_a, 1);
	else
		ft_rrab(stack_a, 1);
	return (1);
}

// FUNCTION TO PASS TO THE STACK_A, ALL THE ITEMS IN THE CORRECT ORDER
int	refill_a(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
		ft_pab(stack_a, stack_b, 1);
	return (1);
}
