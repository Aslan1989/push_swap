/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisaev <aisaev@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:44:24 by aisaev            #+#    #+#             */
/*   Updated: 2025/06/16 12:41:21 by aisaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Handles a single string containing multiple space-separated integers.
 *
 * This function is used when the program receives only one argument
 * that includes several numbers (e.g., "3 2 1 4"). It splits the string
 * into individual numbers, validates them, and fills stack A.
 *
 * @param a Pointer to the stack to be filled.
 * @param arg The input string to be split and parsed.
 * @return 1 on success, 0 on failure (invalid input, duplicates, etc.).
 */
static int	handle_single_arg(t_stack **a, char *arg)
{
	char	**split_args;
	int		result;

	split_args = ft_split(arg, ' ');
	result = parse_args(a, split_args);
	free_split(split_args);
	return (result);
}

/**
 * @brief Initializes stack A with integers from command line arguments.
 *
 * Supports both:
 * - a single quoted string with space-separated numbers:
 * "./push_swap \"3 2 1\""
 * - multiple separate arguments: "./push_swap 3 2 1"
 *
 * @param a Pointer to the stack to fill.
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return 1 if parsing was successful, 0 if input was invalid.
 */
static int	init_stack(t_stack **a, int argc, char **argv)
{
	if (argc == 2)
	{
		if (!handle_single_arg(a, argv[1]))
			return (0);
	}
	else if (argc > 2)
	{
		if (!parse_args(a, argv + 1))
			return (0);
	}
	return (1);
}

/**
 * @brief Main function of the push_swap program.
 *
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return 0 on program exit.
 */
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!init_stack(&a, argc, argv))
		exit_error(a);
	assign_indexes(a);
	sort_stack(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
