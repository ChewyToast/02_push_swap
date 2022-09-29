/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_short_cases_next.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:26:28 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/09/26 16:27:02 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// WILDCARD FUNCTION FOR THE NEXT_CASE()
static size_t	extra_next_case(t_stack **stack_a, t_stack **stack_b, size_t min, size_t max)
{
	int	i;

	i = 0;
	if ((*stack_a)->indx >= min && (*stack_a)->indx < max)
	{
		ft_pab(stack_b, stack_a, 0);
		if (stack_len(stack_a) > 1 && !((*stack_a)->indx >= min && (*stack_a)->indx < max))
			i++;
		if (((*stack_b)->indx) <= ((max - min) / 2) + min)
		{
			if (i)
			{
				//printf("\n1 - OPTI\n");
				ft_rab(stack_a, 50);
				ft_rab(stack_b, 2);
			}
			else if (stack_len(stack_b) > 1)
				ft_rab(stack_b, 0);
		}
		return (1);
	}
	else
		ft_rab(stack_a, 1);
	return (0);
}

// SHORTER FOR MORE THAN 6 NUMBERS
void	next_cases(t_stack **stack_a, t_stack **stack_b, size_t chunck_size)
{
	size_t	count;
	size_t	iter;

	count = 0;
	iter = 0;
	while (*stack_a)
	{
		count += extra_next_case(stack_a, stack_b, chunck_size * iter, chunck_size * (iter + 1));
		if (count == chunck_size)
		{
			count = 0;
			iter++;
		}
		//show_stack(stack_a,stack_b);
	}
	smart_refill(stack_a, stack_b);
	//show_stack(stack_a,stack_b);
}

// FUNCTION TO REFILL THE STACK A IN THE CORRECT ORDER
void	smart_refill(t_stack **stack_a, t_stack **stack_b)
{
	size_t	finder;
	
	while (*stack_b)
	{
		finder = find_bigger(stack_b);
		if (finder)
		{
			if (finder < ((stack_len(stack_b) / 2) + (stack_len(stack_b) % 2)))
				ft_rab(stack_b, 0);
			else
				ft_rrab(stack_b, 0);
		}
		else
		{
			ft_pab(stack_a, stack_b, 1);
		}
		//show_stack(stack_a,stack_b);
	}
}