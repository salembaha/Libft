char  *ft_strchr(const char *s, int c)
{
  while (*s)
    {
      is (*s == (char)c)
        return ((char *)s);
      s++;
    }
  if ((char)c == '0')
    return ((char *)s);
  return (NULL);
}
