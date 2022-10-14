#ifndef INIMIGO
#define INIMIGO

#include "raylib.h"
#include "stdio.h"
#include "stdlib.h"
#include "player.h"
#include "inimigo.h"

typedef struct {
    
    Rectangle hitbox_inimigo;
    float vida_inimigo;
    bool ativo;

}Enemy;

Enemy* initVilao(Enemy* Recvilao){

    Recvilao[0].vida_inimigo = 30;
    Recvilao[1].vida_inimigo = 30;
    Recvilao[2].vida_inimigo = 30;
    Recvilao[3].vida_inimigo = 30;
    Recvilao[4].vida_inimigo = 30;
    Recvilao[5].vida_inimigo = 30;

    Recvilao[3].hitbox_inimigo.x = 530; Recvilao[3].hitbox_inimigo.y = -160; Recvilao[3].hitbox_inimigo.width = 150; Recvilao[3].hitbox_inimigo.height = 150;
    Recvilao[1].hitbox_inimigo.x = -570; Recvilao[1].hitbox_inimigo.y = 220; Recvilao[1].hitbox_inimigo.width = 150; Recvilao[1].hitbox_inimigo.height = 150;
    Recvilao[2].hitbox_inimigo.x = 1700; Recvilao[2].hitbox_inimigo.y = 220; Recvilao[2].hitbox_inimigo.width = 150; Recvilao[2].hitbox_inimigo.height = 150;
    Recvilao[0].hitbox_inimigo.x = 530; Recvilao[0].hitbox_inimigo.y = -160; Recvilao[0].hitbox_inimigo.width = 100; Recvilao[0].hitbox_inimigo.height = 100;
    Recvilao[4].hitbox_inimigo.x = -570; Recvilao[4].hitbox_inimigo.y = 220; Recvilao[4].hitbox_inimigo.width = 100; Recvilao[4].hitbox_inimigo.height = 100;
    Recvilao[5].hitbox_inimigo.x = 1700; Recvilao[5].hitbox_inimigo.y = 220; Recvilao[5].hitbox_inimigo.width = 100; Recvilao[5].hitbox_inimigo.height = 100;

     for(int j = 0; j < 6; j++){
        Recvilao[j].ativo = 1;
     }

    return Recvilao;
}
Enemy* inimigoAcertado(Personagem perso, Enemy* inimigo, int i){
    
    if(i == -1){
        perso.hitbox_ataque.x = perso.posicao.x + 20;
        perso.hitbox_ataque.y = perso.posicao.y + 60;
    }

     else{
        perso.hitbox_ataque.x = perso.posicao.x + 100;
        perso.hitbox_ataque.y = perso.posicao.y + 60;
    }

    perso.hitbox_ataque.height = perso.hitbox.height;
   perso.hitbox_ataque.width = perso.hitbox.width;

    for(int j = 0; j < 6; j++){

    if(CheckCollisionRecs(perso.hitbox_ataque, inimigo[j].hitbox_inimigo) && IsKeyPressed(KEY_Z)){
        DrawText("HIT!", perso.posicao.x + 50, perso.posicao.y - 25, 20, RED);
        inimigo[j].vida_inimigo -= 10;

        if(inimigo[j].vida_inimigo <= 0){
            
            if(j == 3){
            inimigo[3].vida_inimigo = 60;
            inimigo[3].hitbox_inimigo.x = 530; inimigo[3].hitbox_inimigo.y = -160; inimigo[3].hitbox_inimigo.width = 150; inimigo[3].hitbox_inimigo.height = 150;
            }
            else if(j == 1){
             inimigo[1].vida_inimigo = 30;
             inimigo[1].hitbox_inimigo.x = -570; inimigo[1].hitbox_inimigo.y = 220; inimigo[1].hitbox_inimigo.width = 150; inimigo[1].hitbox_inimigo.height = 150;
            }
            else if(j == 2){
            inimigo[2].vida_inimigo = 30;
            inimigo[2].hitbox_inimigo.x = 1700; inimigo[2].hitbox_inimigo.y = 220; inimigo[2].hitbox_inimigo.width = 150; inimigo[2].hitbox_inimigo.height = 150;
            }
            else if(j == 0){
            inimigo[0].vida_inimigo = 30;
            inimigo[0].hitbox_inimigo.x = 530; inimigo[0].hitbox_inimigo.y = -160; inimigo[0].hitbox_inimigo.width = 100; inimigo[0].hitbox_inimigo.height = 100;
            }
            else if(j == 4){
            inimigo[4].vida_inimigo = 60;
            inimigo[4].hitbox_inimigo.x = -570; inimigo[4].hitbox_inimigo.y = 220; inimigo[4].hitbox_inimigo.width = 100; inimigo[4].hitbox_inimigo.height = 100;
            }
            else if(j == 5){
            inimigo[5].vida_inimigo = 60;
            inimigo[5].hitbox_inimigo.x = 1700; inimigo[5].hitbox_inimigo.y = 220; inimigo[5].hitbox_inimigo.width = 100; inimigo[5].hitbox_inimigo.height = 100;
            }
        }
    }
    }
    return inimigo;
}

