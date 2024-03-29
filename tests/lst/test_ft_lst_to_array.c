/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_lst_to_array.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/21 12:10:59 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/22 12:00:29 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_lst_to_array)
{
	{
		t_list	*lst = NULL;

		void	**array = ft_lst_to_array(lst, "test ft_lst_to_array");
		m_safe_assert(void *, array, array, NULL, true);

		ft_lstclear(&lst, NULL);
	}
}

Test(ft_lst_to_array2)
{
	{
		t_list	*lst = NULL;
		void **array = NULL;

		ft_lst_new_front(&lst, "foo", "test ft_lst_to_array2 1");
		if (!was_malloc_unstable)
		{
			ft_lst_new_front(&lst, "bar", "test ft_lst_to_array2 2");
		}
		if (!was_malloc_unstable)
		{
			ft_lst_new_front(&lst, "baz", "test ft_lst_to_array2 3");
		}
		if (!was_malloc_unstable)
		{
			ft_lst_new_front(&lst, "beep", "test ft_lst_to_array2 4");
		}
		if (!was_malloc_unstable)
		{
			ft_lst_new_front(&lst, "boop", "test ft_lst_to_array2 5");
		}
		if (!was_malloc_unstable)
		{
			array = ft_lst_to_array(lst, "test ft_lst_to_array2 6");
			m_safe_assert(void *, array, array, NULL, false);
		}

		if (array != NULL && !was_malloc_unstable)
		{
			m_safe_string_assert(array[0], "boop", true);
			m_safe_string_assert(array[1], "beep", true);
			m_safe_string_assert(array[2], "baz", true);
			m_safe_string_assert(array[3], "bar", true);
			m_safe_string_assert(array[4], "foo", true);
		}

		ft_lstclear(&lst, NULL);
	}
}
