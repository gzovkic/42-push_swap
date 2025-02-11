/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:24:44 by gzovkic           #+#    #+#             */
/*   Updated: 2025/02/11 17:27:12 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_doubles(t_stacks *stacks)
{
	int count;
	int count2;

	count = 0;
	while(count < stacks->size_a)
	{
		count2 = count + 1;
		while(count2 < stacks->size_a)
		{
			if(stacks->stack_a[count] == stacks->stack_a[count2])
				printf_and_exit("Duplicate number");
			count2++;
		}
		count++;
	}
}

void	sort_stack_a(char *arg_str, t_stacks *stacks)
{
	char	**stack_a_split;
	int stack_a_lenght;

	check_argument(arg_str);
	stack_a_split = create_stack_a_split(arg_str);
	stacks->stack_a = create_stack_a_int(stack_a_split);
	stacks->size_a = ft_strlen_index(stack_a_split);
	check_doubles(stacks);
	stacks->index_stack = create_stack_a_int(stack_a_split);
	stacks->stack_a = create_stack_a_int(stack_a_split);
	stacks->stack_b = ft_calloc(stacks->size_a, sizeof(int));
	if (!stacks->stack_b)
		printf_and_exit("Memory allocation failed for stack_b");
	stacks->size_b = 0;
	free_split(stack_a_split);
	stack_a_lenght = ft_strlen_index(stack_a_split);
	stacks->index_stack = bubble_sort_stack(stacks->index_stack, stack_a_lenght);
}

void search_index(t_stacks *stacks)
{
	int count_a;
	int count_i;

	count_a = 0;
	while (count_a <= stacks->size_a)
	{
		count_i = 0;
		while (count_i <= stacks->size_a)
		{
			if (stacks->stack_a[count_a] == stacks->index_stack[count_i])
			{
				stacks->stack_a[count_a] = count_i;
				break;
			}
			count_i++;
		}
		count_a++;
	}
	count_a = 0;
	while (count_a <= stacks->size_i)
	{
		stacks->index_stack[count_a] = count_a;
		count_a++;
	}
}

int	ft_sqrt(int nb)
{
	int	sqr_root;

	if (nb < 0)
		return (0);
	sqr_root = 0;
	while (sqr_root * sqr_root <= nb)
	{
		if (sqr_root * sqr_root <= nb && (sqr_root + 1) * (sqr_root + 1) >= nb)
			return (sqr_root);
		sqr_root++;
	}
	return (0);
}

void b_pre_sort(t_stacks *stacks)
{
	int count;
	int range;
	printf("size stack a : %d\n", stacks->size_a);
	count = 0;
	range = ft_sqrt(stacks->size_a) * 1.6;
	while(stacks->size_a > 0)
	{
		if(stacks->stack_a[0] <= count)
		{
			pb(stacks);
			rb(stacks);
			count++;
		}
		else if(stacks->stack_a[0] < count + range)
		{
			pb(stacks);
			count++;
		}
		else
			ra(stacks);
	}
}

int get_moves(t_stacks *stacks, int index)
{
	int moves_up;
	int size_b;

	moves_up = 0;
	size_b = stacks->size_b;
	while (moves_up < size_b)
	{
		if (stacks->stack_b[moves_up] == index)
			break;
		moves_up++;
	}
	return (moves_up);
}

void switch_index(t_stacks *stacks)
{
	int count;

	count = 0;
	while (count < stacks->size_i)
	{
		stacks->index_stack[count] = stacks->index_stack[count + 1];
		count++;
	}
	stacks->size_i -= 2;
}

void return_num(t_stacks *stacks)
{
	int current_index;
	int moves;
	int size_b;

	size_b = stacks->size_b;
	current_index = size_b - 1;
	while (size_b > 0)
	{
		moves = get_moves(stacks, current_index);
		if (moves > size_b / 2)
		{
			moves = size_b - moves;
			while (moves--)
				rrb(stacks);
		}
		else
		{
			while (moves--)
				rb(stacks);
		}
		pa(stacks);
		switch_index(stacks);
		size_b--;
	}
}


// void	sort_two(t_stacks *stacks)
// {
// 	if (stacks->stack_a[0] > stacks->stack_a[1])
// 		sa(stacks);
// 	// free_all(stacks);
// 	exit(EXIT_SUCCESS);
// }

// void	sort_three(t_stacks *stacks)
// {
// 	if (stacks->stack_a[0] > stacks->stack_a[1] && stacks->stack_a[1] < stacks->stack_a[2] && stacks->stack_a[2] > stacks->stack_a[0])
// 		sa(stacks);
// 	if (stacks->stack_a[0] > stacks->stack_a[1] && stacks->stack_a[1] > stacks->stack_a[2] && stacks->stack_a[2] < stacks->stack_a[0])
// 	{
// 		sa(stacks);
// 		rra(stacks);
// 	}
// 	if (stacks->stack_a[0] > stacks->stack_a[1] && stacks->stack_a[1] < stacks->stack_a[2] && stacks->stack_a[2] < stacks->stack_a[0])
// 		ra(stacks);
// 	if (stacks->stack_a[0] < stacks->stack_a[1] && stacks->stack_a[1] > stacks->stack_a[2] && stacks->stack_a[2] > stacks->stack_a[0])
// 	{
// 		sa(stacks);
// 		ra(stacks);
// 	}
// 	if (stacks->stack_a[0] < stacks->stack_a[1] && stacks->stack_a[1] > stacks->stack_a[2] && stacks->stack_a[2] < stacks->stack_a[0])
// 		rra(stacks);
// }

// void	sort_four(t_stacks *stacks)
// {
// 	int	i;

// 	i = 0;
// 	while (i < stacks->size_a - 3)
// 	{
// 		if (stacks->stack_a[0] == stacks->index_stack[0])
// 		{
// 			pb(stacks);
// 			i++;
// 		}
// 		else
// 			ra(stacks);
// 	}
// 	sort_three(stacks);
// 	pa(stacks);
// }

// void	sort_five(t_stacks *stacks)
// {
// 	int	i;

// 	i = 0;
// 	while (i <= stacks->size_a - 3)
// 	{
// 		if (stacks->stack_a[0] == stacks->index_stack[0] || stacks->stack_a[0] == stacks->index_stack[1])
// 		{
// 			pb(stacks);
// 			i++;
// 		}
// 		else
// 			ra(stacks);
// 	}
// 	sort_three(stacks);
// 	if (stacks->stack_b[0] < stacks->stack_b[1])
// 		sb(stacks);
// 	pa(stacks);
// 	pa(stacks);
// }
void k_sort(t_stacks *stacks)
{
	// if (stacks->size_a == 2)
	// 	sort_two(stacks);
	// // if (is_sorted(stacks->stack_a, stacks->index_stack))
	// // 	free_all(stacks);
	// if (stacks->size_a == 3)
	// 	sort_three(stacks);
	// else if (stacks->size_a == 4)
	// 	sort_four(stacks);
	// // else if (stacks->size_a == 5)
	// // 	sort_five(stacks);
	// else
	// {
		search_index(stacks);
		b_pre_sort(stacks);
		return_num(stacks);
	// }
}

int	main(int argc, char *argv[])
{
	char *arg_str;
	t_stacks stacks;
	
	stacks.size_b = 0;

	if (argc == 2)
	{
		sort_stack_a(argv[1], &stacks);
		k_sort(&stacks);
	}
	else if(argc > 2)
	{
		arg_str = create_argument_str(argv);
		sort_stack_a(arg_str, &stacks);
		k_sort(&stacks);
	}
	else
		printf_and_exit("Wrong amount of arguments");

	return (0);
}

