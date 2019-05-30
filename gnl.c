#include "gnl.h"

enum e_read_return_value
{
	true = 1, false = 0, err = -1
};

static int gderr(const int fd, char **line)
{
	return (fd < 0 || line == NULL || read(fd, NULL, 0) < 0);
}

// NAME :
// 	get_line
//
// DESCRIPTION :
// 	
// PARAMS :
// 	reste, une  
// 	line, 
//
// RETURN VALUE :
// 	
static int ft_getline(char *reste, char **line)  
{

}

static int readline(char *reste)
{

}

int gnl(const int fd, char **line)
{
	static char *reste[255] = {NULL}; // declarartion d'un tableau de chaines de caracteres de taille 255

	if (gderr(fd,line))              // gestion d'erreur 
		return (err);
	if (ft_getline(reste[fd],line))   // Si la ligne contient un '\n' extracter la ligne et retourner 1
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
