#include "libft.h"

char  *ft_strrchr(const char *s, int c)
{
    int last;
    
    last = ft_strlen(s);
    while (last >= 0)
    {
      if (s[last] == (char)c)
        return ((char *)(s + last));
      last--;
    }
    return (NULL);
}
