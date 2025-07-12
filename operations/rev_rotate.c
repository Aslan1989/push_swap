/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisaev <aisaev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:16:29 by aisaev            #+#    #+#             */
/*   Updated: 2025/06/13 16:25:02 by aisaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief Rotates stack a in reverse (last element becomes the first).
 * We set last to the top of the stack.
 * We set prev to NULL for now.
 * last becomes the last node.
 * prev becomes the second-to-last.
 * We break the link between prev and last
 * insert last to the old top of the stack
 * @param a Pointer to stack a.
 */
void	rra(t_stack **a)
{
	t_stack	*prev;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	prev = NULL;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "rra\n", 4);
}

/**
 * @brief Rotates stack b in reverse (last element becomes the first).
 *
 * @param b Pointer to stack b.
 */
void	rrb(t_stack **b)
{
	t_stack	*prev;
	t_stack	*last;

	if (!*b || !(*b)->next)
		return ;
	prev = NULL;
	last = *b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
	write(1, "rrb\n", 4);
}

/**
 * @brief Performs reverse rotation on both stack a and stack b.
 *
 * @param a Pointer to stack a.
 * @param b Pointer to stack b.
 */
void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
