/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:55:22 by pmoreira          #+#    #+#             */
/*   Updated: 2025/06/07 17:12:51 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_meta(int c)
{
	return (c == '|' || c == '<' || c == '>');
}

int	is_quotes(int c)
{
	return (c == '\'' || c == '\"');
}

void	check_quotes(int c, t_bool *quote, t_bool *d_quote)
{
	if (c == '\'' && *quote)
	{
		*quote = FALSE;
		return ;
	}
	else if (c == '\"' && *d_quote)
	{
		*d_quote = FALSE;
		return ;
	}
	if (c == '\'' && !(*d_quote))
	{
		*quote = TRUE;
		return ;
	}
	else if (c == '\"' && !(*quote))
	{
		*d_quote = TRUE;
		return ;
	}
}

void	check_char_quote(const char **s, t_bool *quote, t_bool *d_quote)
{
	if (!s)
		return ;
	check_quotes(**s, quote, d_quote);
	if (**s == '\\' && *(*s + 1) && is_quotes(*(*s + 1)))
	{
		*quote = FALSE;
		*d_quote = FALSE;
		*s += 1;
	}
}

t_bool	has_expansion(char *s)
{
	t_bool		quote;
	t_bool		d_quote;
	const char	*temp;

	if (!s)
		return (0);
	init_proc(&temp, (const char *) s, &quote, &d_quote);
	while (*temp)
	{
		check_char_quote(&temp, &quote, &d_quote);
		if (!quote && *temp == '$')
			return (TRUE);
		temp++;
	}
	return (FALSE);
}
