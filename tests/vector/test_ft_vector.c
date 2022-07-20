/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_vector.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/19 16:27:25 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/20 12:42:57 by sbos          ########   odam.nl         */
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

		ints = vector_new(sizeof(int));

		vector_reserve(&ints, 1);

		v = 1;
		vector_push(&ints, &v);
		v = 2;
		vector_push(&ints, &v);
		v = 3;
		vector_push(&ints, &v);

		massert(ints[0], 1);
		massert(ints[1], 2);
		massert(ints[2], 3);

		vector_free(ints);
	}
	{
		int	*ints;
		int	v;

		ints = vector_new_reserved(sizeof(int), 1);

		v = 1;
		vector_push(&ints, &v);
		v = 2;
		vector_push(&ints, &v);
		v = 3;
		vector_push(&ints, &v);

		massert(ints[0], 1);
		massert(ints[1], 2);
		massert(ints[2], 3);

		vector_free(ints);
	}
	vector_clean_up();
}

////////////////////////////////////////////////////////////////////////////////
