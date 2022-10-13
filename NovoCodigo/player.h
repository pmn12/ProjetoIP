#ifndef PLAYER
#define PLAYER

#include "menu.h"
#include "raylib.h"
#include "stdlib.h"
#include "stdio.h"
#include "player.h"

typedef struct{
    Vector2 posicao;
    Rectangle rec;
    Rectangle recRun;
    Rectangle hitbox;
    Rectangle recAtac;
    float frame_width;
    float timer;
    int frame;
    int max_frames;
    int max_vida;
    int vida_atual;
    bool ativo;
} Personagem;

void initPerso(Personagem *perso, int screenWidth, int screenHeight, float frameWidthIdle, float frameHeightIdle, float frameWidthRun, float frameHeightRun, float frameWidthAtac, float frameHeightAtac) {
    perso -> posicao.x = screenWidth/2;
    perso -> posicao.y = screenHeight/2;
    perso -> rec.x = 0;
    perso -> rec.y = 0;
    perso -> rec.width = frameWidthIdle;
    perso -> rec.height = frameHeightIdle;
    perso -> recRun.x = 0;
    perso -> recRun.y = 0;
    perso -> recRun.width = frameWidthRun;
    perso -> recRun.height = frameHeightRun;
    perso -> hitbox.width = frameWidthRun / 4;
    perso -> hitbox.height = frameHeightRun / 4;
    perso -> recAtac.x = 0;
    perso -> recAtac.y = 0;
    perso -> recAtac.width = frameWidthAtac;
    perso -> recAtac.height = frameHeightAtac;
}

void verificaColisao(int *andando, Rectangle *rec_map, Personagem perso, int posicao) {
    
    if(CheckCollisionRecs(rec_map[0], perso.hitbox) == true) {
        if(posicao == 0) *andando = 0;
    }
    if(CheckCollisionRecs(rec_map[1], perso.hitbox) == true) {
        if(posicao == 1) *andando = 0;
    }
    if(CheckCollisionRecs(rec_map[2], perso.hitbox) == true) {
        if(posicao == 3) *andando = 0;
    }
    if(CheckCollisionRecs(rec_map[3], perso.hitbox) == true) {
        if(posicao == 2) *andando = 0;
    }
    if(CheckCollisionRecs(rec_map[4], perso.hitbox) == true) {
        if(posicao == 3) *andando = 0;
    }
    if(CheckCollisionRecs(rec_map[5], perso.hitbox) == true) {
        if(posicao == 1) *andando = 0;
    }

}

