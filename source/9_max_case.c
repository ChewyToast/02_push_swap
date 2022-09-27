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

// SHORTER FOR MORE THAN 6 NUMBERS
void	next_casess(t_stack **stack_a, t_stack **stack_b, size_t chunck_size)
{
	size_t	chunck_start;
	size_t	count;
	size_t	iter;

	count = 0;
	iter = 0;
	chunck_start = 0;
	while (*stack_a)
	{
		count += extra_next_case(stack_a, stack_b, chunck_start, chunck_size);
		if (count == chunck_size)
		{
			count = 0;
			iter++;
			chunck_start = chunck_size * iter;
		}
	}
	smart_refill(stack_a, stack_b);


