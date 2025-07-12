/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisaev <aisaev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:40:24 by aisaev            #+#    #+#             */
/*   Updated: 2025/06/14 10:38:55 by aisaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Checks if the given string represents a valid integer number.
 *
 * @param str The input string.
 * @return 1 if it's a valid number, 0 otherwise.
 */
int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Checks if a given value already exists in the stack.
 * Move to the next node
 * @param stack The stack to check.
 * @param value The value to search for.
 * @return 1 if duplicate exists, 0 otherwise.
 */
int	is_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

/**
 * @brief Creates a new node with a given value.
 * Initializes index to -1
 * Usually used later for sorting or marking nodes
 * Sets next pointer to NULL — node is standalone for now
 * -1 means "unset" or "invalid" index.
 * @param value Value to assign to the new node.
 * @return Pointer to the new node, or NULL on failure.
 */
t_stack	*create_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

/**
 * @brief Adds a new node to the bottom of the stack.
 * traverses to the end of the stack and appends the new node.
 * If the stack is empty (*stack == NULL), sets new node as head
 * @param stack Pointer to the stack.
 * @param value Value to add.
 * @return 1 on success, exits on failure.
 */
int	add_node(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = create_node(value);
	if (!new_node)
		exit_error(*stack);
	if (!*stack)
	{
		*stack = new_node;
		return (1);
	}
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = new_node;
	return (1);
}

/**
 * @brief Parses command-line arguments and fills the stack.
 * Add the number to the stack
 * and the string is "2147483648" (just 1 over INT_MAX),
 * the value will overflow.
 * The result will be incorrect and possibly negative.
 * get rid of overflow
 * We use long to detect integer overflows when converting strings
 * @param a Pointer to stack a.
 * @param argv Array of argument strings.
 * @return 1 if successful, 0 if invalid input.
 */
int	parse_args(t_stack **a, char **argv)
{
	int		i;
	long	num;

	i = 0;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (0);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		if (is_duplicate(*a, (int)num))
			return (0);
		if (!add_node(a, (int)num))
			exit_error(*a);
		i++;
	}
	return (1);
}
