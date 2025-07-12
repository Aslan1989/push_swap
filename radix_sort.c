/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisaev <aisaev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:41:35 by aisaev            #+#    #+#             */
/*   Updated: 2025/06/15 15:03:33 by aisaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Finds and assigns index to the minimum unindexed node.
 * It finds the smallest element in the stack without an index,
 * and gives it index i
 * tmp: to walk through the stack,
 * min_node: to save the smallest node,
 * min: to save the smallest value we find (start with a big number)
 * Set min to the biggest possible number
 * Update the current minimum and remember the node
 * Go to the next element in the stack
 * If we found a minimum — assign it index i
 * @param stack Stack to operate on.
 * @param i Index to assign.
 */
void	find_and_assign_min(t_stack *stack, int i)
{
	t_stack	*tmp;
	t_stack	*min_node;
	int		min;

	tmp = stack;
	min = INT_MAX;
	min_node = NULL;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->value < min)
		{
			min = tmp->value;
			min_node = tmp;
		}
		tmp = tmp->next;
	}
	if (min_node)
		min_node->index = i;
}

/**
 * @brief Assigns indexes to all nodes based on their sorted position.
 * If the stack is empty, do nothing
 * Get the total number of elements in the stack
 * Each time, find the smallest unindexed value and
 * assign it the next available index (i).
 * Move to the next index
 * @param stack Pointer to the stack.
 */
void	assign_indexes(t_stack *stack)
{
	int	i;
	int	size;

	if (!stack)
		return ;
	size = stack_size(stack);
	i = 0;
	while (i < size)
	{
		find_and_assign_min(stack, i);
		i++;
	}
}

/**
 * @brief Sorts a stack using radix sort algorithm.
 * Radix sort works by sorting the elements based on
 * their indexes using binary digits.
 * We assign each number an index from 0 to N-1,
 * and we sort from the least significant bit to the most significant.
 * For each bit, we check whether it is 0 or 1 using bitwise operators:
 * (num >> i) & 1.
 * The outer loop goes through each bit position
 * (from least significant to most significant).
 * The inner loop checks every element and pushes it
 * to stack b if its bit at position i is 0, otherwise
 * it rotates it in stack a. After that, all elements from b are
 * pushed back to a, and the next bit is processed.
 * This simulates a binary radix sort
 * If it’s 0, we push to stack B; if it’s 1, we rotate stack A.
 * After each bit pass, we return all elements from B to A.
 * @param a Pointer to stack a.
 * @param b Pointer to stack b.
 */
void	radix_sort(t_stack **a, t_stack **b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;
	int	num;

	size = stack_size(*a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			num = (*a)->index;
			if ((num >> i) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (stack_size(*b) != 0)
			pa(a, b);
	}
}
