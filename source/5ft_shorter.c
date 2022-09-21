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
	put_indx(stack_a, stack_len(stack_a));
	if (!short_case(stack_a, stack_b))
	{
		while ((!is_shorted(stack_a) || (*stack_b)))
		{
			if (stack_len(stack_a) > 1 && !is_shorted(stack_a))
			{
				if (!filling_stack_b(stack_a, stack_b))
					return (0);
			}
			else
			{
				if (!refill_a(stack_a, stack_b))
					return (0);
			}
		}
	}
	return (1);
}

//printf("\nnum: %d, compare with %d, indx: %d, len: %zu\n",
//tmp->num, tmp2->num, tmp->indx, stackln);
//printf("\nnum: %d, indx: %d, len: %zu\n", tmp->num, tmp->indx, stackln);
//FUNCTION THAT ADDS A INDX FOR EACH ITEM OF THE STACK
void	put_indx(t_stack **stack, size_t stackln)
{
	size_t	size;
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	while (tmp)
	{
		tmp->indx = 0;
		size = stackln - 1;
		if (tmp->next)
			tmp2 = tmp->next;
		else
			tmp2 = *stack;
		while (size--)
		{
			if (tmp->num > tmp2->num)
				tmp->indx++;
			if (!(tmp2->next))
				tmp2 = *stack;
			else
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
