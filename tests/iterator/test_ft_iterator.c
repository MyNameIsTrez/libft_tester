/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_iterator.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/26 12:39:51 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/26 14:51:14 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_iterator_range_start_0)
{
	t_iterator	it;

	it = ft_get_range_start_0_iterator(10);
	massert((intptr_t)it.current, (intptr_t)0);
	massert((intptr_t)it.stop, (intptr_t)10);
	massert(it.step, 1);

	int expected_current = 0;
	while (ft_iterate(&it) != FINISHED)
	{
		expected_current++;
		massert((intptr_t)it.current, (intptr_t)expected_current);
		massert((intptr_t)it.stop, (intptr_t)10);
		massert(it.step, 1);
	}

	massert((intptr_t)it.current, (intptr_t)9);
	massert((intptr_t)it.stop, (intptr_t)10);
	massert(it.step, 1);

	ft_iterate(&it);
	massert((intptr_t)it.current, (intptr_t)9);
	massert((intptr_t)it.stop, (intptr_t)10);
	massert(it.step, 1);
}

Test(ft_iterator_range)
{
	t_iterator	it;

	it = ft_get_range_iterator(5, 10);
	massert((intptr_t)it.current, (intptr_t)5);
	massert((intptr_t)it.stop, (intptr_t)10);
	massert(it.step, 1);

	int expected_current = 5;
	while (ft_iterate(&it) != FINISHED)
	{
		expected_current++;
		massert((intptr_t)it.current, (intptr_t)expected_current);
		massert((intptr_t)it.stop, (intptr_t)10);
		massert(it.step, 1);
	}

	massert((intptr_t)it.current, (intptr_t)9);
	massert((intptr_t)it.stop, (intptr_t)10);
	massert(it.step, 1);

	ft_iterate(&it);
	massert((intptr_t)it.current, (intptr_t)9);
	massert((intptr_t)it.stop, (intptr_t)10);
	massert(it.step, 1);
}

Test(ft_iterator_positive_step_range_1)
{
	t_iterator	it;

	it = ft_get_step_range_iterator(5, 10, 2);
	massert((intptr_t)it.current, (intptr_t)5);
	massert((intptr_t)it.stop, (intptr_t)10);
	massert(it.step, 2);

	int expected_current = 5;
	while (ft_iterate(&it) != FINISHED)
	{
		expected_current += 2;
		massert((intptr_t)it.current, (intptr_t)expected_current);
		massert((intptr_t)it.stop, (intptr_t)10);
		massert(it.step, 2);
	}

	massert((intptr_t)it.current, (intptr_t)9);
	massert((intptr_t)it.stop, (intptr_t)10);
	massert(it.step, 2);

	ft_iterate(&it);
	massert((intptr_t)it.current, (intptr_t)9);
	massert((intptr_t)it.stop, (intptr_t)10);
	massert(it.step, 2);
}

Test(ft_iterator_positive_step_range_2)
{
	t_iterator	it;

	it = ft_get_step_range_iterator(5, 9, 2);
	massert((intptr_t)it.current, (intptr_t)5);
	massert((intptr_t)it.stop, (intptr_t)9);
	massert(it.step, 2);

	int expected_current = 5;
	while (ft_iterate(&it) != FINISHED)
	{
		expected_current += 2;
		massert((intptr_t)it.current, (intptr_t)expected_current);
		massert((intptr_t)it.stop, (intptr_t)9);
		massert(it.step, 2);
	}

	massert((intptr_t)it.current, (intptr_t)7);
	massert((intptr_t)it.stop, (intptr_t)9);
	massert(it.step, 2);

	ft_iterate(&it);
	massert((intptr_t)it.current, (intptr_t)7);
	massert((intptr_t)it.stop, (intptr_t)9);
	massert(it.step, 2);
}

Test(ft_iterator_negative_step_range_1)
{
	t_iterator	it;

	it = ft_get_step_range_iterator(5, -3, -2);
	massert((intptr_t)it.current, (intptr_t)5);
	massert((intptr_t)it.stop, (intptr_t)-3);
	massert(it.step, -2);

	int expected_current = 5;
	while (ft_iterate(&it) != FINISHED)
	{
		expected_current += -2;
		massert((intptr_t)it.current, (intptr_t)expected_current);
		massert((intptr_t)it.stop, (intptr_t)-3);
		massert(it.step, -2);
	}

	massert((intptr_t)it.current, (intptr_t)-1);
	massert((intptr_t)it.stop, (intptr_t)-3);
	massert(it.step, -2);

	ft_iterate(&it);
	massert((intptr_t)it.current, (intptr_t)-1);
	massert((intptr_t)it.stop, (intptr_t)-3);
	massert(it.step, -2);
}

Test(ft_iterator_negative_step_range_2)
{
	t_iterator	it;

	it = ft_get_step_range_iterator(5, -2, -2);
	massert((intptr_t)it.current, (intptr_t)5);
	massert((intptr_t)it.stop, (intptr_t)-2);
	massert(it.step, -2);

	int expected_current = 5;
	while (ft_iterate(&it) != FINISHED)
	{
		expected_current += -2;
		massert((intptr_t)it.current, (intptr_t)expected_current);
		massert((intptr_t)it.stop, (intptr_t)-2);
		massert(it.step, -2);
	}

	massert((intptr_t)it.current, (intptr_t)-1);
	massert((intptr_t)it.stop, (intptr_t)-2);
	massert(it.step, -2);

	ft_iterate(&it);
	massert((intptr_t)it.current, (intptr_t)-1);
	massert((intptr_t)it.stop, (intptr_t)-2);
	massert(it.step, -2);
}

////////////////////////////////////////////////////////////////////////////////
