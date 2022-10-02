#ifndef PLAYER
#define PLAYER

#include "menu.h"
#include "raylib.h"
#include "stdlib.h"
#include "stdio.h"

void movimenta_player(Rectangle* mario, Rectangle cr7, Texture2D texture2, Texture2D texture, int* posicaoAuxX1, int* posicaoAuxX2, int* posicaoAuxY1, int* posicaoAuxY2){

    const int screen_width = 1640;
    const int screen_height = 924;
    char flag;

    *posicaoAuxX1 = mario->x;        //variaveis aux que eu uso pra mudar a imagem do pers de acordo com a posicao q ele ta indo
    *posicaoAuxY1 = mario->y;

        //borda lateral = screenWidth/2 - texture.width/2
        //tamanho ate a borda = (screenWidth/2 - texture.width/2) + screen.width/2
        
    mario->x = mario->x;
    mario->y = mario->y;

    
    
    
    
        if (mario->x + texture2.width < (screen_width/2 + texture.width/2))        //so move pra direita se a posicao x do pers for menor q
            if (IsKeyDown(KEY_RIGHT)){
                mario->x += 4.0f;   
                flag = 'd';
            }
        
        if (mario->x > (screen_width - texture.width)/2)
            if (IsKeyDown (KEY_LEFT)){ 
                mario->x -= 4.0f;
                flag = 'e';
            }
        
        if(mario->y > (screen_height - texture.height)/2)                          //so move pra cima se a posicao y do pers for menor q
            if (IsKeyDown(KEY_UP)){ 
                mario->y -= 4.0f; 
                flag = 'c';
            }                
        
        if (mario->y + texture2.height < (screen_height/2 + texture.height/2))
            if (IsKeyDown(KEY_DOWN)) {
                mario->y += 4.0f;
                flag = 'b';
            }
   
    
    if(CheckCollisionRecs(*mario, cr7)==1){
        
            if (flag == 'e') {
                
                mario->x += 4.0f;
            }
                              
            if (flag == 'c') {
                
                mario->y += 4.0f;
            }
        
            if (flag == 'b') {
                
                mario->y -= 4.0f;
            }
                              
            if (flag == 'd') {
               
                mario->x -= 4.0f;
            }
    }
    
     
    
        *posicaoAuxX2 = mario->x;
        *posicaoAuxY2 = mario->y;
        
}
#endif