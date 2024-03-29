/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_tolower.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 14:52:52 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_tolower)
{
	massert(ft_tolower('A'), 'a');
	massert(ft_tolower('Z'), 'z');
	massert(ft_tolower('a'), 'a');
	massert(ft_tolower('z'), 'z');
	massert(ft_tolower('#'), '#');
}
