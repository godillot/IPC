/* 
 * File:   serveur.c
 * Author: kauve
 *
 * Created on 14 septembre 2018, 10:12
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
int main(int argc, char** argv) {
    
 int socketServeur;
  struct sockaddr_in infosClient;
    struct sockaddr_in infosServeur;
 
    int entierRecu;
    int retour;
    int retourBind;
    
    //CREATION DE LA SOCKET UDP
socketServeur = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
if(socketServeur==-1){
    printf("pb socket : %s \n", strerror(errno));
    exit(errno);
}

    //INIT DES INFOMATIONS SERVEURS
/**/
infosServeur.sin_addr.s_addr=inet_addr(INADDR_ANY);
infosServeur.sin_family=AF_INET;
infosServeur.sin_port=htons(2222);


    //ENVOYER L'ENTIER AU SERVEUR
retourBind = bind( socketServeur, (struct sockaddr *)&infosServeur, sizeof(infosServeur));

retour =recvfrom(socketServeur, &entierRecu,sizeof(entierRecu), 0, (struct sockaddr *)&infosServeur,sizeof(infosServeur));

 if(retour==-1){
    printf("pb de réception : %s \n", strerror(errno));
    exit(errno);
}

retour = sendto(socketServeur,&entierRecu,sizeof(entierRecu),0,(struct sockaddr *)&infosClient,sizeof(infosClient));
 
   if(retour==-1){
    printf("pb sendto : %s \n", strerror(errno));
    exit(errno);
} 

    
   close(socketServeur);
    
    
    
    
    return (EXIT_SUCCESS);
}

