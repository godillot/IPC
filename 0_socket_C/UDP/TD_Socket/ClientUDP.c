/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: kauve
 *
 * Created on September 12, 2018, 8:33 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
/*
 * 
 */
typedef struct{
	unsigned char jour;
	unsigned char mois;
	unsigned short int annee;
	char jourDeLaSemaine[10];	// le jour en toute lettre
}datePerso;

int main(int argc, char** argv) {
    
    int socketClient;
    struct sockaddr_in infosServeur;
   /* float entierAEnvoyer=12.0;
    float entierRecu;*/
    int retour;
    datePerso d;
    d.annee=1998;
    d.mois=12;
    d.jour=11;
    strcpy(d.jourDeLaSemaine,"Lundi");
    //CREATION DE LA SOCKET UDP
socketClient = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
if(socketClient==-1){
    printf("pb socket : %s \n", strerror(errno));
    exit(errno);
}
    //INIT DES INFOMATIONS SERVEURS

infosServeur.sin_addr.s_addr=inet_addr("172.18.58.83");
infosServeur.sin_family=AF_INET;
infosServeur.sin_port=htons(4444);


    //ENVOYER L'ENTIER AU SERVEUR
   retour = sendto(socketClient,/*&entierAEnvoyer*/&d,sizeof(/*entierAEnvoyer*/d),0,(struct sockaddr *)&infosServeur,sizeof(infosServeur));
 
   if(retour==-1){
    printf("pb sendto : %s \n", strerror(errno));
    exit(errno);
}
    //RECEVOIR L'ENTIER DU SERVEUR
//recvfrom(socketClient, &entierRecu,sizeof(entierRecu), 0, (struct sockaddr *)&infosServeur,sizeof(infosServeur));
    //AFFICHER L'ENTIER DU SERVEUR

   //printf("Recu du serveur: %d \n", entierRecu);
    
   
    
    
    
    
    
    
    return (EXIT_SUCCESS);
}


