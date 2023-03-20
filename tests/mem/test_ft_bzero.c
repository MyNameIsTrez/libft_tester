/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_bzero.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 15:20:13 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_bzero)
{
	char	str[4];

	str[0] = 'f';
	str[1] = 'o';
	str[2] = 'o';
	str[3] = '\0';
	ft_bzero(str, 2);

	massert(str, "");
	massert(str[0], (char)0);
	massert(str[1], (char)0);
	massert(str[2], (char)'o');
	massert(str[3], (char)'\0');
}
