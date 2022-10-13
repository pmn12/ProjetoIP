#ifndef MAPA
#define MAPA

#include "raylib.h"
#include "stdio.h"
#include "stdlib.h"
#include "player.h"

void desenharPerso(Texture2D persoIdle, Texture2D persoRun, Texture2D persoAtac, Personagem perso, int andando) {


    if(IsKeyDown(KEY_Z)){
        DrawTextureRec(persoAtac, perso.recAtac, perso.posicao, RAYWHITE);
    }

    else if(andando == 0) 
        DrawTextureRec(persoIdle, perso.rec, perso.posicao, RAYWHITE);
    
    else if(andando == 1)
        DrawTextureRec(persoRun, perso.recRun, perso.posicao, RAYWHITE);
    
    
}

void carregarRetangulos(Rectangle *rec_map,int screenWidth, int screenHeight, Texture2D mapa) {
    
    rec_map[0].x = (screenWidth / 2 - mapa.width /2) + 17;
    rec_map[0].y = (screenHeight /2 - mapa.height / 2) + 655;
    rec_map[0].width = 1781;
    rec_map[0].height = 10;

    rec_map[1].x = (screenWidth / 2 - mapa.width /2) + 3;
    rec_map[1].y = (screenHeight /2 - mapa.height / 2) + 180;
    rec_map[1].width = 20;
    rec_map[1].height = 500;

     rec_map[2].x = (screenWidth / 2 - mapa.width /2) + 17;
    rec_map[2].y = (screenHeight /2 - mapa.height / 2) + 150;
    rec_map[2].width = 1781;
    rec_map[2].height = 10;

    rec_map[3].x = (screenWidth / 2 - mapa.width /2) + 1791;
    rec_map[3].y = (screenHeight /2 - mapa.height / 2) + 170;
    rec_map[3].width = 10;
    rec_map[3].height = 500;

    rec_map[4].x = (screenWidth / 2 - mapa.width /2) + 17;
    rec_map[4].y = (screenHeight /2 - mapa.height / 2) + 203;
    rec_map[4].width = 63;
    rec_map[4].height = 12;

    rec_map[5].x = (screenWidth / 2 - mapa.width /2) + 80;
    rec_map[5].y = (screenHeight /2 - mapa.height / 2) + 150;
    rec_map[5].width = 12;
    rec_map[5].height = 53;  
}

#endif 