#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include "AlgoGenetique.c"


int main(int argc, char *argv[])
{

	/*
	serpent testSnake = {"\x66\x32\x0d\xb7\x31\x58\xa3\x5a\x25\x5d\x05\x17\x58\xe9\x5e\xd4\xab\xb2\xcd\xc6\x9b\xb4\x54\x11\x0e\x82\x74\x41\x21\x3d\xdc\x87",456};

	affiche(testSnake.gene);
	calcul(&testSnake);
*/
/*
	groupe population;
	groupe parents;
	generationAleatoire(&population);

	for(int i = 0;i<100;i++){
		evaluation(&population);
		selection(&population,&parents);
		reproduction(&population,&parents);
		mutation(&population);
	}

	//testCalcul();
*/

	int opt,nbgeneration=0;
 	groupe population,parents;

	// les valeurs par defaut.
	population.nombre=NBPOPULATION;
	parents.nombre=NBPARENTS;

 	while ((opt = getopt(argc, argv, "p:P:")) != -1) {
               switch (opt) {
               case 'p':
                   population.nombre=atoi(optarg);
                   break;
               case 'P':
                   parents.nombre = atoi(optarg);
                   break;
               default: /* '?' */
                   fprintf(stderr, "Usage: %s [-p nbpopulation] [-P nbparents] \n",argv[0]);
                   exit(EXIT_FAILURE);
               }
        }
	// test et allocation mémoire.
	if (parents.nombre > population.nombre) exit(EXIT_FAILURE);

	if ((population.membres=malloc(sizeof(serpent)*population.nombre)) == NULL ) exit(EXIT_FAILURE);
	if ((parents.membres=malloc(sizeof(serpent)*parents.nombre)) == NULL ) exit(EXIT_FAILURE);

	// creation de la premiere génération
	generationAleatoire(&population);

	while (evaluation(&population)) {
		selection(&population,&parents);
		reproduction(&population,&parents);
		mutation(&population);
		nbgeneration++;
	}
	printf("Generation %d\n",nbgeneration);
	free(population.membres);
	free(parents.membres);

}
