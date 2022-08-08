/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_range_iterator.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 13:10:41 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 12:54:28 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

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

	massert(it.current, (intptr_t)5);
	massert(it.next, (intptr_t)10);
	massert(it.stop, (intptr_t)10);
	massert(it.step, (intptr_t)1);

	ft_iterate(&it);
	massert(it.current, (intptr_t)5);
	massert(it.next, (intptr_t)10);
	massert(it.stop, (intptr_t)10);
	massert(it.step, (intptr_t)1);
}

////////////////////////////////////////////////////////////////////////////////
