/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_deque_front.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/19 16:27:25 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/10 12:54:29 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_deque_front)
{
	t_deque	*ints;
	int	v;

	m_safe_assert(void *, ints = ft_deque_new_reserved(sizeof(int), 2), ints, NULL, false);

	if (!was_malloc_unstable)
	{
		v = 1;
		m_safe_assert(t_status, ft_deque_push_front(ints, &v), OK, ERROR, false);
	}
	if (!was_malloc_unstable)
	{
		v = 2;
		m_safe_assert(t_status, ft_deque_push_front(ints, &v), OK, ERROR, false);
	}

	if (!was_malloc_unstable)
	{
		massert(*(int *)ft_deque_front(ints), 2);
		ft_deque_pop_front(ints);
		massert(ft_deque_size(ints), (size_t)1);

		massert(*(int *)ft_deque_front(ints), 1);
		ft_deque_pop_front(ints);
		massert(ft_deque_size(ints), (size_t)0);
	}
}

////////////////////////////////////////////////////////////////////////////////
