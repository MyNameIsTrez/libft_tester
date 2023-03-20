/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_is_lower.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 14:12:26 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_is_lower)
{
	massert(ft_is_lower('a'), (bool)true);
	massert(ft_is_lower('z'), (bool)true);

	massert(ft_is_lower('A'), (bool)false);
	massert(ft_is_lower('Z'), (bool)false);
	massert(ft_is_lower('#'), (bool)false);
}
