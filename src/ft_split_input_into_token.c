/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_input_into_token.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicchio <tpicchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:03:04 by tpicchio          #+#    #+#             */
/*   Updated: 2023/12/20 14:27:42 by tpicchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_consecutive_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i + 1])
	{
		if ((ft_isspace(str[i]) && ft_isspace(str[i + 1]))
			|| (ft_isspace(str[i]) && str[i] != ' '))
			return (1);
		i++;
	}
	if (ft_isspace(str[0]) || ft_isspace(str[i]))
		return (1);
	return (0);
}

static char	**ft_one_arg(char *str, char sep)
{
	char	**token;

	if (ft_consecutive_space(str) == 1)
		ft_error(1, NULL, NULL);
	sep = ' ';
	token = ft_split(str, sep);
	if (token == NULL)
		ft_error(0, NULL, NULL);
	return (token);
}

static void	ft_multiple_arg_is_triky(char **token)
{
	int	i;
	int	j;

	i = 0;
	while (token[i])
	{
		j = 0;
		while (token[i][j])
		{
			if (token[i][j] == ' ')
			{
				ft_error(1, token, NULL);
			}
			j++;
		}
		i++;
	}
}

static char	**ft_multiple_arg(char **matrix, int size)
{
	char	**token;
	int		i;

	i = 1;
	token = malloc(size * sizeof(char *));
	if (token == NULL)
		ft_error(2, NULL, NULL);
	while (i < size)
	{
		token[i - 1] = ft_strdup(matrix[i]);
		if (token[i - 1] == NULL)
			ft_error(2, token, NULL);
		i++;
	}
	token[size - 1] = NULL;
	ft_multiple_arg_is_triky(token);
	i = 0;
	while (token[i])
		i++;
	if (i < 2)
		ft_error(0, token, NULL);
	return (token);
}

char	**ft_split_input_into_token(int ac, char **av)
{
	char	**token;

	token = NULL;
	if (ac < 2)
	{
		ft_error(0, NULL, NULL);
	}
	else if (ac == 2)
	{
		if (av[1][0] == '\0')
			ft_error(1, NULL, NULL);
		token = ft_one_arg(av[1], ' ');
	}
	else if (ac > 2)
	{
		token = ft_multiple_arg(av, ac);
	}
	if (token[0] == NULL)
		ft_error(0, NULL, NULL);
	return (token);
}
