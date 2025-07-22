#include "libft.h"
#include <stdio.h>

size_t  count_tokens(char const *str, char delimiter)
{
    size_t  tokens;
    bool    inside_token;

	tokens = 0;
	inside_token = false;
    while (*str)
    {
        inside_token = false;
        while (*str == delimiter && *str)
        ++str;
        while (*str != delimiter && *str)
        {
            if (!inside_token)
            inside_token = true;
			str++;
        }
		if (inside_token)
        tokens++;
    }
    return tokens;
}

int	safe_malloc(char **token_v, int position, size_t buffer)
{
	int	i;

	i = 0;
	token_v[position] = malloc(buffer);
	if (NULL == token_v[position])
	{
		while (i < position)
		{
			free(token_v[i++]);
		}
		free(token_v);
		return 1;
	}
	return 0;
}

int	fill(char **token_v, char const *s, char delimiter)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == delimiter && *s)
		++s;
		while (*s != delimiter && *s)
		{
			++len;
			++s;
		}
		if (len)
		{
			if (safe_malloc(token_v, i, len +1))
			return (1);
		}
		ft_strlcpy(token_v[i], s - len, len + 1);
		++i;
	}
	return 0;
}

// count the tokens in str
// allocate memory for array of str
// copy token to the right position
char    **ft_split(char const *s, char c)
{
	size_t tokens;
	char **token_v;

	if (NULL == s)
		return NULL;
	tokens = 0;
	tokens = count_tokens(s, c);
	token_v = malloc((tokens + 1) * sizeof(char *));
	if (NULL == token_v)
		return NULL;
		token_v[tokens] = NULL;
	if (fill(token_v, s, c))
		return NULL;
	return token_v;
}

int	main()
{
	char	*s = "  Hello Ting World, dude I test test tiet love you!!";

	char	**v = ft_split(s, ' ');

	while (*v)
	printf("%s\n", *v++);
}
