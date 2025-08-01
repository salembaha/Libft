#include "libft.h"

void  ft_lstclear(t_list **lst, void (*del)(void*))
{
  t_list  *current;
  t_list  *next;

  if (lst != NULL && del != NULL)
  {
    current = *lst;
    while (current != NULL)
    {
      next = current->next;
      del(current->content);
      free(current);
      current = next;
    }
    *lst = NULL;
  }
}
