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

//CASE OF ONLY TWO STACK ELEMENTS
void	two_case(t_stack **stack_a)
{
	if ((*stack_a)->indx == 1)
		ft_sab(stack_a, 1);
}

//CASE OF ONLY TREE STACK ELEMENTS
void	tree_case(t_stack **stack_a)
{
	if (!is_shorted(stack_a))
	{
		if ((*stack_a)->indx == 0)
		{
			ft_rrab(stack_a, 1);
			ft_sab(stack_a, 1);
		}
		else if ((*stack_a)->indx == 1)
		{
			if ((*stack_a)->next->indx == 0)
				ft_sab(stack_a, 1);
			else
				ft_rrab(stack_a, 1);
		}
		else if ((*stack_a)->indx == 2)
		{
			if ((*stack_a)->next->indx == 1)
			{
				ft_rab(stack_a, 1);
				ft_sab(stack_a, 1);
			}
			else
				ft_rab(stack_a, 1);
		}
	}
}

//CASE OF ONLY FOUR STACK ELEMENTS
void	four_case(t_stack **stack_a, t_stack **stack_b)
{
	size_t	indx;

	indx = find_smallest(stack_a);
	if (indx == 1)
		ft_sab(stack_a, 1);
	else if (indx == 2)
	{
		ft_rab(stack_a, 1);
		ft_rab(stack_a, 1);
	}
	else if (indx == 3)
	{
		ft_rrab(stack_a, 1);
	}
	if (!is_shorted(stack_a))
	{
		ft_pab(stack_b, stack_a, 2);
		put_indx(stack_a);
		tree_case(stack_a);
		ft_pab(stack_a, stack_b, 1);
	}
}

//CASE OF ONLY FIVE STACK ELEMENTS
void	five_case(t_stack **stack_a, t_stack **stack_b)
{
	size_t	indx;

	indx = find_smallest(stack_a);
	if (indx == 1)
		ft_sab(stack_a, 1);
	else if (indx == 2)
	{
		ft_rab(stack_a, 1);
		ft_rab(stack_a, 1);
	}
	else if (indx == 3)
	{
		ft_rrab(stack_a, 1);
		ft_rrab(stack_a, 1);
	}
	else if (indx == 4)
		ft_rrab(stack_a, 1);
	if (!is_shorted(stack_a))
	{
		ft_pab(stack_b, stack_a, 2);
		put_indx(stack_a);
		four_case(stack_a, stack_b);
		ft_pab(stack_a, stack_b, 1);
	}
}

//FUNCTION TO SEE IF IS A SHORT CASE AND SELECT THE CASE
int	short_case(t_stack **stack_a, t_stack **stack_b, size_t i)
{
	if (i >= 6 && i <= 200 && !is_shorted(stack_a))
	{
		if (!(i % 4))
			next_cases(stack_a, stack_b, i / 4);
		else
			next_cases(stack_a, stack_b, i / 4 + 1);
	}
	else if (i >= 201 && !is_shorted(stack_a))
	{
		if (!(i % 4))
			next_cases(stack_a, stack_b, i / 9);
		else
			next_cases(stack_a, stack_b, i / 9 + 1);
	}
	return (1);
}
