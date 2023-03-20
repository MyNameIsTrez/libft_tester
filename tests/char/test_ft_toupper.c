/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_toupper.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 14:54:02 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_toupper)
{
	massert(ft_toupper('a'), 'A');
	massert(ft_toupper('z'), 'Z');
	massert(ft_toupper('A'), 'A');
	massert(ft_toupper('Z'), 'Z');
	massert(ft_toupper('@'), '@');
}
