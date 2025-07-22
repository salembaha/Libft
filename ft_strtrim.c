#include "libft.h"

static int  is_in_set(char c, const char *set)
{
  while (*set)
    {
      if (c == *set)
        return (1);
      set++;
    }
  return (0);
}

char  *ft_strtrim(char const *s1, char const *set)
{
  size_t  start;
  size_t  end;
  char *trimmed_str;

  if (!s1 || !set)
    return (NULL);
  start = 0;
  end = ft_strlen(s1);
  while(s1[start] && is_in_set(s1[start], set))
    start++;
  while (end > start && is_in_set(s1[end - 1], set))
    end--;
  trimmed_str = (char *)malloc(sizeof(char) * (end - start + 1));
  if (!trimmed_str)
    return (NULL);
  ft_strlcpy(trimmed_str, &s1[start], end - start + 1);
    return (trimmed_str);
}

int main(void)
{
    char *s1 = "xxyyyyTingILoveYouyyyyxxyxx";
    char *set = "xy";
    char *trimmed_str = ft_strtrim(s1, set);
    printf("Trimmed String: '%s'\n", trimmed_str);
    free(trimmed_str);
}
