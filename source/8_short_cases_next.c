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
	if ((*stack_a)->indx >= min && (*stack_a)->indx <= max)
	{
		ft_pab(stack_b, stack_a, 0);
		return (1);
	}
	else
		ft_rab(stack_a, 1);
	return (0);
}

// SHORTER FOR MORE THAN 6 NUMBERS
void	next_cases(t_stack **stack_a, t_stack **stack_b, size_t chunck_size)
{
	size_t	n_chunck;
	size_t	count;

	count = 0;
	n_chunck = 0;
	while ((*stack_a))
	{
		if (1)
		{
			if (n_chunck == 0)
				count += extra_next_case(stack_a, stack_b, 0, chunck_size);
			else if (n_chunck == 1)
				count += extra_next_case(stack_a, stack_b, chunck_size, chunck_size * 2);
			else if (n_chunck == 2)
				count += extra_next_case(stack_a, stack_b, chunck_size * 2, chunck_size * 3);
			else if (n_chunck == 3)
				count += extra_next_case(stack_a, stack_b, chunck_size * 3, chunck_size * 4);
			if (count == chunck_size)
			{
				count = 0;
				n_chunck++;
			}
			//show_stack(stack_a, stack_b);
		}
	}
}
