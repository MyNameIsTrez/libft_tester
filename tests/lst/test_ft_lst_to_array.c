/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_lst_to_array.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/21 12:10:59 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/21 12:44:41 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_lst_to_array)
{
	{
		t_list	*lst = NULL;

		void	**array = ft_lst_to_array(lst);
		m_safe_assert(void *, array, array, NULL, true);

		ft_lstclear(&lst, NULL);
		free(array);
	}

	{
		t_list	*lst = NULL;

		ft_lst_new_front(&lst, "foo");
		m_safe_assert(void *, lst, lst, NULL, true);

		ft_lst_new_front(&lst, "bar");
		m_safe_assert(void *, lst, lst, NULL, true);

		void	**array = ft_lst_to_array(lst);
		m_safe_assert(void *, array, array, NULL, true);

		if (array != NULL)
		{
			m_safe_string_assert(array[0], "bar", true);
			m_safe_string_assert(array[1], "foo", true);
		}

		ft_lstclear(&lst, NULL);
		free(array);
	}
}

////////////////////////////////////////////////////////////////////////////////
