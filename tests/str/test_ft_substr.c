/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_substr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 17:44:28 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/21 11:04:08 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_substr)
{
	m_safe_string_assert_free(ft_substr("lorem ipsum dolor sit amet", 400, 20, "test ft_substr 1"), "", true);
	m_safe_string_assert_free(ft_substr("lorem ipsum dolor sit amet", 5, 0, "test ft_substr 2"), "", true);
	m_safe_string_assert_free(ft_substr("lorem ipsum dolor sit amet", 0, 0, "test ft_substr 3"), "", true);
	m_safe_string_assert_free(ft_substr(" a", 1, 1, "test ft_substr 4"), "a", true);
}
