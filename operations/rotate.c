/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisaev <aisaev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:16:11 by aisaev            #+#    #+#             */
/*   Updated: 2025/06/13 16:33:12 by aisaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief Rotates stack a (first element becomes the last).
 * save the top of the stack in first
 * second element becomes the new top of the stack
 * cut first from the rest of the stack.
 * We start from the top of stack A.
 * While the current element has a next, we go forward.
 * Move to the next element.
 * Go through the stack to find the last element
 * after the loop, last points to the last node of the stack.
 * add first at the end of the stack.
 * @param a Pointer to stack a.
 */
void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	*a = first->next;
	first->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	write(1, "ra\n", 3);
}

/**
 * @brief Rotates stack b (first element becomes the last).
 *
 * @param b Pointer to stack b.
 */
void	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	*b = first->next;
	first->next = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
	write(1, "rb\n", 3);
}

/**
 * @brief Performs a rotate operation on both stack a and stack b.
 *
 * @param a Pointer to stack a.
 * @param b Pointer to stack b.
 */
void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
