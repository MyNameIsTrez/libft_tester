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

#include "libft_tests.h"

int	int_cmp_fn(void *lst_content, void *needle)
{
	int	*lst_content_int_ptr = lst_content;
	int	*needle_int_ptr = needle;

	if (*lst_content_int_ptr == *needle_int_ptr)
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
	m_safe_assert(void *, new_lst = ft_lst_new_front(&lst, &nbr1, "test ft_lst_remove_if_int 1"), new_lst, NULL, false);

	if (!was_malloc_unstable)
	{
		massert((void *)lst, (void *)new_lst);
		massert(*(int *)new_lst->content, 1);
		massert((void *)lst->next, (void *)old_lst);
	}

	// Remove `1`
	if (!was_malloc_unstable)
	{
		ft_lst_remove_if(&lst, &nbr1, int_cmp_fn);

		massert((void *)lst, NULL);
	}


	// Add `1` to front
	if (!was_malloc_unstable)
	{
		old_lst = lst;
		m_safe_assert(void *, new_lst = ft_lst_new_front(&lst, &nbr1, "test ft_lst_remove_if_int 2"), new_lst, NULL, false);
	}

	if (!was_malloc_unstable)
	{
		massert((void *)lst, (void *)new_lst);
		massert(*(int *)new_lst->content, 1);
		massert((void *)new_lst->next, NULL);
	}

	// Add `2` to front
	int	nbr2 = 2;
	if (!was_malloc_unstable)
	{
		old_lst = lst;
		m_safe_assert(void *, new_lst = ft_lst_new_front(&lst, &nbr2, "test ft_lst_remove_if_int 3"), new_lst, NULL, false);
	}

	if (!was_malloc_unstable)
	{
		massert((void *)lst, (void *)new_lst);
		massert(*(int *)new_lst->content, 2);
		massert((void *)new_lst->next, (void *)old_lst);

		massert(*(int *)lst->next->content, 1);
		massert((void *)lst->next->next, NULL);
	}

	// Add `3` to front
	int	nbr3 = 3;
	if (!was_malloc_unstable)
	{
		old_lst = lst;
		m_safe_assert(void *, new_lst = ft_lst_new_front(&lst, &nbr3, "test ft_lst_remove_if_int 4"), new_lst, NULL, false);
	}

	if (!was_malloc_unstable)
	{
		massert((void *)lst, (void *)new_lst);
		massert(*(int *)new_lst->content, 3);
		massert((void *)new_lst->next, (void *)old_lst);

		massert(*(int *)new_lst->next->content, 2);

		massert(*(int *)lst->next->next->content, 1);
		massert((void *)lst->next->next->next, NULL);
	}

	// Remove `2`
	if (!was_malloc_unstable)
	{
		ft_lst_remove_if(&lst, &nbr2, int_cmp_fn);

		massert(*(int *)lst->content, 3);
		massert(*(int *)lst->next->content, 1);
		massert((void *)lst->next->next, NULL);
	}

	// Remove `3`
	if (!was_malloc_unstable)
	{
		ft_lst_remove_if(&lst, &nbr3, int_cmp_fn);

		massert(*(int *)lst->content, 1);
		massert((void *)lst->next, NULL);
	}

	// Remove `1`
	if (!was_malloc_unstable)
	{
		ft_lst_remove_if(&lst, &nbr1, int_cmp_fn);

		massert((void *)lst, NULL);
	}
}

Test(ft_lst_remove_if_int_several)
{
	t_list	*new_lst;
	t_list	*old_lst;

	t_list	*lst = NULL;
	old_lst = lst;

	int	nbr1 = 1;


	// Add `1` to front
	if (!was_malloc_unstable)
	{
		old_lst = lst;
		m_safe_assert(void *, new_lst = ft_lst_new_front(&lst, &nbr1, "test ft_lst_remove_if_int_several 1"), new_lst, NULL, false);
	}

	if (!was_malloc_unstable)
	{
		massert((void *)lst, (void *)new_lst);
		massert(*(int *)new_lst->content, 1);
		massert((void *)new_lst->next, NULL);
	}

	// Add `1` to front
	if (!was_malloc_unstable)
	{
		old_lst = lst;
		m_safe_assert(void *, new_lst = ft_lst_new_front(&lst, &nbr1, "test ft_lst_remove_if_int_several 2"), new_lst, NULL, false);
	}

	if (!was_malloc_unstable)
	{
		massert((void *)lst, (void *)new_lst);
		massert(*(int *)new_lst->content, 1);
		massert((void *)new_lst->next, (void *)old_lst);

		massert(*(int *)lst->next->content, 1);
		massert((void *)lst->next->next, NULL);
	}

	// Add `1` to front
	if (!was_malloc_unstable)
	{
		old_lst = lst;
		m_safe_assert(void *, new_lst = ft_lst_new_front(&lst, &nbr1, "test ft_lst_remove_if_int_several 3"), new_lst, NULL, false);
	}

	if (!was_malloc_unstable)
	{
		massert((void *)lst, (void *)new_lst);
		massert(*(int *)new_lst->content, 1);
		massert((void *)new_lst->next, (void *)old_lst);

		massert(*(int *)new_lst->next->content, 1);

		massert(*(int *)lst->next->next->content, 1);
		massert((void *)lst->next->next->next, NULL);
	}


	// Remove `1`
	if (!was_malloc_unstable)
	{
		ft_lst_remove_if(&lst, &nbr1, int_cmp_fn);

		massert((void *)lst, NULL);
	}
}

