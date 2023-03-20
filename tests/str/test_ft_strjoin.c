/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strjoin.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 17:11:34 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/21 10:57:41 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_strjoin)
{
	m_safe_string_assert_free(ft_strjoin("lorem ipsum", "dolor sit amet", "test ft_strjoin"), "lorem ipsumdolor sit amet", true);
}

Test(ft_strjoin_null)
{
	m_safe_string_assert_free(ft_strjoin("foo", NULL, "test ft_strjoin_null 1"), "foo", true);
	m_safe_string_assert_free(ft_strjoin(NULL, "bar", "test ft_strjoin_null 2"), "bar", true);
}

Test(ft_strjoin_partial)
{
	char	*str = ft_stralloc(3, "test ft_strjoin_partial 1");
	if (str != NULL)
	{
		str[0] = 'a';
		str[1] = 'b';
		str[2] = 'c';

		m_safe_string_assert_free(ft_strjoin("foo", str + 1, "test ft_strjoin_partial 2"), "foobc", true);
	}
}
