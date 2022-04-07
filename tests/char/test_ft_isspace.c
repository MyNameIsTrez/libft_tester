/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_isspace.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 14:48:22 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_isspace)
{
	massert(ft_isspace(' '), (bool)true);
	massert(ft_isspace('\t'), (bool)true);
	massert(ft_isspace('\n'), (bool)true);
	massert(ft_isspace('\v'), (bool)true);
	massert(ft_isspace('\f'), (bool)true);
	massert(ft_isspace('\r'), (bool)true);
	massert(ft_isspace('c'), (bool)false);
}

////////////////////////////////////////////////////////////////////////////////
