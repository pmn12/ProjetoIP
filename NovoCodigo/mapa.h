#ifndef MAPA
#define MAPA

#include "raylib.h"
#include "stdio.h"
#include "stdlib.h"
#include "player.h"
#include "inimigo.h"

void desenharPerso(Texture2D persoIdle, Texture2D persoRun, Personagem *perso, int andando, int *attacking, float FWattack, float *timeAttack, int *attackMode, Texture2D Attack0, Texture2D Attack1, Texture2D Attack2, float FHattack, int *frameAttack) {
    if(*attacking == 0) {
        if(andando == 0) {
            DrawTextureRec(persoIdle, perso -> rec, perso -> posicao, RAYWHITE);
        }
        else {
            DrawTextureRec(persoRun, perso -> recRun, perso -> posicao, RAYWHITE);
        }

    }
    else {
        perso -> recAttack.x = (*frameAttack) * FWattack;
        perso -> recAttack.y = FHattack;

        if(*attackMode == 0) {
            
            DrawTextureRec(Attack0, perso -> recAttack, perso -> posicao, RAYWHITE);
        
            *timeAttack += GetFrameTime();
            if(*timeAttack >= 0.05f) {
                (*frameAttack) += 1;
                *timeAttack = 0.0f;
                    
            }
            
            if(*frameAttack == 7) {
                *attacking = 0;
                *frameAttack = 0;
                *attackMode = 1;
            }
        }
        else if(*attackMode == 1) {
            DrawTextureRec(Attack1, perso -> recAttack, perso -> posicao, RAYWHITE);
        
            *timeAttack += GetFrameTime();
            if(*timeAttack >= 0.05f) {
                (*frameAttack) += 1;
                *timeAttack = 0.0f;
                    
            }
            
            if(*frameAttack == 7) {
                *attacking = 0;
                *frameAttack = 0;
                *attackMode = 2;
            }
        }
        else {
            DrawTextureRec(Attack2, perso -> recAttack, perso -> posicao, RAYWHITE);
        
            *timeAttack += GetFrameTime();
            if(*timeAttack >= 0.05f) {
                (*frameAttack) += 1;
                *timeAttack = 0.0f;
                    
            }
            
            if(*frameAttack == 7) {
                *attacking = 0;
                *frameAttack = 0;
                *attackMode = 0;
            }
        }
    }
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

void desenharMapa(Personagem perso, Rectangle* inimigo, Vector2* inimig, Texture2D mapa, Texture2D barravida, Texture2D texture7, int andando, int i){

    const int screenWidth = 1600;
    const int screenHeight = 800;

    inimigo->x = 500;
    inimigo->y = 500;
    inimigo->width = 100;
    inimigo->height = 100;
    inimig->x = 500;
    inimig->y = 500;

    DrawTexture(mapa, screenWidth / 2 - mapa.width /2 ,screenHeight / 2 - mapa.height/2 , RAYWHITE);
    //DrawTexture(barravida ,perso.posicao.x - 350, perso.posicao.y - 180 , RAYWHITE);
    DrawTextureRec(texture7, *inimigo, *inimig, RAYWHITE);
    //VOU MUDAR PARA OUTRA FUNÇÃO ESTA PARTE DE BAIXO
    if(IsKeyPressed(KEY_Z)){
        if(i == 1)
            DrawRectangle(perso.posicao.x + 100, perso.posicao.y + 60, perso.hitbox.width, perso.hitbox.height, RED);
        else{
        DrawRectangle(perso.posicao.x + 20, perso.posicao.y + 60, perso.hitbox.width, perso.hitbox.height, RED);
        inimigoAcertado(perso, *inimigo, i);
        }

}
}


#endif 