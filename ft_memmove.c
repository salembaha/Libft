void *ft_memmove(void *dst, const void *src, size_t n)
{
// declare tmp ptr and counter;
	unsigned char *tmp_src;
	unsigned char *tmp_dst;
	size_t i;
// if NULL, return NULL;
if (!src && !dst)
	return (NULL);
// assign converted values to tmp pointers as to not touch original values
tmp_src = (unsigned const char *) src;
tmp_dst = (unsigned char *) dst;
i = 0;
// check if adress of dst > src, if so, copy from end to start
if (tmp_dst > tmp_src)
	while (n-- > 0)
		tmp_dst[n] = tmp_src[n];
// check if adress of dst !> src, if so, copy from start to end
else
{
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		i++;
	}
}
return (dst);
