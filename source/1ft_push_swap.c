/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:19:28 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/06/24 12:30:21 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// MAIN FUNCTION, THERE WE SEE THE NUM OF ARGS AND START THE PROGRAM
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (check_input(argv))
		{
			if (!startup(argv))
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
ssize_t	startup(char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!fill_stack(argv, &stack_a))
		return (ft_error_free(&stack_a, &stack_b));
	if (!shorter(&stack_a, &stack_b))
		return (ft_error_free(&stack_a, &stack_b));
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (1);
}

// FUNTION TO SHOW THE ERROR MSG AND RETURN -1
size_t	ft_error_free(t_stack **stack_a, t_stack **stack_b)
{
	ft_free(stack_a);
	ft_free(stack_b);
	return (0);
}

// FUNTION TO SHOW THE ERROR MSG AND RETURN -1
size_t	ft_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}
