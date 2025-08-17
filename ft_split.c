/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabahass <sabahass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 23:07:01 by sabahass          #+#    #+#             */
/*   Updated: 2025/08/17 23:53:21 by sabahass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	count_words;
	int	in_word_flag;
	int	i;

	count_words = 0;
	in_word_flag = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && !in_word_flag)
		{
			in_word_flag = 1;
			count_words++;
		}
		else if (str[i] == c)
			in_word_flag = 0;
		i++;
	}
	return (count_words);
}

static char	*getword(const char *s, char c, int *index)
{
	char	*word;
	int		start;
	int		len;
	int		i;

	while (s[*index] == c && s[*index] != '\0')
		(*index)++;
	start = *index;
	while (s[*index] != c && s[*index] != '\0')
		(*index)++;
	len = *index - start;
	word = malloc((len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_result(char **result, int count)
{
	while (count > 0)
		free(result[--count]);
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		word_count;
	int		index;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	index = 0;
	i = 0;
	while (i < word_count)
	{
		result[i] = getword(s, c, &index);
		if (!result[i])
		{
			free_result(result, i);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
