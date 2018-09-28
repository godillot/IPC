/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServeurTCP.c
 * Author: kauve
 *
 * Created on 18 septembre 2018, 08:59
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

    int tailleClient;
    int entierRecu;
    int retourListen;
    int retourRead;
    int retourWrite;
    int retourBind;
    int retourAccept;
    int retour = 1;
    
    float reelRecu;


    //CREATION DE LA SOCKET TCP
    socketServeur = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    if (socketServeur == -1) {
        printf("pb socket : %s \n", strerror(errno));
        exit(errno);
    }

    //INIT DES INFOMATIONS SERVEURS
    /**/
    infosServeur.sin_addr.s_addr = htonl(INADDR_ANY);
    infosServeur.sin_family = AF_INET;
    infosServeur.sin_port = htons(5555);

    tailleClient = sizeof (infosClient);

    //ENVOYER L'ENTIER AU SERVEUR
    retourBind = bind(socketServeur, (struct sockaddr *) &infosServeur, sizeof (infosServeur));

    if (retourBind == -1) {
        printf("pb bind : %s\n", strerror(errno));
        exit(errno);
    }
/////////////////////////
    
        retourListen = listen(socketServeur, 10);

        if (retourListen == -1) {
            printf("pb listen : %s\n", strerror(errno));
            exit(errno);
        }
////////////////////////
        retourAccept = accept(socketServeur, (struct sockaddr *) &infosClient, &tailleClient);

        if (retourAccept == -1) {
            printf("pb accept : %s\n", strerror(errno));
            exit(errno);
        }
        
////////////////////////        
        retourRead = read(retourAccept, &/*entierRecu*/reelRecu, sizeof (/*entierRecu*/reelRecu));

        if (retourRead == -1) {
            printf("pb read : %s\n", strerror(errno));
            exit(errno);
        }
 printf("message client %s : %i\n", inet_ntoa(infosClient.sin_addr), entierRecu);
////////////////////////
        retourWrite = write(retourAccept, &/*entierRecu*/reelRecu, sizeof (/*entierRecu*/reelRecu));

        if (retourWrite == -1) {
            printf("pb write : %s\n", strerror(errno));
            exit(errno);
        }
        close(socketServeur);

          return (EXIT_SUCCESS);
    }
