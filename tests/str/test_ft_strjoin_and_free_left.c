/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strjoin_and_free_left.c                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 17:11:34 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/21 10:57:41 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_strjoin_and_free_left)
{
	char	*left = ft_strdup("lorem ipsum", "test ft_strjoin_and_free_left 1");
	if (left != NULL)
	{
		m_safe_string_assert_free(ft_strjoin_and_free_left(left, "dolor sit amet", "test ft_strjoin_and_free_left 2"), "lorem ipsumdolor sit amet", true);
	}
}

Test(ft_strjoin_and_free_left_null)
{
	char	*left = ft_strdup("lorem ipsum", "test ft_strjoin_and_free_left_null 1");
	if (left != NULL)
	{
		m_safe_string_assert_free(ft_strjoin_and_free_left(left, NULL, "test ft_strjoin_and_free_left_null 2"), "lorem ipsum", true);
		m_safe_string_assert_free(ft_strjoin_and_free_left(NULL, "bar", "test ft_strjoin_and_free_left_null 3"), "bar", true);
	}
}
