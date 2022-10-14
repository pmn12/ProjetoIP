#ifndef INIMIGO
#define INIMIGO

#include "raylib.h"
#include "stdio.h"
#include "stdlib.h"
#include "player.h"


void inimigoAcertado(Personagem perso, Rectangle inimigo, int i){
    
    Rectangle hitbox_ataque;

    if(i == 1){
        hitbox_ataque.x = perso.posicao.x + 100;
        hitbox_ataque.y = perso.posicao.y + 60;
    }

    else{
        hitbox_ataque.x = perso.posicao.x + 20;
        hitbox_ataque.y = perso.posicao.y + 60;
    }

    hitbox_ataque.height = perso.hitbox.height;
    hitbox_ataque.width = perso.hitbox.width;

    if(CheckCollisionRecs(hitbox_ataque, inimigo))
        DrawText("HIT!", perso.posicao.x + 50, perso.posicao.y - 25, 20, RED);

}

void personagemAcertado(Personagem* perso, Rectangle inimigo, int *morreu, Sound *Tema){

    if(CheckCollisionRecs(perso->hitbox, inimigo)){
        perso->vida_atual = (float)(perso->vida_atual) - 0.4;
    }

    //DrawText(TextFormat("Vida: %.2f", perso->vida_atual), perso->posicao.x, perso->posicao.y - 20, 30, RED);
    DrawRectangle(perso->posicao.x + 48, perso->posicao.y + 26, perso->vida_atual , 13 , RED);
    if(perso->vida_atual <= 0){
        abrirGameOver(&morreu, &Tema);
        perso->ativo = 0;
    }
}

#endif 