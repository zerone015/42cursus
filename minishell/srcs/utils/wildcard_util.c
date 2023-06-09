/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:49:01 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/05 13:38:41 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	init_caches(t_wildcard *wc)
{
	int	row;
	int	col;

	wc->caches = safe_malloc((wc->p_len + 1) * sizeof(int *));
	row = -1;
	while (++row <= wc->p_len)
		wc->caches[row] = safe_malloc((wc->f_len + 1) * sizeof(int));
	row = -1;
	while (++row <= wc->p_len)
	{
		col = -1;
		while (++col <= wc->f_len)
			wc->caches[row][col] = -1;
	}
}

static int	match(int p_idx, int f_idx, t_wildcard *wc)
{
	if (wc->caches[p_idx][f_idx] != -1)
		return (wc->caches[p_idx][f_idx]);
	if (p_idx < wc->p_len \
		&& f_idx < wc->f_len \
		&& wc->pattern[p_idx] == wc->filename[f_idx])
	{
		wc->caches[p_idx][f_idx] = match(p_idx + 1, f_idx + 1, wc);
		return (wc->caches[p_idx][f_idx]);
	}
	if (p_idx == wc->p_len)
		return (f_idx == wc->f_len);
	if (wc->pattern[p_idx] == '*')
	{
		if (match(p_idx + 1, f_idx, wc) \
			|| (f_idx < wc->f_len && match(p_idx, f_idx + 1, wc)))
		{
			wc->caches[p_idx][f_idx] = TRUE;
			return (TRUE);
		}
	}
	wc->caches[p_idx][f_idx] = FALSE;
	return (FALSE);
}

int	match_wildcard(char *pattern, struct dirent *file)
{
	t_wildcard	wc;

	wc.pattern = pattern;
	wc.filename = file->d_name;
	wc.p_len = ft_strlen(pattern);
	wc.f_len = ft_strlen(file->d_name);
	init_caches(&wc);
	return (match(0, 0, &wc));
}
