/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:39:30 by pmoreira          #+#    #+#             */
/*   Updated: 2025/07/04 11:42:16 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	quotes_check(char *input)
{
	t_bool		quote;
	t_bool		d_quote;
	char		*error;
	const char	*temp;

	if (!input)
		return (0);
	init_proc(&temp, (const char *) input, &quote, &d_quote);
	while (*temp)
	{
		check_char_quote(&temp, &quote, &d_quote);
		temp++;
	}
	if (d_quote)
		return (parser_error("\"", 2), 0);
	else if (quote)
		return (parser_error("\'", 2), 0);
	error = syntax_error_check(input);
	if (error)
		return (parser_error(error, 2), free(error), 0);
	return (1);
}

int	pre_process_input(char **input)
{
	int		count;
	char	*new_input;

	if (!input || !*input)
		return (1);
	new_input = NULL;
	count = space_length(*input);
	if (count)
	{
		new_input = space_put(*input, count);
		if (!new_input)
			return (merror("pre_process_input:new_input"), 0);
		free (*input);
		*input = new_input;
	}
	if (count_expand_zones(*input))
	{
		*input = remove_zones(input, *input);
		if (!*input)
			return (merror("pre_process_input:remove_zones"), 0);
	}
	return (1);
}

char	*handle_limiter(char *s, t_bool *flag)
{
	char	*temp;

	if (!s || !flag)
		return (NULL);
	temp = NULL;
	if (!ft_strcmp(s, "$"))
	{
		temp = ft_strdup(s);
		if (!temp)
			return (merror("handle_limiter"), NULL);
	}
	if (flag && *flag)
	{
		temp = remove_both_quotes(s);
		if (!temp)
			return (merror("handle_limiter"), NULL);
	}
	return (temp);
}

void	make_backup(t_token *tok)
{
	if (!tok)
		return ;
	while (tok->next)
	{
		tok->backup = ft_strdup(tok->cmd);
		if (!tok->backup)
		{
			merror("make_backup");
			return (mini_cleaner(NULL, get_hell(NULL), 1));
		}
		tok = tok->next;
	}
}

void	update_prev_cmd(t_cmd *cmd)
{
	t_cmd	*temp;
	t_cmd	*prev;

	if (!cmd)
		return ;
	temp = cmd;
	prev = NULL;
	while (temp)
	{
		temp->prev = prev;
		prev = temp;
		temp = temp->next;
	}
}
