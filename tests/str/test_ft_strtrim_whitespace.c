/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strtrim_whitespace.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 17:41:08 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/21 10:32:11 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_strtrim_whitespace)
{
	m_safe_string_assert_free(ft_strtrim_whitespace(" a"), "a", true);
	m_safe_string_assert_free(ft_strtrim_whitespace(" \n\t foo bar \n\t "), "foo bar", true);
	m_safe_string_assert_free(ft_strtrim_whitespace("\t\n\r\v\f  469 \n"), "469", true);
}

////////////////////////////////////////////////////////////////////////////////
