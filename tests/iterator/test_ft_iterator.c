/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_iterator.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/26 12:39:51 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/28 14:38:34 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_iterator_range_start_0_1)
{
	t_iterator	it;

	it = ft_get_range_start_0_iterator(1);
	massert(it.current, (intptr_t)0);
	massert(it.next, (intptr_t)0);
	massert(it.stop, (intptr_t)1);
	massert(it.step, (intptr_t)1);

	massert(ft_iterate(&it), (t_iterator_status)LOOPED);
	massert(it.current, (intptr_t)0);
	massert(it.next, (intptr_t)1);
	massert(it.stop, (intptr_t)1);
	massert(it.step, (intptr_t)1);

	massert(ft_iterate(&it), (t_iterator_status)FINISHED);
	massert(it.current, (intptr_t)0);
	massert(it.next, (intptr_t)1);
	massert(it.stop, (intptr_t)1);
	massert(it.step, (intptr_t)1);
}

Test(ft_iterator_range_start_0_2)
{
	t_iterator	it;

	it = ft_get_range_start_0_iterator(3);
	massert(it.current, (intptr_t)0);
	massert(it.next, (intptr_t)0);
	massert(it.stop, (intptr_t)3);
	massert(it.step, (intptr_t)1);

	int expected_current = 0;
	while (ft_iterate(&it) != FINISHED)
	{
		massert(it.current, (intptr_t)expected_current);
		massert(it.next, (intptr_t)expected_current + 1);
		massert(it.stop, (intptr_t)3);
		massert(it.step, (intptr_t)1);
		expected_current += 1;
	}

	massert(it.current, (intptr_t)2);
	massert(it.next, (intptr_t)3);
	massert(it.stop, (intptr_t)3);
	massert(it.step, (intptr_t)1);

	ft_iterate(&it);
	massert(it.current, (intptr_t)2);
	massert(it.next, (intptr_t)3);
	massert(it.stop, (intptr_t)3);
	massert(it.step, (intptr_t)1);
}

Test(ft_iterator_range)
{
	t_iterator	it;

	it = ft_get_range_iterator(5, 10);
	massert(it.current, (intptr_t)5);
	massert(it.next, (intptr_t)5);
	massert(it.stop, (intptr_t)10);
	massert(it.step, (intptr_t)1);

	int expected_current = 5;
	while (ft_iterate(&it) != FINISHED)
	{
		massert(it.current, (intptr_t)expected_current);
		massert(it.next, (intptr_t)expected_current + 1);
		massert(it.stop, (intptr_t)10);
		massert(it.step, (intptr_t)1);
		expected_current += 1;
	}

	massert(it.current, (intptr_t)9);
	massert(it.next, (intptr_t)10);
	massert(it.stop, (intptr_t)10);
	massert(it.step, (intptr_t)1);

	ft_iterate(&it);
	massert(it.current, (intptr_t)9);
	massert(it.next, (intptr_t)10);
	massert(it.stop, (intptr_t)10);
	massert(it.step, (intptr_t)1);
}

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

Test(ft_array_iterator)
{
	size_t		count;
	size_t		size;
	int			*ints;
	t_iterator	it;

	count = 2;
	size = sizeof(*ints);

	m_safe_assert(void *, ints = ft_malloc(count, size), ints, NULL, false);

	it = ft_get_array_iterator(ints, count, size);
	massert(it.current, (intptr_t)ints);
	massert(it.next, (intptr_t)ints);
	massert(it.stop, (intptr_t)(((uintptr_t)ints) + count * size));
	massert(it.step, (intptr_t)size);

	massert(ft_iterate(&it), (t_iterator_status)LOOPED);
	massert(it.current, (intptr_t)ints);
	massert(it.next, (intptr_t)(((uintptr_t)ints) + 1 * size));
	massert(it.stop, (intptr_t)(((uintptr_t)ints) + count * size));
	massert(it.step, (intptr_t)size);

	massert(ft_iterate(&it), (t_iterator_status)LOOPED);
	massert(it.current, (intptr_t)(((uintptr_t)ints) + 1 * size));
	massert(it.next, (intptr_t)(((uintptr_t)ints) + 2 * size));
	massert(it.stop, (intptr_t)(((uintptr_t)ints) + count * size));
	massert(it.step, (intptr_t)size);

	massert(ft_iterate(&it), (t_iterator_status)FINISHED);
	massert(it.current, (intptr_t)(((uintptr_t)ints) + 1 * size));
	massert(it.next, (intptr_t)(((uintptr_t)ints) + 2 * size));
	massert(it.stop, (intptr_t)(((uintptr_t)ints) + count * size));
	massert(it.step, (intptr_t)size);
}

////////////////////////////////////////////////////////////////////////////////

Test(ft_count_iterator)
{
	t_iterator	it;

	it = ft_get_count_iterator(3);
	massert(it.current, (intptr_t)0);
	massert(it.next, (intptr_t)0);
	massert(it.stop, (intptr_t)3);
	massert(it.step, (intptr_t)1);

	int expected_current = 0;
	while (ft_iterate(&it) != FINISHED)
	{
		massert(it.current, (intptr_t)expected_current);
		massert(it.next, (intptr_t)expected_current + 1);
		massert(it.stop, (intptr_t)3);
		massert(it.step, (intptr_t)1);
		expected_current += 1;
	}

	massert(it.current, (intptr_t)2);
	massert(it.next, (intptr_t)3);
	massert(it.stop, (intptr_t)3);
	massert(it.step, (intptr_t)1);

	ft_iterate(&it);
	massert(it.current, (intptr_t)2);
	massert(it.next, (intptr_t)3);
	massert(it.stop, (intptr_t)3);
	massert(it.step, (intptr_t)1);
}

////////////////////////////////////////////////////////////////////////////////