void personagemAcertado(Personagem* perso, Enemy* inimigo, int *morreu, Sound *Tema){

    for(int j = 0; j < 6; j++){
    if(CheckCollisionRecs(perso->hitbox, inimigo[j].hitbox_inimigo))
        perso->vida_atual = (float)(perso->vida_atual) - 0.3;
    
    }

    DrawRectangle(perso->posicao.x + 48, perso->posicao.y + 26, perso->vida_atual , 13 , RED);
    if(perso->vida_atual <= 0){
        abrirGameOver(&morreu, &Tema);
        perso->ativo = 0;
    }
}

void movimentarvilao(Rectangle personagem, Enemy *vilao, int time, Rectangle torre){
    
    if(time >3){
        if(CheckCollisionRecs(personagem, vilao[3].hitbox_inimigo)==0){
            if(personagem.x < vilao[3].hitbox_inimigo.x)
                vilao[3].hitbox_inimigo.x -= 0.5f;
            if(personagem.x > vilao[3].hitbox_inimigo.x)
                vilao[3].hitbox_inimigo.x += 0.5f;
            if(personagem.y < vilao[3].hitbox_inimigo.y)
                vilao[3].hitbox_inimigo.y -= 0.5f;
            if(personagem.y > vilao[3].hitbox_inimigo.y)
                vilao[3].hitbox_inimigo.y += 0.5f;
        }
    
            if(torre.x + torre.width < vilao[0].hitbox_inimigo.x)
                vilao[0].hitbox_inimigo.x -= 1.0f;
            if(torre.x > vilao[0].hitbox_inimigo.x + vilao[0].hitbox_inimigo.width)
                vilao[0].hitbox_inimigo.x += 1.0f;
            if(torre.y + torre.height < vilao[0].hitbox_inimigo.y)
                vilao[0].hitbox_inimigo.y -= 1.0f;
            if(torre.y > vilao[0].hitbox_inimigo.y + vilao[0].hitbox_inimigo.height)
                vilao[0].hitbox_inimigo.y += 1.0f;
            
    }
    if(time >15){ 
        if(CheckCollisionRecs(personagem,vilao[1].hitbox_inimigo)==0){
            if(personagem.x <vilao[1].hitbox_inimigo.x)
               vilao[1].hitbox_inimigo.x -= 1.0f;
            if(personagem.x >vilao[1].hitbox_inimigo.x)
               vilao[1].hitbox_inimigo.x += 1.0f;
            if(personagem.y <vilao[1].hitbox_inimigo.y)
               vilao[1].hitbox_inimigo.y -= 1.0f;
            if(personagem.y >vilao[1].hitbox_inimigo.y)
               vilao[1].hitbox_inimigo.y += 1.0f;
        }    

            if(torre.x + torre.width < vilao[4].hitbox_inimigo.x)
                vilao[4].hitbox_inimigo.x -= 1.0f;
            if(torre.x > vilao[4].hitbox_inimigo.x + vilao[4].hitbox_inimigo.width)
                vilao[4].hitbox_inimigo.x += 1.0f;
            if(torre.y + torre.height < vilao[4].hitbox_inimigo.y)
                vilao[4].hitbox_inimigo.y -= 1.0f;
            if(torre.y > vilao[4].hitbox_inimigo.y + vilao[4].hitbox_inimigo.height)
                vilao[4].hitbox_inimigo.y += 1.0f;
            
    }
    if(time >25){
        if(CheckCollisionRecs(personagem, vilao[2].hitbox_inimigo)==0){
            if(personagem.x < vilao[2].hitbox_inimigo.x)
                vilao[2].hitbox_inimigo.x -= 0.8f;
            if(personagem.x > vilao[2].hitbox_inimigo.x)
                vilao[2].hitbox_inimigo.x += 0.8f;
            if(personagem.y < vilao[2].hitbox_inimigo.y)
                vilao[2].hitbox_inimigo.y -= 0.8f;
            if(personagem.y > vilao[2].hitbox_inimigo.y)
                vilao[2].hitbox_inimigo.y += 0.8f;
        }  

            if(torre.x + torre.width < vilao[5].hitbox_inimigo.x)
                vilao[5].hitbox_inimigo.x -= 1.0f;
            if(torre.x > vilao[5].hitbox_inimigo.x + vilao[5].hitbox_inimigo.width)
                vilao[5].hitbox_inimigo.x += 1.0f;
            if(torre.y + torre.height < vilao[5].hitbox_inimigo.y)
                vilao[5].hitbox_inimigo.y -= 1.0f;
            if(torre.y > vilao[5].hitbox_inimigo.y + vilao[5].hitbox_inimigo.height)
                vilao[5].hitbox_inimigo.y += 1.0f;
            
    }
}

#endif 