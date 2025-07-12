/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisaev <aisaev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:11:07 by aisaev            #+#    #+#             */
/*   Updated: 2025/06/15 15:04:11 by aisaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Finds the position (index) of the smallest value in the stack.
 *
 * This function iterates through the given stack (implemented as a linked list),
 * compares each node's value, and keeps track of the smallest value found.
 * It returns the zero-based position (index) of the node that contains
 * the smallest value.
 *
 * Example:
 * If the stack contains the values [5, 3, 9, 2], the function returns 3,
 * since 2 is the smallest value and is at index 3.
 *
 * @param stack A pointer to the head of the stack (linked list).
 * @return The index (starting from 0) of the node with the smallest value.
 */
int	find_min_index(t_stack *stack)
{
	int	min;
	int	index;
	int	pos;

	min = stack->value;
	index = 0;
	pos = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			pos = index;
		}
		stack = stack->next;
		index++;
	}
	return (pos);
}

/**
 * @brief Moves the element at a given position to the top of the stack.
 *
 * This function rotates the stack either forwards (using `ra`)
 * or backwards (using `rra`) to bring the element at position `pos`
 * to the top of the stack in the most efficient way (with the fewest moves).
 *
 * For positions closer to the top (i.e., <= size / 2), it uses `ra`.
 * For positions closer to the bottom, it uses `rra`.
 *
 * @param stack A pointer to the pointer of the stack.
 * @param pos The index (starting from 0) of the element to move to the top.
 */
void	move_to_top(t_stack **stack, int pos)
{
	int	size;

	size = stack_size(*stack);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(stack);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(stack);
	}
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

/**
 * @brief Sorts a small stack of up to 5 elements using an efficient strategy.
 *
 * This function is used when the number of elements in stack A
 * is small (typically 4 or 5).
 * It repeatedly finds and pushes the smallest elements to stack B
 * until only 3 are left in A.
 * Then it sorts the remaining 3 elements using a simple sort.
 * If stack B has 2 elements in the wrong order, it swaps them.
 * Finally, it pushes all elements back to A, resulting in a sorted stack.
 *
 * @param a A double pointer to the primary stack (stack A).
 * @param b A double pointer to the auxiliary stack (stack B).
 */
void	sort_small(t_stack **a, t_stack **b)
{
	int	pos;

	while (stack_size(*a) > 3)
	{
		pos = find_min_index(*a);
		move_to_top(a, pos);
		pb(a, b);
	}
	sort_three(a);
	while (stack_size(*b) > 0)
		pa(a, b);
}
