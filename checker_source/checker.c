/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:19:03 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/10/07 18:19:19 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../source/push_swap.h"

static ssize_t	ck_startup(char **argv);
static size_t	compare_inp(char *str, t_stack **stack_a, t_stack **stack_b);
static size_t	extra_comp_inp(char *str, t_stack **stack_a, t_stack **stack_b);

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (check_input(argv))
		{
			if (!ck_startup(argv))
				return (ft_error());
		}
		else
			return (ft_error());
	}
	else
		return (0);
	return (0);
}

// FUNCTION TO ORGANIZE PROGRAM PROCESSES
static ssize_t	ck_startup(char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!fill_stack(argv, &stack_a))
		return (ft_error_free(&stack_a, &stack_b));
	if (!checker(&stack_a, &stack_b))
		return (ft_error_free(&stack_a, &stack_b));
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (1);
}

// READ AND EXECUTE FUNCTIONS
size_t	checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (!compare_inp(str, stack_a, stack_b))
		{
			free(str);
			return (0);
		}
		str = get_next_line(0);
	}
	free(str);
	if (is_shorted(stack_a) && !(*stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (1);
}

// FUNCTION TO CHECK THE INPUT VALUE
static size_t	compare_inp(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(str, "sa\n", 0xFFFFFFF))
		return (ck_sab(stack_a));
	else if (!ft_strncmp(str, "sb\n", 0xFFFFFFF))
		return (ck_sab(stack_b));
	else if (!ft_strncmp(str, "ss\n", 0xFFFFFFF))
	{
		if (!ck_sab(stack_a))
			return (0);
		return (ck_sab(stack_b));
	}
	else if (!ft_strncmp(str, "pa\n", 0xFFFFFFF))
		return (ck_pab(stack_a, stack_b));
	else if (!ft_strncmp(str, "pb\n", 0xFFFFFFF))
		return (ck_pab(stack_b, stack_a));
	else if (!ft_strncmp(str, "ra\n", 0xFFFFFFF))
		return (ck_rab(stack_a));
	else if (!ft_strncmp(str, "rb\n", 0xFFFFFFF))
		return (ck_rab(stack_b));
	else
		return (extra_comp_inp(str, stack_a, stack_b));
	return (0);
}

// EXTRA FUNCTION FOR THE INPUT CHECKER
static size_t	extra_comp_inp(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(str, "rr\n", 0xFFFFFFFF))
	{
		if (!ck_rab(stack_a))
			return (0);
		return (ck_rab(stack_b));
	}
	else if (!ft_strncmp(str, "rra\n", 0xFFFFFFFF))
		return (ck_rrab(stack_a));
	else if (!ft_strncmp(str, "rrb\n", 0xFFFFFFFF))
		return (ck_rrab(stack_b));
	else if (!ft_strncmp(str, "rrr\n", 0xFFFFFFFF))
	{
		if (!ck_rrab(stack_a))
			return (0);
		return (ck_rrab(stack_b));
	}
	return (0);
}
