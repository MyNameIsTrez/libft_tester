/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strtrim_whitespace.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 17:41:08 by sbos          #+#    #+#                 */
/*   Updated: 2022/05/06 16:22:12 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_strtrim_whitespace)
{
	m_safe_string_assert(ft_strtrim_whitespace(" a"), "a", true);
	m_safe_string_assert(ft_strtrim_whitespace(" \n\t foo bar \n\t "), "foo bar", true);
	m_safe_string_assert(ft_strtrim_whitespace("\t\n\r\v\f  469 \n"), "469", true);
}

////////////////////////////////////////////////////////////////////////////////
