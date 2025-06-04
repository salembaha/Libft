void *ft_memcpy(void *dst, const void *src, size_t n)
{
// declare temporary pointers for src and dst;
	unsigned char *tmp_src;
	unsigned char *tmp_dst;
// this function returns so tell function what to do in NULL case;
	if (dst == (void *)0 && src == (void *)0)
		return (dst);
// make both temporary pointers equal to src and dst converted to unsigned char *;
tmp_src = (unsigned char *) src;
tmp_dst = (unsigned char *) dst;
	while (n > 0)
	{
		*(tmp_dst++) = *(tmp_src++);
		n--;
	}
return (dst);

