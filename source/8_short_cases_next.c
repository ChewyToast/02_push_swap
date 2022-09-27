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
	if ((*stack_a)->indx >= min && (*stack_a)->indx < max)
	{
		ft_pab(stack_b, stack_a, 0);
		if (((*stack_b)->indx) <= ((max - min) / 2) + min)
			ft_rab(stack_b, 0);
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
	while (*stack_a)
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
	}
	smart_refill(stack_a, stack_b);
	//show_stack(stack_a, stack_b);
	//printf("\nCHUNK SIZE = %zu, n of numbers: %zu, bigger pos: %zu\n", chunck_size, stack_len(stack_b), find_bigger(stack_b));
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
			ft_pab(stack_a, stack_b, 1);
	}
}
