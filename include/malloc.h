/*
** malloc.h for malloc in /home/auzou_t/rendu/PSU_2014_malloc/thibaud
** 
** Made by Thibaud Auzou
** Login   <auzou_t@epitech.net>
** 
** Started on  Fri Jan 30 13:49:23 2015 Thibaud Auzou
** Last update Fri Feb 13 16:21:05 2015 Thibaud Auzou
*/

#ifndef MALLOC_H_
# define MALLOC_H_

# define ALIGN		8

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stddef.h>
# include <stdint.h>

typedef struct		s_header
{
  struct s_header      	*next;
  struct s_header      	*prev;
  struct s_header	*next_free;
  struct s_header	*prev_free;
  size_t		size;
  char			is_free;
  char			_pad[7];
}			t_header;

/*
** Malloc
*/
void			*malloc(size_t size);
void			*cut_free_space(t_header *elem, size_t size, int pop);
void			*new_alloc(size_t size);
t_header		*set_new_end(size_t size);
t_header		*first_alloc(t_header *first, size_t size);

/*
** Free
*/
void			free(void *ptr);
t_header		*backward_fusion(t_header *elem);
t_header		*forward_fusion(t_header *elem);

/*
** Realloc
*/
void			*realloc(void *ptr, size_t size);
void			*enlarge_alloc(t_header *elem, size_t size);
void			*move_alloc(t_header *elem, size_t size);

/*
** Calloc
*/
void			*calloc(size_t nmemb, size_t size);

/*
** Memalign
*/
void			*memalign(size_t alignement, size_t size);
int			posix_memalign(void **memptr,
				       size_t alignment,
				       size_t size);
void			*aligned_alloc(size_t alignment, size_t size);

/*
** Show Alloc Mem
*/
void			show_alloc_mem(void);

/*
** Size & Padding
*/
size_t			calc_alloc_size(size_t size);
size_t			padd_size(size_t size);

/*
** Gobal Variable Wrapping
*/
t_header		**start(void);
t_header		**v_end(void);
size_t			page_size(void);
pthread_mutex_t		*mutex(void);

/*
** Free List
*/
int			push(t_header *elem);
int			push_first(t_header *elem, t_header *tmp2);
int			push_last(t_header *elem, t_header *tmp);
int			pop(t_header *elem);
t_header		**first(void);
int			dump(void);

#endif /* !MALLOC_H_ */
