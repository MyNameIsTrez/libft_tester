/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_step_range_iterator.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/26 12:39:51 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 13:11:17 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_iterator_positive_step_range_1)
{
	t_iterator	it;

	it = ft_get_step_range_iterator(5, 10, 2);
	massert(it.current, (intptr_t)5);
	massert(it.next, (intptr_t)5);
	massert(it.stop, (intptr_t)10);
	massert(it.step, (intptr_t)2);

	int expected_current = 5;
	while (ft_iterate(&it) != FINISHED)
	{
		massert(it.current, (intptr_t)expected_current);
		massert(it.next, (intptr_t)expected_current + 2);
		massert(it.stop, (intptr_t)10);
		massert(it.step, (intptr_t)2);
		expected_current += 2;
	}

	massert(it.current, (intptr_t)9);
	massert(it.next, (intptr_t)11);
	massert(it.stop, (intptr_t)10);
	massert(it.step, (intptr_t)2);

	ft_iterate(&it);
	massert(it.current, (intptr_t)9);
	massert(it.next, (intptr_t)11);
	massert(it.stop, (intptr_t)10);
	massert(it.step, (intptr_t)2);
}

Test(ft_iterator_positive_step_range_2)
{
	t_iterator	it;

	it = ft_get_step_range_iterator(5, 9, 2);
	massert(it.current, (intptr_t)5);
	massert(it.next, (intptr_t)5);
	massert(it.stop, (intptr_t)9);
	massert(it.step, (intptr_t)2);

	int expected_current = 5;
	while (ft_iterate(&it) != FINISHED)
	{
		massert(it.current, (intptr_t)expected_current);
		massert(it.next, (intptr_t)expected_current + 2);
		massert(it.stop, (intptr_t)9);
		massert(it.step, (intptr_t)2);
		expected_current += 2;
	}

	massert(it.current, (intptr_t)7);
	massert(it.next, (intptr_t)9);
	massert(it.stop, (intptr_t)9);
	massert(it.step, (intptr_t)2);

	ft_iterate(&it);
	massert(it.current, (intptr_t)7);
	massert(it.next, (intptr_t)9);
	massert(it.stop, (intptr_t)9);
	massert(it.step, (intptr_t)2);
}

Test(ft_iterator_negative_step_range_1)
{
	t_iterator	it;

	it = ft_get_step_range_iterator(5, -3, -2);
	massert(it.current, (intptr_t)5);
	massert(it.next, (intptr_t)5);
	massert(it.stop, (intptr_t)-3);
	massert(it.step, (intptr_t)-2);

	int expected_current = 5;
	while (ft_iterate(&it) != FINISHED)
	{
		massert(it.current, (intptr_t)expected_current);
		massert(it.next, (intptr_t)expected_current + -2);
		massert(it.stop, (intptr_t)-3);
		massert(it.step, (intptr_t)-2);
		expected_current += -2;
	}

	massert(it.current, (intptr_t)-1);
	massert(it.next, (intptr_t)-3);
	massert(it.stop, (intptr_t)-3);
	massert(it.step, (intptr_t)-2);

	ft_iterate(&it);
	massert(it.current, (intptr_t)-1);
	massert(it.next, (intptr_t)-3);
	massert(it.stop, (intptr_t)-3);
	massert(it.step, (intptr_t)-2);
}

Test(ft_iterator_negative_step_range_2)
{
	t_iterator	it;

	it = ft_get_step_range_iterator(5, -2, -2);
	massert(it.current, (intptr_t)5);
	massert(it.next, (intptr_t)5);
	massert(it.stop, (intptr_t)-2);
	massert(it.step, (intptr_t)-2);

	int expected_current = 5;
	while (ft_iterate(&it) != FINISHED)
	{
		massert(it.current, (intptr_t)expected_current);
		massert(it.next, (intptr_t)expected_current + -2);
		massert(it.stop, (intptr_t)-2);
		massert(it.step, (intptr_t)-2);
		expected_current += -2;
	}

	massert(it.current, (intptr_t)-1);
	massert(it.next, (intptr_t)-3);
	massert(it.stop, (intptr_t)-2);
	massert(it.step, (intptr_t)-2);

	ft_iterate(&it);
	massert(it.current, (intptr_t)-1);
	massert(it.next, (intptr_t)-3);
	massert(it.stop, (intptr_t)-2);
	massert(it.step, (intptr_t)-2);
}

////////////////////////////////////////////////////////////////////////////////
