/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_vector_from_deque.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 20:24:37 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 17:07:41 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"
#include "src/deque/back/ft_deque_back.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_vector_from_deque)
{
	t_deque	*deque;
	int		v;

	m_safe_assert(void *, deque = ft_deque_new_reserved(sizeof(int), 3), deque, NULL, false);

	if (!was_malloc_unstable)
	{
		v = 1;
		m_safe_assert(t_status, ft_deque_push_back(deque, &v), OK, ERROR, false);
	}
	if (!was_malloc_unstable)
	{
		v = 2;
		m_safe_assert(t_status, ft_deque_push_back(deque, &v), OK, ERROR, false);
	}
	if (!was_malloc_unstable)
	{
		v = 3;
		m_safe_assert(t_status, ft_deque_push_back(deque, &v), OK, ERROR, false);
	}

	int	*vector;

	if (!was_malloc_unstable)
	{
		m_safe_assert(void *, vector = ft_vector_from_deque(deque), vector, NULL, false);
	}

	if (!was_malloc_unstable)
	{
		massert(vector[0], 1);
		massert(vector[1], 2);
		massert(vector[2], 3);
	}
}

////////////////////////////////////////////////////////////////////////////////
