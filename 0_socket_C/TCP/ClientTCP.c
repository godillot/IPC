/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClientTCP.c
 * Author: kauve
 *
 * Created on 18 septembre 2018, 08:11
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

/*
 * 
 */
/*
typedef struct{
	unsigned char jour;
	unsigned char mois;
	unsigned short int annee;
	char jourDeLaSemaine[10];	// le jour en toute lettre
}datePerso;*/

int main(int argc, char** argv) {

     int socketClient;

    struct sockaddr_in infosServeur;
    //1
    int entierAEnvoyer=56;
     int entierRecu;
     //2
    float reelAEnvoyer=66.6;
    float reelRecu;
    
    int retour;
    int retourBind;
    
    //POUR LA DATE
  /*   datePerso date;
    date.annee=1998;
    date.mois=12;
    date.jour=11;*/
    
    //CREATION DE LA SOCKET TCP
socketClient = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
if(socketClient==-1){
    printf("pb socket : %s \n", strerror(errno));
    exit(errno);
}

 //INIT DES INFOMATIONS SERVEURS

infosServeur.sin_addr.s_addr=inet_addr("172.18.58.75");
infosServeur.sin_family=AF_INET;
infosServeur.sin_port=htons(2222/*5555*//*6666*//*7777*/);


//CONNEXION 
connect( socketClient,(struct sockaddr *)&infosServeur,sizeof(infosServeur));

//WRITE
retour = write(socketClient, &entierAEnvoyer/*reelAEnvoyer*//*date*/, sizeof(entierAEnvoyer/*reelAEnvoyer*//*date*/));

if(retour==-1){
    printf("pb write : %s \n", strerror(errno));
    exit(errno);
}
//READ
retour = read(socketClient, &entierRecu/*reelRecu*/, sizeof(entierRecu/*reelRecu*/));

if(retour==-1){
    printf("pb read : %s \n", strerror(errno));
    exit(errno);
}

close(socketClient);
    
    return (EXIT_SUCCESS);
}

