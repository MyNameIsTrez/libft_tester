/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_rejoin_split.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 12:45:44 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/21 11:32:55 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_rejoin_split)
{
	{
		char	*str = "AB1ABAB2AB3";
		char	*sep = "AB";

		char	**split;
		m_safe_assert(void *, split = ft_split_str(str, sep), split, NULL, true);
		if (split != NULL)
		{
			m_safe_string_assert_free(ft_rejoin_split(split, "C"), "C1CC2C3", true);
			ft_free_split(&split);
		}
	}

	{
		char	*str = "AB1ABAB2AB3AB";
		char	*sep = "AB";

		char	**split;
		m_safe_assert(void *, split = ft_split_str(str, sep), split, NULL, true);
		if (split != NULL)
		{
			m_safe_string_assert_free(ft_rejoin_split(split, "C"), "C1CC2C3C", true);
			ft_free_split(&split);
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
