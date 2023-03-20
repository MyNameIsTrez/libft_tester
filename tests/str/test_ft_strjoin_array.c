/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strjoin_array.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 17:11:34 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/21 10:57:41 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_strjoin_array)
{
	m_safe_string_assert_free(ft_strjoin_array((char *[]){NULL}, "test ft_strjoin_array 1"), NULL, true);
	m_safe_string_assert_free(ft_strjoin_array((char *[]){"a", NULL}, "test ft_strjoin_array 2"), "a", true);
	m_safe_string_assert_free(ft_strjoin_array((char *[]){"a", "b", NULL}, "test ft_strjoin_array 3"), "ab", true);
}
