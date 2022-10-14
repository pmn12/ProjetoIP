#ifndef INIMIGO
#define INIMIGO

#include "raylib.h"
#include "stdio.h"
#include "stdlib.h"
#include "player.h"
#include "inimigo.h"
#include "cristal.h"

typedef struct {
    
    Rectangle hitbox_inimigo;
    float vida_inimigo;
    bool ativo;

}Enemy;

Enemy* initVilao(Enemy* Recvilao, Texture2D mapa){

    const int screenWidth = 1600;
    const int screenHeight = 800;

    Recvilao[0].vida_inimigo = 60;
    Recvilao[1].vida_inimigo = 30;
    Recvilao[2].vida_inimigo = 30;
    Recvilao[3].vida_inimigo = 30;
    Recvilao[4].vida_inimigo = 60;
    Recvilao[5].vida_inimigo = 60;
    Recvilao[6].vida_inimigo = 1000;

    Recvilao[3].hitbox_inimigo.x = 530; Recvilao[3].hitbox_inimigo.y = -160; Recvilao[3].hitbox_inimigo.width = 150; Recvilao[3].hitbox_inimigo.height = 150;
    Recvilao[1].hitbox_inimigo.x = -570; Recvilao[1].hitbox_inimigo.y = 220; Recvilao[1].hitbox_inimigo.width = 150; Recvilao[1].hitbox_inimigo.height = 150;
    Recvilao[2].hitbox_inimigo.x = 1700; Recvilao[2].hitbox_inimigo.y = 220; Recvilao[2].hitbox_inimigo.width = 150; Recvilao[2].hitbox_inimigo.height = 150;
    Recvilao[0].hitbox_inimigo.x = (screenWidth / 2 - mapa.width /2) + 1791; Recvilao[0].hitbox_inimigo.y = 340 ; Recvilao[0].hitbox_inimigo.width = 100; Recvilao[0].hitbox_inimigo.height = 100;
    Recvilao[4].hitbox_inimigo.x = (screenWidth / 2 - mapa.width /2) + 1791; Recvilao[4].hitbox_inimigo.y = 340; Recvilao[4].hitbox_inimigo.width = 100; Recvilao[4].hitbox_inimigo.height = 100;
    Recvilao[5].hitbox_inimigo.x = (screenWidth / 2 - mapa.width /2) + 1791; Recvilao[5].hitbox_inimigo.y = 340; Recvilao[5].hitbox_inimigo.width = 100; Recvilao[5].hitbox_inimigo.height = 100;
    Recvilao[6].hitbox_inimigo.x = 750; Recvilao[6].hitbox_inimigo.y = 340; Recvilao[6].hitbox_inimigo.width = 100; Recvilao[6].hitbox_inimigo.height = 120;

     for(int j = 0; j < 7; j++){
        Recvilao[j].ativo = 1;
     }

    return Recvilao;
}
Enemy* inimigoAcertado(Personagem perso, Enemy* inimigo, int i, int* morreu, Sound* tema, Sound* efeitos){
    
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

    for(int k = 0; k < 7; k++){
        if(k <= 5)
        DrawRectangle(inimigo[k].hitbox_inimigo.x + 30, inimigo[k].hitbox_inimigo.y - 10, inimigo[k].vida_inimigo * 2 , 13 , RED);
        else
        DrawRectangle(inimigo[k].hitbox_inimigo.x - 16, inimigo[k].hitbox_inimigo.y - 10, inimigo[k].vida_inimigo / 10 , 13 , PURPLE);
    }

    for(int j = 0; j < 6; j++){
    
    if(CheckCollisionRecs(perso.hitbox_ataque, inimigo[j].hitbox_inimigo) && IsKeyPressed(KEY_Z)){
        DrawText("HIT!", perso.posicao.x + 50, perso.posicao.y - 25, 20, RED);
        inimigo[j].vida_inimigo -= 10;
        PlaySound(efeitos[3]);

        if(inimigo[j].vida_inimigo <= 0){
            
            if(j == 3){
            inimigo[3].vida_inimigo = 30;
            inimigo[3].hitbox_inimigo.x = 530; inimigo[3].hitbox_inimigo.y = 0; inimigo[3].hitbox_inimigo.width = 150; inimigo[3].hitbox_inimigo.height = 150;
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
            inimigo[0].vida_inimigo = 60;
            inimigo[0].hitbox_inimigo.x = 530; inimigo[0].hitbox_inimigo.y = 0; inimigo[0].hitbox_inimigo.width = 100; inimigo[0].hitbox_inimigo.height = 100;
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

        if(CheckCollisionRecs(inimigo[6].hitbox_inimigo, inimigo[0].hitbox_inimigo)){
            inimigo[6].vida_inimigo -= 0.3;
            DrawText("Acertou!", inimigo[6].hitbox_inimigo.x, inimigo[6].hitbox_inimigo.y, 40, RED);
        }
        if(CheckCollisionRecs(inimigo[6].hitbox_inimigo, inimigo[4].hitbox_inimigo)){
            inimigo[6].vida_inimigo -= 0.3;
            DrawText("Acertou!", inimigo[6].hitbox_inimigo.x, inimigo[6].hitbox_inimigo.y, 40, RED);
        }
        if(CheckCollisionRecs(inimigo[6].hitbox_inimigo, inimigo[5].hitbox_inimigo)){
            inimigo[6].vida_inimigo -= 0.3;
            DrawText("Acertou!", inimigo[6].hitbox_inimigo.x, inimigo[6].hitbox_inimigo.y, 40, RED);
        }

        if(inimigo[6].vida_inimigo <= 0){
            abrirGameOver(&morreu, &tema);
        }
    }
    return inimigo;
}

void personagemAcertado(Personagem* perso, Enemy* inimigo, int *morreu, Sound *Tema, Cristal* cristal){

    for(int j = 0; j < 6; j++){
    if(CheckCollisionRecs(perso->hitbox, inimigo[j].hitbox_inimigo))
        perso->vida_atual = (float)(perso->vida_atual) - 0.3;
    
    }

    DrawRectangle(perso->posicao.x + 48, perso->posicao.y + 26, perso->vida_atual , 13 , GREEN);
    if(perso->vida_atual <= 0){
        abrirGameOver(&morreu, &Tema);
        perso->ativo = 0;
    }
    
    for(int i=0;i<2;i++){
        if(CheckCollisionRecs(perso->hitbox, cristal[i].hitbox_cristal) &&  cristal[i].ativo_cristal == 1 && perso->max_vida > perso->vida_atual){
            perso->vida_atual = (float)(perso->vida_atual) + 0.3;
            cristal[i].vida_cristal = (float)(cristal[i].vida_cristal) - 0.3;
        }
        if(cristal[i].vida_cristal <=0){
            cristal[i].ativo_cristal = 0;
        }
    }
    for(int k=0;k<2;k++){
    DrawRectangle(cristal[k].hitbox_cristal.x + 26, cristal[k].hitbox_cristal.y + 26, cristal[k].vida_cristal , 13 , YELLOW);
    }
}

void movimentarvilao(Rectangle personagem, Enemy *vilao, int time){
    
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
    
            if(vilao[6].hitbox_inimigo.x + vilao[6].hitbox_inimigo.width <= vilao[0].hitbox_inimigo.x)
                vilao[0].hitbox_inimigo.x -= 1.0f;
            if(vilao[6].hitbox_inimigo.x >= vilao[0].hitbox_inimigo.x + vilao[0].hitbox_inimigo.width)
                vilao[0].hitbox_inimigo.x += 1.0f;
            if(vilao[6].hitbox_inimigo.y + vilao[6].hitbox_inimigo.height <= vilao[0].hitbox_inimigo.y)
                vilao[0].hitbox_inimigo.y -= 1.0f;
            if(vilao[6].hitbox_inimigo.y >= vilao[0].hitbox_inimigo.y + vilao[0].hitbox_inimigo.height)
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

            if(vilao[6].hitbox_inimigo.x + vilao[6].hitbox_inimigo.width <= vilao[4].hitbox_inimigo.x)
                vilao[4].hitbox_inimigo.x -= 1.0f;
            if(vilao[6].hitbox_inimigo.x >= vilao[4].hitbox_inimigo.x + vilao[4].hitbox_inimigo.width)
                vilao[4].hitbox_inimigo.x += 1.0f;
            if(vilao[6].hitbox_inimigo.y + vilao[6].hitbox_inimigo.height <= vilao[4].hitbox_inimigo.y)
                vilao[4].hitbox_inimigo.y -= 1.0f;
            if(vilao[6].hitbox_inimigo.y >= vilao[4].hitbox_inimigo.y + vilao[4].hitbox_inimigo.height)
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

            if(vilao[6].hitbox_inimigo.x + vilao[6].hitbox_inimigo.width <= vilao[5].hitbox_inimigo.x)
                vilao[5].hitbox_inimigo.x -= 1.0f;
            if(vilao[6].hitbox_inimigo.x >= vilao[5].hitbox_inimigo.x + vilao[5].hitbox_inimigo.width)
                vilao[5].hitbox_inimigo.x += 1.0f;
            if(vilao[6].hitbox_inimigo.y + vilao[6].hitbox_inimigo.height <= vilao[5].hitbox_inimigo.y)
                vilao[5].hitbox_inimigo.y -= 1.0f;
            if(vilao[6].hitbox_inimigo.y >= vilao[5].hitbox_inimigo.y + vilao[5].hitbox_inimigo.height)
                vilao[5].hitbox_inimigo.y += 1.0f;
            
    }
}

#endif 