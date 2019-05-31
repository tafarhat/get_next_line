#include "gnl.h"

enum e_read_return_value
{
	true = 1,
	false = 0,
	err = -1
};

static int gderr(const int fd, char **line)
{
	return (fd < 0 || line == NULL || read(fd, NULL, 0) < 0);
}

// NAME :
// 	get_line
//
// DESCRIPTION :
// 	L'objectif est de chercher le '\n' dans la ligne,si oui ,on va appeler
// 	la fonction ft_strchr et remplacer le '\n' par '\0' et on va  stocker
// 	tous ca dans une variable temporaire, apres on va appeler la fonction 
// 	ft_strdup pour dipliquer le reste dans la chaine reste
// 	et retourner true,
//
// PARAMS :
// 	reste, une chaine de caractere ou va stocker le reste 
// 	line, un tableau du chaine de caractere 
//
// RETURN VALUE :
// 	
static int ft_getline(char **reste, char **line) // faker 3lash khasna char **reste machi char *reste  
{
	char *temp;
	char **old;
			// *reste = "abcd'\n'efg'\n'hij'\n"
	if (*reste == NULL)
		return false;
	else
	{
		old = *reste;
		temp = ft_strchr(*reste, '\n');       // ===> temp = "abcd"
		*temp = '\0';			      // ===> temp = "abcd'\0'"
		*line = ft_strdup(*reste);	      // ===> reste = "efg'\n'hij'\n'"
		*reste = ft_strdup(temp + 1);
		ft_strdel(old);
		return (true);}

}

static int readline(char *reste)
{
	int ret;
	char buff[BUFF_SIZE];                      // BUFF_SIZE = 7
	char *tmp;
	if (reste == NULL)
		reste = ft_strnew(0);
	while (ret = read(fd,buff,BUFF_SIZE) > 0)  //  
	{
		buff[ret] = '\0';
		tmp = *reste;
		ft_strjoin(*reste,buff);
		if (ft_strchr(*reste, '\n'))
			break;
		ft_strdel(&tmp);
	}
	return ret;
}

int gnl(const int fd, char **line)
{
	static char *reste[255] = {NULL}; // declarartion d'un tableau de chaines de caracteres de taille 255

	if (gderr(fd,line))              // gestion d'erreur 
		return (err);
	if (ft_getline(&reste[fd],line))   // Si la ligne contient un '\n' extracter la ligne et retourner 1
		return (false);                 
	int ret = readline(reste[fd]);    // Sinon on va lire jusqu a le '\n'. la valeur de ret signifie ce qui a lire la fonction read  

	if (ret < 0)                      // erreur
		return (err);
	else if (ret > 0)    		  // scenarion parfait
		return (true);
	else      			  // 
	{
		if (reste[fd] != NULL)     

		{
			ft_getline(reste[fd],line);
			return (true);
		}
		else
			return (false);
	}

	/* 1- verifier les variable par gderr */
	/* 2- chercher le \n dans le reste */
	/* 2-1- si oui , la fonction getline ketjbad ligne dans
	 * le reste et la supprimer	 */
	/* 2-2- Sinon il va reader une partie dans le fd */
	/* 3-1-	 */
}
