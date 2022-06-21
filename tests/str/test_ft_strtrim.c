/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strtrim.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 17:43:19 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/21 11:17:10 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_strtrim)
{
	m_safe_string_assert_free(ft_strtrim("lorem \n ipsum \t dolor \n sit \t amet", " "), "lorem \n ipsum \t dolor \n sit \t amet", true);
	m_safe_string_assert_free(ft_strtrim(" a", " \t\n\v\f\r"), "a", true);
	m_safe_string_assert_free(ft_strtrim("  \t \t \n   \n\n\n\t", " \n\t"), "", true);
}

////////////////////////////////////////////////////////////////////////////////
