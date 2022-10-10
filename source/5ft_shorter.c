/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5ft_shorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:19:28 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/06/29 21:59:34 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// MAIN FUNCTION OF SHORTING, THERE WE CALL ALL THE SHORTER FUNCTIONS
int	shorter(t_stack **stack_a, t_stack **stack_b)
{
	size_t	i;

	i = stack_len(stack_a);
	put_indx(stack_a);
	if (i == 2)
		two_case(stack_a);
	else if (i == 3)
		tree_case(stack_a);
	else if (i == 4)
		four_case(stack_a, stack_b);
	else if (i == 5)
		five_case(stack_a, stack_b);
	else
		return (short_case(stack_a, stack_b, i));
	return (1);
}

//FUNCTION THAT ADDS A INDX FOR EACH ITEM OF THE STACK
void	put_indx(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	while (tmp)
	{
		tmp2 = *stack;
		tmp->indx = 0;
		while (tmp2)
		{
			if (tmp->num > tmp2->num)
				tmp->indx++;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

// FUNCTION TO CHECK IF THE STACK IS ALREADY SHORTED
int	is_shorted(t_stack **stack)
{
	int		indx;
	t_stack	*tmp;

	tmp = *stack;
	indx = -2147483648;
	while (tmp)
	{
		if (tmp->num >= indx)
		{
			indx = tmp->num;
			tmp = tmp->next;
		}
		else
			return (0);
	}
	return (1);
}
