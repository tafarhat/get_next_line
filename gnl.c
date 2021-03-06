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
//	get_line
//
// DESCRIPTION :
//	L'objectif est de chercher le '\n' dans la ligne,si oui ,on va appeler
//	la fonction ft_strchr et remplacer le '\n' par '\0' et on va  stocker
//	tous ca dans une variable temporaire, apres on va appeler la fonction
//	ft_strdup pour dipliquer le reste dans la chaine reste
//	et retourner true,
//
// PARAMS :
//	reste, une chaine de caractere ou va stocker le reste
//	line, un tableau du chaine de caractere
//
// RETURN VALUE :
//
static int ft_getline(char **reste, char **line) // faker 3lash khasna char **reste machi char *reste
{
	char *temp;
	char *old;
	// *reste = "abcd'\n'efg'\n'hij'\n"
	if (*reste == NULL)
	{
		printf("reste was null\n");
		return false;
	}
	else
	{
		printf("IN:\nline [%s], reste [%s]\n", *line, *reste);
		old = *reste;
		temp = ft_strchr(*reste, '\n');		  // ===> temp = "abcd"
		if (temp == NULL)
		{
			*line = ft_strdup(*reste);
			printf("NO NEW LINE!\n line: [%s], reste [%s]\n", *line, *reste);
			printf("Affichage de la ligne :[%s]\n", *line);
			return (false);
		}
		*temp = '\0';				  // ===> temp = "abcd'\0'"
		*line = ft_strdup(*reste);		  // ===> reste = "efg'\n'hij'\n'"
		printf("Affichage de la ligne :[%s]\n", *line);
		*reste = ft_strdup(temp + 1);
		printf("Affichage de reste 1 :[%s]\n", *reste);
		ft_strdel(&old);
		return (true);
	}

}

static int readline(const int fd, char **reste)
{
	int ret;
	char buff[BUFF_SIZE];					   // BUFF_SIZE = 7
	char *tmp;

	printf("entrer fd :%d\n",fd);
	printf("entrer reste : [%s]\n", *reste);
	if (*reste == NULL)
		*reste = ft_strnew(0);
	printf("before while reste : [%s]\n", *reste);
	/* (void)getchar(); */
	while ((ret = read(fd,buff,BUFF_SIZE)) > 0)	 //
	{
		buff[ret] = '\0';
		tmp = *reste;
		printf("affiche reste BEFORE join: [%s]\nbuff : [%s]\n", *reste, buff);
		*reste = ft_strjoin(*reste, buff);
		printf("affiche reste after join: [%s]\nbuff : [%s]\n", *reste, buff);
		/* (void)getchar(); */
		if (ft_strchr(*reste, '\n'))
		{
			printf("NEWLINE WAS FOUND!\n");
			/* (void)getchar(); */
			break;
		}
		ft_strdel(&tmp);
	}
	printf("END: [%s]\nbuff : [%s]\n", *reste, buff);
	return ret;
}

int gnl(const int fd, char **line)
{
	printf("Affichage de la ligne :[%s]\n", *line);
	printf("entrer fd :%d\n",fd);
	/* (void)getchar(); */

	static char *reste[255] = {NULL}; // declarartion d'un tableau de chaines de caracteres de taille 255

	if (gderr(fd, line))			  // gestion d'erreur
		return (err);

	*line = NULL;
	if (ft_getline(&reste[fd], line))	// Si la ligne contient un '\n' extracter la ligne et retourner 1
		return (true);

	printf("===============");
	/* (void)getchar(); */
	int ret = readline(fd, &reste[fd]);	   // Sinon on va lire jusqu a le '\n'. la valeur de ret signifie ce qui a lire la fonction read

	printf(" #### after read line\n");
	/* (void)getchar(); */

	if (ret < 0)					  // erreur
		return (err);
	else if (ret > 0)
	{
		printf(" >>> extracting line: [%s], reste [%s]\n", *line, reste[fd]);
		/* (void)getchar(); */
		ft_getline(&reste[fd], line);
		printf(" <<< extracting line: [%s], reste [%s]\n", *line, reste[fd]);
		return (true);
	}
	else				  //
	{
		printf("ret was 0. line : [%s], reste [%s]\n", *line, reste[fd]);
		ft_getline(&reste[fd], line);
		if (*line != NULL)
			ft_strdel(&reste[fd]);
		printf(">>> line : [%s], reste [%s]\n", *line, reste[fd]);
		return (*line != NULL);
	}

	/* 1- verifier les variable par gderr */
	/* 2- chercher le \n dans le reste */
	/* 2-1- si oui , la fonction getline ketjbad ligne dans
* le reste et la supprimer	 */
	/* 2-2- Sinon il va reader une partie dans le fd */
	/* 3-1-	 */
}
