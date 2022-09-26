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
	if ((*stack_a)->indx >= min && (*stack_a)->indx <= max - 1)
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
	while (!is_shorted(stack_a) && n_chunck <= 3)
	{
		printf("\nnum: %d, ind: %zu, chunck_size: %zu\n", (*stack_a)->num, (*stack_a)->indx, chunck_size);
		//show_stack(stack_a, stack_b);
		if (stack_len(stack_a) == 2)
			ft_sab(stack_a, 1);
		else
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
			show_stack(stack_a, stack_b);
			printf("\nn_chunk: %zu, counter: %zu, chunck_size: %zu\n", n_chunck, count, chunck_size);
		}
	}
}


				/* if ((*stack_a)->indx >= 0 && (*stack_a)->indx <= chunck_size)
				{
					ft_pab(stack_b, stack_a, 0);
					//if (!((*stack_b)->indx >= 0 && (*stack_b)->indx <= chunck_size / 2))
					//	ft_rrab(stack_b, 0);
					count++;
				}
				else
					ft_rab(stack_a, 1); */
