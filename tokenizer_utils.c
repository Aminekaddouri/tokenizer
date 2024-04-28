/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaddouri <kaddouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 23:02:29 by kaddouri          #+#    #+#             */
/*   Updated: 2024/04/28 03:14:12 by kaddouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	ft_is_separator(char *s)
{
	if (!ft_strncmp(s, "&&", 2) || *s == ' ' || *s == '\t'
		|| *s == '<' || *s == '>' || *s == '|' || *s == '(' || *s == ')')
		return (1);
	return (0);
}

void	ft_skip_spaces(char **line)
{
	while (**line && ft_isspace(**line))
				(*line)++;
}

int	ft_is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}

bool	ft_skip_quotes(char *line, size_t *i)
{
	char	quote;

	quote = line[*i];
	if (ft_strchr(line + *i + 1, quote))
	{
		(*i)++;
		while (line[*i] != quote)
			(*i)++;
		(*i)++;
		return (true);
	}
	return (false);
}

void	ft_print_quote_err(char c)
{
	ft_putstr_fd("minishell: unexpected EOF while looking for matching `", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("'\n", 2);
	g_minishell.exit_s = 258;
}

