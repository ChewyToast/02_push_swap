/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:19:28 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/06/24 12:30:40 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// FUNCTION FILLS THE STACK_A WITH THE INPUT
size_t	fill_stack(char **input, t_stack **stack_a)
{
	size_t	x;

	x = 1;
	*stack_a = create_cont(ft_atoi(input[x]));
	while (input[++x])
	{
		if (!add_at_end(stack_a, create_cont(ft_atoi(input[x]))))
		{
			ft_free(stack_a);
			return (ft_error());
		}
	}
	return (1);
}

// FUNCTION CREATES A NEW STACK ITEM WITH THE NUM OF THE PARAMETER
t_stack	*create_cont(int num)
{
	t_stack	*new_item;

	new_item = malloc(sizeof(t_stack) * 1);
	if (!new_item)
		return (0);
	new_item->num = num;
	new_item->next = NULL;
	return (new_item);
}

// FUNCTION ADDS AT THE END OF THE STACK
size_t	add_at_end(t_stack **stack, t_stack *new_item)
{
	t_stack	*tmp;

	if (!new_item)
		return (0);
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_item;
	return (1);
}

// FUNCTION TO RETURN THE SIZE OF THE STACK
size_t	stack_len(t_stack **stack)
{
	t_stack	*tmp;
	size_t	indx;

	tmp = *stack;
	indx = 0;
	while (tmp)
	{
		tmp = tmp->next;
		indx++;
	}
	return (indx);
}

// FUNCTION TO FREE ALL THE STACK
void	ft_free(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	stack = NULL;
}

// function to see the stack, just a checker for the programer
void	show_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack_a;
	tmp2 = *stack_b;
	printf("\n------------------------------\n");
	printf("\nSTACK A\t\t\tSTACK B");
	while (tmp || tmp2)
	{
		if (tmp)
		{
			printf("\n %d - %zu", tmp->num, tmp->indx);
			tmp = tmp->next;
		}
		else
			printf("\n -");
		if (tmp2)
		{
			printf("\t\t\t%d - %zu", tmp2->num, tmp2->indx);
			tmp2 = tmp2->next;
		}
		else
			printf("\t\t\t-");
	}
	printf("\n\n------------------------------");
} 
