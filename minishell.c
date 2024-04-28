/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaddouri <kaddouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:18:25 by kaddouri          #+#    #+#             */
/*   Updated: 2024/04/28 03:13:44 by kaddouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	g_minishell;

void display_prompt(char **line)
{
	*line = readline("Minishell:~$ ");
	if (!*line)
	{
		printf("exit\n");
		exit(1);
	}
	if (*line[0])
		add_history(*line);
}

const char	*get_token_type_name(t_token_type type)
{
	const char	*token_type_names[11];

	token_type_names[0] = "T_IDENTIFIER";
	token_type_names[1] = "T_LESS";
	token_type_names[2] = "T_GREAT";
	token_type_names[3] = "T_DLESS";
	token_type_names[4] = "T_DGREAT";
	token_type_names[5] = "T_PIPE";
	token_type_names[6] = "T_O_PARENT";
	token_type_names[7] = "T_C_PARENT";
	token_type_names[8] = "T_AND";
	token_type_names[9] = "T_OR";
	token_type_names[10] = "T_NL";
	if (type >= 0 && type < 11)
		return (token_type_names[type]);
	return ("UNKNOWN");
}

void	display_tokens(t_token *tokens)
{
	t_token	*token;

	token = tokens;
	while (token)
	{
		printf("Token: \033[0;36m %-20s \033[0m |\t \
			Type: \033[0;35m %-18s \033[0m \n",
			token->value, get_token_type_name(token->type));
		printf("--------------------------------------------------\n");
		token = token->next;
	}
}

int main(int ac, char **av, char **envp) {
    (void)av;
    (void)ac;
    (void)envp;

    if (ac != 1)
	{
		printf("This program does not accept arguments\n");
		exit(0);
	}
    while (1) {
        display_prompt(&g_minishell.line);
		g_minishell.tokens = ft_tokenize();
		display_tokens(g_minishell.tokens);
    }
}
