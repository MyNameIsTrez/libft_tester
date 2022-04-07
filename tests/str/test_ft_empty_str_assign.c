/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_empty_str_assign.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 20:13:08 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_empty_str_assign)
{
	char	*str;

	str = NULL;
	m_safe_assert(t_success, ft_empty_str_assign(&str), SUCCESS, ERROR);
	free(str);
}

////////////////////////////////////////////////////////////////////////////////
