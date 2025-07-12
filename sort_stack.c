/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisaev <aisaev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:39:55 by aisaev            #+#    #+#             */
/*   Updated: 2025/06/15 14:46:55 by aisaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Calculates the size of the stack.
 * We increase the counter for each node
 * After the loop, return the total number of elements in the stack
 * Move to the next node in the list
 * @param stack Pointer to the stack.
 * @return Number of nodes in the stack.
 */
int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

/**
 * @brief Checks whether the stack is sorted in ascending order.
 * Move to the next element and continue checking
 * @param stack Pointer to the stack.
 * @return 1 if sorted, 0 otherwise.
 */
int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/**
 * @brief Main sort dispatcher based on the size of the stack.
 *
 * @param a Pointer to stack a.
 * @param b Pointer to stack b.
 */
void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (is_sorted(*a))
		return ;
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	else if (size == 3)
		sort_three(a);
	else if (size >= 4 && size <= 50)
		sort_small(a, b);
	else
		radix_sort(a, b);
}
