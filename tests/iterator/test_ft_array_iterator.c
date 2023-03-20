/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_array_iterator.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 13:07:41 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/08 12:55:15 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_array_iterator)
{
	size_t		count;
	size_t		size;
	int			*ints;
	t_iterator	it;

	count = 2;
	size = sizeof(*ints);

	m_safe_assert(void *, ints = ft_malloc(count, size, "test ft_array_iterator"), ints, NULL, false);

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
	massert(it.current, (intptr_t)ints);
	massert(it.next, (intptr_t)(((uintptr_t)ints) + 2 * size));
	massert(it.stop, (intptr_t)(((uintptr_t)ints) + count * size));
	massert(it.step, (intptr_t)size);
}
