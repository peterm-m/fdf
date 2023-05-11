/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:09:20 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/08 04:12:43 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

//char	*get_next_line(int fd); 
//void	ft_read_and_save(t_queue *file, int fd);
//char	*ft_get_line(t_queue *file, char *save);
//void	ft_save_file(t_queue *file, char *save);
//void	ft_clean_file(t_queue *file);
//int		ft_find_newline(char *save);
//t_queue	*ft_creat_queue(void);
//char	*ft_join_nodes(t_queue *file, int len, char *line);

static char	*ft_strcpy_to(char *save, char sep)
{
	// Devuelve cadena desde inicio hasta sep. Pone en save desde sep hasta final.
}

static bool	ft_read_inque(t_queue *q,char  sep, int fd)
{
	// funcion añade buffers hasta que encuentra sep o llega al final del archivo.
	// si encuentra sep: return true
	// si encuentra EOF: return false
	// si encuentra SEP y EOF simultaneo return true
}

static char *ft_join_dequeue(t_queue *q)
{
	// reserva memoria para: (len primer nodo) + (nºnodos * size_nodo) + (len_ultimo nodo)
	// junta nodos mientras los elimina.
}

char	*gnl(int fd, char sep)
{
	static char	save[FD_MAX][BUFSIZ];
	t_queue		*q;
	char		*dest;

	if (read(fd, 0, 0) < 0)
	{
		if (fd >= 0 && fd < FD_MAX)
			save[fd][0] = '\0';
		return (NULL);
	}
	else if (ft_strchr(save[fd], sep) != NULL)
		 dest = ft_strcpy_to(save, sep); // Si sep != EOF y esta en save.
	else
	{
		q = ft_queuenew((void *) save[fd]);
		if (ft_read_inque(q, sep, fd))
			q->tail->content  = ft_strcpy_to(q->tail, sep); // En ultimo nodo, desde inicio hasta sep pertenece al nodo. el resto a save.
		dest = ft_join_dequeue(q); // dequeueu juntar todos los nodos
	}
	return (dest);
}

//char	*get_file()
//{
//	gnl(fd, EOF);
//}

// char *get_next_line(int fd)
//{
//	retunr (fd, '/n');	
//}

//char	*get_next_line(int fd)
//{
//si	static char	save[FD_MAX][STATIC_SIZE + 1];
//si	t_queue		*file;
//si	char		*dest;
//si
//si	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
//si	{
//si		if (fd >= 0 && fd < FD_MAX)
//si			save[fd][0] = '\0';
//si		return (NULL);
//si	}
//si	file = ft_creat_queue();
//	if (ft_find_newline(save[fd]) == 0)
//		ft_read_and_save(file, fd);
//	dest = ft_get_line(file, save[fd]);
//	ft_save_file(file, save[fd]);
//	ft_clean_file(file);
//	if (dest[0] == '\0' && save[fd][0] == '\0')
//	{
//		free(dest);
//		return (NULL);
//	}
//	return (dest);
//}
//
//void	ft_read_and_save(t_queue *file, int fd) // ft_queuein
//{
//	t_lstbuff	*node;
//	int			len_read;
//
//	len_read = 1;
//	while (len_read != 0)
//	{
//		node = (t_lstbuff *) malloc(sizeof(t_lstbuff));
//		if (!node)
//			break ;
//		node->next = NULL;
//		len_read = read(fd, node->string, BUFFER_SIZE);
//		node->string[len_read] = '\0';
//		if (file->ini == NULL)
//			file->ini = node;
//		else
//			file->end->next = node;
//		file->end = node;
//		file->len++;
//		if (ft_find_newline(node->string) != 0)
//			break ;
//	}
//}
//
//char	*ft_get_line(t_queue *file, char *save)
//{
//	char		*line;
//	int			i;
//	int			j;
//
//	i = 0;
//	j = 0;
//	line = (char *) malloc((file->len + 1) * BUFFER_SIZE);
//	if (!line)
//		return (line);
//	if (save)
//	{
//		while (save[i] != '\0')
//		{
//			line[j++] = save[i];
//			if (save[i++] == '\n')
//				break ;
//		}
//	}
//	return (ft_join_nodes(file, j, line));
//}
//
//char	*ft_join_nodes(t_queue	*file, int len, char *line) // ft_queuede
//{
//	t_lstbuff	*aux;
//	int			i;
//	int			j;
//
//	i = 0;
//	j = len;
//	aux = file->ini;
//	while (aux)
//	{
//		while (aux->string[i] != '\0')
//		{
//			line[j++] = aux->string[i];
//			if (aux->string[i++] == '\n')
//				break ;
//		}
//		i = 0;
//		aux = aux->next;
//	}
//	line[j] = '\0';
//	return (line);
//}
//
//void	ft_save_file(t_queue *file, char *save)
//{
//	int	i;
//	int	j;
//
//	i = 0;
//	j = 0;
//	if (file->end)
//	{
//		while (file->end->string[i] != '\0')
//			if (file->end->string[i++] == '\n')
//				break ;
//		while (file->end->string[i] != '\0')
//			save[j++] = file->end->string[i++];
//	}
//	else
//	{
//		while (save[i] != '\0')
//			if (save[i++] == '\n')
//				break ;
//		while (save[i] != '\0')
//			save[j++] = save[i++];
//	}
//	save[j] = '\0';
//}
//
// queue new
//t_queue	*ft_creat_queue(void)
//{
//	t_queue	*file;
//
//	file = (t_queue *) malloc(sizeof(t_queue));
//	if (!file)
//		return ((t_queue *) NULL);
//	file->ini = (t_lstbuff *) NULL;
//	file->end = (t_lstbuff *) NULL;
//	file->len = 0;
//	return (file);
//}
//
//// ft_strchr
//int	ft_find_newline(char *str)
//{
//	int	i;
//
//	i = 0;
//	if (!str)
//		return (0);
//	while (str[i] != '\0' )
//	{
//		if (str[i++] == '\n')
//			return (i);
//	}
//	return (0);
//}
//
//// ft_queuclean
//void	ft_clean_file(t_queue *file)
//{
//	t_lstbuff	*aux1;
//	t_lstbuff	*aux2;
//
//	aux1 = file->ini;
//	while (aux1)
//	{
//		aux2 = aux1->next;
//		free(aux1);
//		aux1 = aux2;
//	}
//	free(aux1);
//	free(file);
//}