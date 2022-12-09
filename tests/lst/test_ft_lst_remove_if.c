/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_lst_remove_if.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 18:58:39 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/21 16:42:51 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

int	int_cmp_fn(void *lst_data, void *needle)
{
	int	*lst_data_int = lst_data;
	int	*needle_int = needle;

	if (*lst_data_int == *needle_int)
		return (0);
	return (1);
}

Test(ft_lst_remove_if_int)
{
	t_list	*new_lst;
	t_list	*old_lst;

	t_list	*lst = NULL;

	int	nbr1 = 1;
	ft_lst_remove_if(&lst, &nbr1, int_cmp_fn);
	massert((void *)lst, NULL);


	// Add `1` to front
	old_lst = lst;
	m_safe_assert(void *, new_lst = ft_lst_new_front(&lst, &nbr1), new_lst, NULL, false);

	if (NOT was_malloc_unstable)
	{
		massert(*(int *)new_lst->content, 1);
		massert((void *)lst, (void *)new_lst);
		massert((void *)lst->next, (void *)old_lst);
	}

	// Remove `1`
	if (NOT was_malloc_unstable)
	{
		ft_lst_remove_if(&lst, &nbr1, int_cmp_fn);

		massert((void *)lst, NULL);
	}


	// Add `1` to front
	if (NOT was_malloc_unstable)
	{
		old_lst = lst;
		m_safe_assert(void *, new_lst = ft_lst_new_front(&lst, &nbr1), new_lst, NULL, false);
	}

	if (NOT was_malloc_unstable)
	{
		massert((void *)lst, (void *)new_lst);
		massert(*(int *)new_lst->content, 1);
		massert((void *)new_lst->next, NULL);
	}

	// Add `2` to front
	int	nbr2 = 2;
	if (NOT was_malloc_unstable)
	{
		old_lst = lst;
		m_safe_assert(void *, new_lst = ft_lst_new_front(&lst, &nbr2), new_lst, NULL, false);
	}

	if (NOT was_malloc_unstable)
	{
		massert((void *)lst, (void *)new_lst);
		massert(*(int *)new_lst->content, 2);
		massert((void *)new_lst->next, (void *)old_lst);

		massert(*(int *)lst->next->content, 1);
		massert((void *)lst->next->next, NULL);
	}

	// Add `3` to front
	int	nbr3 = 3;
	if (NOT was_malloc_unstable)
	{
		old_lst = lst;
		m_safe_assert(void *, new_lst = ft_lst_new_front(&lst, &nbr3), new_lst, NULL, false);
	}

	if (NOT was_malloc_unstable)
	{
		massert((void *)lst, (void *)new_lst);
		massert(*(int *)new_lst->content, 3);
		massert((void *)new_lst->next, (void *)old_lst);

		massert(*(int *)new_lst->next->content, 2);

		massert(*(int *)lst->next->next->content, 1);
		massert((void *)lst->next->next->next, NULL);
	}

	// Remove `2`
	if (NOT was_malloc_unstable)
	{
		ft_lst_remove_if(&lst, &nbr2, int_cmp_fn);

		massert(*(int *)lst->content, 3);
		massert(*(int *)lst->next->content, 1);
		massert((void *)lst->next->next, NULL);
	}

	// Remove `3`
	if (NOT was_malloc_unstable)
	{
		ft_lst_remove_if(&lst, &nbr3, int_cmp_fn);

		massert(*(int *)lst->content, 1);
		massert((void *)lst->next, NULL);
	}

	// Remove `1`
	if (NOT was_malloc_unstable)
	{
		ft_lst_remove_if(&lst, &nbr1, int_cmp_fn);

		massert((void *)lst, NULL);
	}
}

int	string_cmp_fn(void *content, void *needle)
{
	char	*_content = content;
	char	*_needle = needle;

	if (ft_str_eq(_content, _needle))
		return (0);
	return (1);
}

Test(ft_lst_remove_if_string)
{
	t_list	*new_lst;
	t_list	*old_lst;

	t_list	*lst = NULL;

	char	*str1 = "foo";
	ft_lst_remove_if(&lst, &str1, int_cmp_fn);
	massert((void *)lst, NULL);


	// Add `"foo"` to front
	old_lst = lst;
	m_safe_assert(void *, new_lst = ft_lst_new_front(&lst, &str1), new_lst, NULL, false);

	if (NOT was_malloc_unstable)
	{
		massert(*(char **)new_lst->content, "foo");
		massert((void *)lst, (void *)new_lst);
		massert((void *)lst->next, (void *)old_lst);
	}

	// Remove `"foo"`
	if (NOT was_malloc_unstable)
	{
		ft_lst_remove_if(&lst, &str1, int_cmp_fn);

		massert((void *)lst, NULL);
	}


	// Add `"foo"` to front
	if (NOT was_malloc_unstable)
	{
		old_lst = lst;
		m_safe_assert(void *, new_lst = ft_lst_new_front(&lst, &str1), new_lst, NULL, false);
	}

	if (NOT was_malloc_unstable)
	{
		massert((void *)lst, (void *)new_lst);
		massert(*(char **)new_lst->content, "foo");
		massert((void *)new_lst->next, NULL);
	}

	// Add `"bar"` to front
	char	*str2 = "bar";
	if (NOT was_malloc_unstable)
	{
		old_lst = lst;
		m_safe_assert(void *, new_lst = ft_lst_new_front(&lst, &str2), new_lst, NULL, false);
	}

	if (NOT was_malloc_unstable)
	{
		massert((void *)lst, (void *)new_lst);
		massert(*(char **)new_lst->content, "bar");
		massert((void *)new_lst->next, (void *)old_lst);

		massert(*(char **)lst->next->content, "foo");
		massert((void *)lst->next->next, NULL);
	}

	// Add `"baz"` to front
	char	*str3 = "baz";
	if (NOT was_malloc_unstable)
	{
		old_lst = lst;
		m_safe_assert(void *, new_lst = ft_lst_new_front(&lst, &str3), new_lst, NULL, false);
	}

	if (NOT was_malloc_unstable)
	{
		massert((void *)lst, (void *)new_lst);
		massert(*(char **)new_lst->content, "baz");
		massert((void *)new_lst->next, (void *)old_lst);

		massert(*(char **)new_lst->next->content, "bar");

		massert(*(char **)lst->next->next->content, "foo");
		massert((void *)lst->next->next->next, NULL);
	}

	// Remove `"bar"`
	if (NOT was_malloc_unstable)
	{
		ft_lst_remove_if(&lst, &str2, int_cmp_fn);

		massert(*(char **)lst->content, "baz");
		massert(*(char **)lst->next->content, "foo");
		massert((void *)lst->next->next, NULL);
	}

	// Remove `"baz"`
	if (NOT was_malloc_unstable)
	{
		ft_lst_remove_if(&lst, &str3, int_cmp_fn);

		massert(*(char **)lst->content, "foo");
		massert((void *)lst->next, NULL);
	}

	// Remove `"foo"`
	if (NOT was_malloc_unstable)
	{
		ft_lst_remove_if(&lst, &str1, int_cmp_fn);

		massert((void *)lst, NULL);
	}
}
