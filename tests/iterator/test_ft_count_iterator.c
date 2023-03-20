/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_count_iterator.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 13:08:11 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 12:54:49 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_iterator_range_start_0_1)
{
	t_iterator	it;

	it = ft_get_count_iterator(1);
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

	massert(it.current, (intptr_t)0);
	massert(it.next, (intptr_t)3);
	massert(it.stop, (intptr_t)3);
	massert(it.step, (intptr_t)1);

	ft_iterate(&it);
	massert(it.current, (intptr_t)0);
	massert(it.next, (intptr_t)3);
	massert(it.stop, (intptr_t)3);
	massert(it.step, (intptr_t)1);
}
