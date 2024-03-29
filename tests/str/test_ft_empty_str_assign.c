/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_empty_str_assign.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 20:13:08 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/22 12:04:22 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_empty_str_assign)
{
	char	*str;

	m_safe_assert(t_status, ft_empty_str_assign(&str), OK, ERROR, true);
}
