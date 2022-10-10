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

// EXTRA FUNTION FOR THE IF OF THE SMART REFILL
static void	extra_extra_re(t_stack **stack_a, t_stack **stack_b, t_refill *ref);
// EXTRA FUNCTION FOR SMART_REFILL()
static char	extra_smart_re(t_stack **stack_a, t_stack **stack_b, t_refill *ref);

// WILDCARD FUNCTION FOR THE NEXT_CASE()
static size_t	extra_next_case(t_stack **stack_a, t_stack **stack_b,
					size_t min, size_t max)
{
	int	i;

	i = 0;
	if ((*stack_a)->indx >= min && (*stack_a)->indx < max)
	{
		ft_pab(stack_b, stack_a, 0);
		if ((stack_len(stack_a) > 1) && (!((*stack_a)->indx >= min)
				&& ((*stack_a)->indx < max)))
			i++;
		if (((*stack_b)->indx) <= ((max - min) / 2) + min)
		{
			if (i)
			{
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
		count += extra_next_case(stack_a, stack_b,
				chunck_size * iter, chunck_size * (iter + 1));
		if (count == chunck_size)
		{
			count = 0;
			iter++;
		}
	}
	smart_refill(stack_a, stack_b);
}

// FUNCTION TO REFILL THE STACK A IN THE CORRECT ORDER
void	smart_refill(t_stack **stack_a, t_stack **stack_b)
{
	t_refill	ref;

	ref.opti = 0;
	ref.optimax = 0;
	while (*stack_b)
	{
		ref.finder = find_bigger(stack_b);
		ref.scnd = find_second_bigger(stack_b, ref.finder);
		ref.thrd = find_third_bigger(stack_b, ref.scnd);
		if (ref.finder)
			extra_extra_re(stack_a, stack_b, &ref);
		else
			ref.opti = extra_smart_re(stack_a, stack_b, &ref);
	}
	if (!is_shorted(stack_a) && ref.optimax == 3)
		ft_rrab(stack_a, 1);
	else if (!is_shorted(stack_a) && ref.optimax == 2)
	{
		ft_sab(stack_a, 1);
		ft_rrab(stack_a, 1);
	}
}

// EXTRA FUNTION FOR THE IF OF THE SMART REFILL
static void	extra_extra_re(t_stack **stack_a, t_stack **stack_b, t_refill *ref)
{
	if ((*stack_b)->num == ref->thrd && ref->opti == 0 && ref->optimax == 0)
	{
		ft_pab(stack_a, stack_b, 1);
		ft_rab(stack_a, 1);
		ref->optimax = 1;
	}
	else if (((*stack_b)->num == ref->scnd)
		&& (ref->opti == 0) && (ref->optimax == 1))
	{
		ft_pab(stack_a, stack_b, 1);
		ref->optimax = 2;
	}
	else if (((*stack_b)->num == ref->scnd)
		&& (ref->opti == 0) && (ref->optimax == 0))
	{
		ft_pab(stack_a, stack_b, 1);
		ref->opti = 1;
	}
	else
	{
		if (ref->finder < ((stack_len(stack_b) / 2) + (stack_len(stack_b) % 2)))
			ft_rab(stack_b, 0);
		else
			ft_rrab(stack_b, 0);
	}
}

// EXTRA FUNCTION FOR SMART_REFILL()
static char	extra_smart_re(t_stack **stack_a, t_stack **stack_b, t_refill *ref)
{
	ft_pab(stack_a, stack_b, 1);
	if (ref->optimax == 1 && ref->opti == 0)
	{
		ref->optimax = 3;
	}
	else if (ref->optimax == 2 && ref->opti == 0)
	{
		ft_sab(stack_a, 1);
		ft_rrab(stack_a, 1);
		ref->optimax = 0;
	}
	else if (ref->optimax == 3)
	{
		ft_rrab(stack_a, 1);
		ref->optimax = 0;
	}
	else if (ref->opti == 1 && ref->optimax == 0)
	{
		ref->opti = 0;
		ft_sab(stack_a, 1);
	}
	return (ref->opti);
}