int	string_cmp_fn(void *lst_content, void *needle)
{
	char	**lst_content_string = lst_content;
	char	*needle_string = needle;

	if (ft_str_eq(*lst_content_string, needle_string))
		return (0);
	return (1);
}

Test(ft_lst_remove_if_string)
{
	t_list	*new_lst;
	t_list	*old_lst;

	t_list	*lst = NULL;

	char	*str1 = "foo";
	ft_lst_remove_if(&lst, str1, string_cmp_fn);
	massert((void *)lst, NULL);


	// Add `"foo"` to front
	old_lst = lst;
	m_safe_assert(void *, new_lst = ft_lst_new_front(&lst, &str1, "test ft_lst_remove_if_string 1"), new_lst, NULL, false);

	if (!was_malloc_unstable)
	{
		massert((void *)lst, (void *)new_lst);
		massert(*(char **)new_lst->content, "foo");
		massert((void *)lst->next, (void *)old_lst);
	}

	// Remove `"foo"`
	if (!was_malloc_unstable)
	{
		ft_lst_remove_if(&lst, str1, string_cmp_fn);

		massert((void *)lst, NULL);
	}


	// Add `"foo"` to front
	if (!was_malloc_unstable)
	{
		old_lst = lst;
		m_safe_assert(void *, new_lst = ft_lst_new_front(&lst, &str1, "test ft_lst_remove_if_string 2"), new_lst, NULL, false);
	}

	if (!was_malloc_unstable)
	{
		massert((void *)lst, (void *)new_lst);
		massert(*(char **)new_lst->content, "foo");
		massert((void *)new_lst->next, NULL);
	}

	// Add `"bar"` to front
	char	*str2 = "bar";
	if (!was_malloc_unstable)
	{
		old_lst = lst;
		m_safe_assert(void *, new_lst = ft_lst_new_front(&lst, &str2, "test ft_lst_remove_if_string 3"), new_lst, NULL, false);
	}

	if (!was_malloc_unstable)
	{
		massert((void *)lst, (void *)new_lst);
		massert(*(char **)new_lst->content, "bar");
		massert((void *)new_lst->next, (void *)old_lst);

		massert(*(char **)lst->next->content, "foo");
		massert((void *)lst->next->next, NULL);
	}

	// Add `"baz"` to front
	char	*str3 = "baz";
	if (!was_malloc_unstable)
	{
		old_lst = lst;
		m_safe_assert(void *, new_lst = ft_lst_new_front(&lst, &str3, "test ft_lst_remove_if_string 4"), new_lst, NULL, false);
	}

	if (!was_malloc_unstable)
	{
		massert((void *)lst, (void *)new_lst);
		massert(*(char **)new_lst->content, "baz");
		massert((void *)new_lst->next, (void *)old_lst);

		massert(*(char **)new_lst->next->content, "bar");

		massert(*(char **)lst->next->next->content, "foo");
		massert((void *)lst->next->next->next, NULL);
	}

	// Remove `"bar"`
	if (!was_malloc_unstable)
	{
		ft_lst_remove_if(&lst, str2, string_cmp_fn);

		massert(*(char **)lst->content, "baz");
		massert(*(char **)lst->next->content, "foo");
		massert((void *)lst->next->next, NULL);
	}

	// Remove `"baz"`
	if (!was_malloc_unstable)
	{
		ft_lst_remove_if(&lst, str3, string_cmp_fn);

		massert(*(char **)lst->content, "foo");
		massert((void *)lst->next, NULL);
	}

	// Remove `"foo"`
	if (!was_malloc_unstable)
	{
		ft_lst_remove_if(&lst, str1, string_cmp_fn);

		massert((void *)lst, NULL);
	}
}
