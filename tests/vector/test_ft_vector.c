/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_vector.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/19 16:27:25 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/20 16:35:20 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_vector)
{
	{
		int	*ints;
		int	v;

		m_safe_assert(void *, ints = vector_new(sizeof(int)), ints, NULL, true);

		m_safe_assert(int, (int)vector_reserve(&ints, 1), OK, ERROR, false);

		v = 1;
		m_safe_assert(int, (int)vector_push(&ints, &v), OK, ERROR, false);
		v = 2;
		m_safe_assert(int, (int)vector_push(&ints, &v), OK, ERROR, false);
		v = 3;
		m_safe_assert(int, (int)vector_push(&ints, &v), OK, ERROR, false);

		if (NOT was_malloc_unstable)
		{
			massert(ints[0], 1);
			massert(ints[1], 2);
			massert(ints[2], 3);
		}
		vector_free(ints);
	}
	{
		int	*ints;
		int	v;

		m_safe_assert(void *, ints = vector_new_reserved(sizeof(int), 1), ints, NULL, true);

		v = 1;
		m_safe_assert(int, (int)vector_push(&ints, &v), OK, ERROR, false);
		v = 2;
		m_safe_assert(int, (int)vector_push(&ints, &v), OK, ERROR, false);
		v = 3;
		m_safe_assert(int, (int)vector_push(&ints, &v), OK, ERROR, false);

		if (NOT was_malloc_unstable)
		{
			massert(ints[0], 1);
			massert(ints[1], 2);
			massert(ints[2], 3);
		}
		vector_free(ints);
	}
	{
		int	**ints_2d;
		int	*row_0;
		int	*row_1;
		int	v;

		m_safe_assert(void *, ints_2d = vector_new(sizeof(int *)), ints_2d, NULL, true);


		m_safe_assert(void *, row_0 = vector_new(sizeof(int)), row_0, NULL, false);
		m_safe_assert(int, (int)vector_push(&ints_2d, &row_0), OK, ERROR, false);
		v = 1;

		// WARNING:
		// "vector_push(&row_0, &v);" doesn't work since whenever row_0
		// is realloced, ints_2d wouldn't be aware row_0 its address moved

		m_safe_assert(int, (int)vector_push(&ints_2d[0], &v), OK, ERROR, false);
		v = 2;
		m_safe_assert(int, (int)vector_push(&ints_2d[0], &v), OK, ERROR, false);
		v = 3;
		m_safe_assert(int, (int)vector_push(&ints_2d[0], &v), OK, ERROR, false);

		if (NOT was_malloc_unstable)
		{
			massert(ints_2d[0][0], 1);
			massert(ints_2d[0][1], 2);
			massert(ints_2d[0][2], 3);
		}


		m_safe_assert(void *, row_1 = vector_new(sizeof(int)), row_1, NULL, false);
		v = 4;
		m_safe_assert(int, (int)vector_push(&row_1, &v), OK, ERROR, false);
		v = 5;
		m_safe_assert(int, (int)vector_push(&row_1, &v), OK, ERROR, false);
		v = 6;
		m_safe_assert(int, (int)vector_push(&row_1, &v), OK, ERROR, false);
		m_safe_assert(int, (int)vector_push(&ints_2d, &row_1), OK, ERROR, false);

		if (NOT was_malloc_unstable)
		{
			massert(ints_2d[1][0], 4);
			massert(ints_2d[1][1], 5);
			massert(ints_2d[1][2], 6);
		}


		m_safe_assert(int, (int)vector_push_new_vector(&ints_2d, sizeof(int)), OK, ERROR, false);
		v = 7;
		m_safe_assert(int, (int)vector_push(&ints_2d[2], &v), OK, ERROR, false);
		v = 8;
		m_safe_assert(int, (int)vector_push(&ints_2d[2], &v), OK, ERROR, false);
		v = 9;
		m_safe_assert(int, (int)vector_push(&ints_2d[2], &v), OK, ERROR, false);

		if (NOT was_malloc_unstable)
		{
			massert(ints_2d[2][0], 7);
			massert(ints_2d[2][1], 8);
			massert(ints_2d[2][2], 9);
		}
	}
	vector_clean_up();
}

////////////////////////////////////////////////////////////////////////////////
