/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strdup.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 17:10:01 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/22 12:12:20 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_strdup)
{
	char	*a = "hello";
	m_safe_string_assert_free(ft_strdup(a, "test ft_strdup 1"), a, true);
	char	*dup = ft_strdup(a, "test ft_strdup 2");
	massert((bool)(dup == a), false);
}