void updatePerso(Personagem *perso, int screenWidth, int screenHeight, float frameWidthIdle, float frameHeightIdle, float frameWidthRun, float frameHeightRun, float frameHeightAtac, float frameWidthAtac, int *frame, int *frameIdle, int *frameAtac, float *time, int *x, int *y, Rectangle *rec_map, int *andando, int *i) {
    int xaux, yaux, posicao = 0;
        xaux = *x;
        yaux = *y;
        perso -> posicao.x = screenWidth/2 + *x;
        perso -> posicao.y = screenHeight/2 + *y;
        perso -> hitbox.x = (screenWidth / 2 + frameWidthRun / 4 + frameWidthRun / 8) + *x;
        perso -> hitbox.y = (screenHeight / 2 + frameHeightRun / 4 + frameWidthRun / 8) + *y;

        //Inverter a posição da animação da direita para esquerda
        if(*i == 1) {
            perso -> rec.width = frameWidthIdle;
            perso -> recRun.width = frameWidthRun;
            perso -> recAtac.width = frameWidthAtac;
        }
        else {
            perso -> rec.width = -frameWidthIdle;
            perso -> recRun.width = -frameWidthRun;
            perso -> recAtac.width = -frameWidthAtac;
        }
        perso -> rec.x = (*frameIdle) * frameWidthIdle;
        perso -> recRun.x = (*frame) * frameWidthRun;
        perso -> recAtac.x = (*frameAtac) * frameWidthAtac;

        if(IsKeyDown(KEY_A) == true) {
            xaux = xaux - 4;
            *andando = 1;
            posicao = 1;
            *i = -1;
            verificaColisao(andando, rec_map, *perso, posicao);
            
            if(*andando == 1) *x = xaux;
        }
        else if(IsKeyDown(KEY_D) == true) {
            xaux = xaux + 4;
            *andando = 1;
            posicao = 2;
            *i = 1;
            verificaColisao(andando, rec_map, *perso, posicao);
            
            if(*andando == 1) *x = xaux;
        }
        else if(IsKeyDown(KEY_W) == true) {
            yaux = yaux - 4;
            *andando = 1;
            posicao = 3;
            verificaColisao(andando, rec_map, *perso, posicao);
            
            if(*andando == 1) *y = yaux;

        }
        else if(IsKeyDown(KEY_S) == true) {
            yaux = yaux + 4;
            *andando = 1;
            posicao = 0;
            verificaColisao(andando, rec_map, *perso, posicao);
            
            if(*andando == 1) *y = yaux;
        }
        else *andando = 0;

        
        if(IsKeyDown(KEY_Z)){

            *time += GetFrameTime();
            if(*time >= 0.1f) {
                (*frameAtac)++;
                *time = 0.0f;
            }
            *frameAtac = *frameAtac % 7;
         } 

        else if(*andando == 1) {
            *time += GetFrameTime();
            if(*time >= 0.1f) {
                (*frame)++;
                *time = 0.0f;
            }
            *frame = *frame % 8;
            *frameIdle = 0;
            *frameAtac = 0;
        }
        
        else if(*andando == 0){
            *frame = 0;
            *frameAtac = 0;

            *time += GetFrameTime();
            if(*time >= 0.1f) {
                (*frameIdle)++;
                *time = 0.0f;
            }
            *frameIdle = *frameIdle % 10;
         }  

      
      if(*i == 1) {
            perso->rec.width = frameWidthIdle;
            perso->recRun.width = frameWidthRun;
        }
        else {
            perso->rec.width = -frameWidthIdle;
            perso->recRun.width = -frameWidthRun;
        }
}

void initCamera(Camera2D *camera) {
    camera -> offset.x = 0;
    camera -> offset.y = 0; 
    camera -> rotation = 0.0f;
    camera -> zoom = 1.5;
}

void updateCamera(Camera2D *camera, Personagem *perso, int screenWidth, int screenHeight, Texture2D mapa) {
    if(perso -> posicao.x -(screenWidth /2) /2 <= (screenWidth /2 - mapa.width /2)) {
        camera -> target.x = (screenWidth /2 - mapa.width /2);
                     
    }
    else if(perso -> posicao.x -(screenWidth /2) /2 >= mapa.width /2 - ((screenWidth / 2) / 1.5) / 2 ) {
        camera -> target.x = mapa.width /2 - ((screenWidth / 2) / 1.5) /2 ;
                
    }
    else {
        camera -> target.x = perso -> posicao.x - (screenWidth /2) / 2;
    }
            
    if(perso -> posicao.y - (screenHeight / 2) / 2 <=(screenHeight /2 - mapa.height /2) + ((screenHeight / 2) / 1.5) / 8 ) {
        camera -> target.y = (screenHeight /2 - mapa.height /2) + ((screenHeight / 2) / 1.5) / 8;
    }
    else if(perso -> posicao.y - (screenHeight / 2) /2 >= mapa.height /2 - ((screenHeight / 2) / 1.5) / 2) {
        camera -> target.y = mapa.height /2 - ((screenHeight / 2) / 1.5) / 2;
    }
    else {
        camera -> target.y = perso -> posicao.y - (screenHeight /2) / 2;
    }
}

void ataquePersonagem(Personagem perso){
    
    if(IsKeyDown(KEY_Z)){

    }


}
#endif