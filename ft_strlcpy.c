#include "libft.a"

size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
  size_t i;

i = 0;
if (!dst || !src)
  return (0);
if (size > 0)
  {
    while (src[i] && i < size - 1)
    {
      dst[i] = src[i];
      i++;
    }
    dst[i] = '\0';
  }
  while (src[i])
      i++;
  return (i);
}

int main(void) {
    char dest[20];
    const char *src = "Hello, world!";
    size_t ret;

    // Test 1: Normal copy
    ret = ft_strlcpy(dest, src, sizeof(dest));
    printf("Test 1: '%s' (returned %zu, expected %zu)\n", dest, ret, strlen(src));

    // Test 2: Size == 0 (should not copy, but return length)
    ret = ft_strlcpy(dest, src, 0);
    printf("Test 2: '%s' (returned %zu, expected %zu)\n", dest, ret, strlen(src));

    // Test 3: Size < src length (should truncate)
    ret = ft_strlcpy(dest, src, 6);
    printf("Test 3: '%s' (returned %zu, expected %zu)\n", dest, ret, strlen(src));

    // Test 4: Empty src
    ret = ft_strlcpy(dest, "", sizeof(dest));
    printf("Test 4: '%s' (returned %zu, expected 0)\n", dest, ret);

    return 0;
}
