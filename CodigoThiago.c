/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0

*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2022 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    Vector2 posicao;
    Rectangle rec;
    Rectangle hitbox;
} Personagem;

void DesenharPersonagem(Texture2D personagem, Personagem perso, int andando, int posicao) {
    DrawTextureRec(personagem, perso.rec, perso.posicao, RAYWHITE);
}

void carregarRetangulos(Rectangle *rec_map,int screenWidth, int screenHeight, Texture2D mapa) {
    
    rec_map[0].x = (screenWidth / 2 - mapa.width /2) + 17;
    rec_map[0].y = (screenHeight /2 - mapa.height / 2) + 659;
    rec_map[0].width = 1781;
    rec_map[0].height = 10;

    rec_map[1].x = (screenWidth / 2 - mapa.width /2) + 3;
    rec_map[1].y = (screenHeight /2 - mapa.height / 2) + 180;
    rec_map[1].width = 10;
    rec_map[1].height = 500;

     rec_map[2].x = (screenWidth / 2 - mapa.width /2) + 17;
    rec_map[2].y = (screenHeight /2 - mapa.height / 2) + 150;
    rec_map[2].width = 1781;
    rec_map[2].height = 10;

    rec_map[3].x = (screenWidth / 2 - mapa.width /2) + 1801;
    rec_map[3].y = (screenHeight /2 - mapa.height / 2) + 170;
    rec_map[3].width = 10;
    rec_map[3].height = 500;

    rec_map[4].x = (screenWidth / 2 - mapa.width /2) + 17;
    rec_map[4].y = (screenHeight /2 - mapa.height / 2) + 193;
    rec_map[4].width = 63;
    rec_map[4].height = 12;

    rec_map[5].x = (screenWidth / 2 - mapa.width /2) + 70;
    rec_map[5].y = (screenHeight /2 - mapa.height / 2) + 150;
    rec_map[5].width = 12;
    rec_map[5].height = 53;


    
    
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



//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1809;
    const int screenHeight = 809;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    // Textures:
    int x = 0, y = 0, andando = 0, posicao = 0, xaux, yaux;

    Personagem perso;
    perso.posicao.x = screenWidth / 2;
    perso.posicao.y = screenHeight / 2;

    Camera2D camera;
    camera.offset.x = 0;
    camera.offset.y = 0;
    camera.target.x = perso.posicao.x;
    camera.target.y = perso.posicao.y;
    
    camera.rotation = 0.0f;
    camera.zoom = 1;

    
    
    
    Texture2D mapa = LoadTexture("./Assets/MapaDefinitivo.png");
    Texture2D personagem = LoadTexture("./Assets/perso.png");
    float frameWidth = personagem.width / 4.0;
    float frameHeight = personagem.height / 4.0;
    int frame = 0;
    float time = 0.0f;

    char posx[20];
    char posy[20];
    int mousex;
    int mousey;
    

    Rectangle *rec_map = (Rectangle *) malloc(10 * sizeof(Rectangle));
    carregarRetangulos(rec_map, screenWidth, screenHeight, mapa);
    
    

   
    
    

    
    
    

   
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //---------------------------------------------------------------------------------
        
        camera.target.x = perso.posicao.x - screenWidth /3 + 20;
        camera.target.y = perso.posicao.y - screenHeight / 3 + 20;

        mousex = GetMouseX();
        mousey = GetMouseY();

        sprintf(posx, "%d", mousex);
        sprintf(posy, "%d", mousey);
        strcat(posx, " ");
        strcat(posx, posy);
    
        
        
        
        
        

        perso.rec.height = frameHeight;
        perso.rec.width = frameWidth;
        perso.rec.x = frame * frameWidth;
        perso.rec.y = posicao * frameHeight;
        perso.posicao.x = screenWidth / 2 + x;
        perso.posicao.y = screenHeight /2 + y;
        perso.hitbox.width = frameWidth;
        perso.hitbox.height = frameHeight;
        perso.hitbox.x = (screenWidth / 2) + x;
        perso.hitbox.y = (screenHeight / 2) + y;

        yaux = y;
        xaux = x;

        if(IsKeyDown(KEY_A) == true) {
            xaux = xaux - 2;
            andando = 1;
            posicao = 1;
            verificaColisao(&andando, rec_map, perso, posicao);
            if(andando == 1) x = xaux;
        }
        else if(IsKeyDown(KEY_D) == true) {
            xaux = xaux + 2;
            andando = 1;
            posicao = 2;
            verificaColisao(&andando, rec_map, perso, posicao);
            if(andando == 1) x = xaux;
        }
        else if(IsKeyDown(KEY_W) == true) {
            yaux = yaux -2;
            andando = 1;
            posicao = 3;
            verificaColisao(&andando, rec_map, perso, posicao);
            if(andando == 1) y = yaux;

        }
        else if(IsKeyDown(KEY_S) == true) {
            yaux = yaux + 2;
            andando = 1;
            posicao = 0;
            verificaColisao(&andando, rec_map, perso, posicao);
            if(andando == 1) y = yaux;
        }
        else {
            andando = 0;
            frame = 0;
        }

        if(andando == 1) {
            time += GetFrameTime();
            if(time >= 0.2f) {
                frame++;
                time = 0.0f;
            }
            frame = frame % 4;
        }
        
        
         
        // Draw----------------------------------------
        BeginDrawing();
        ClearBackground(BLACK);
        //BeginMode2D(camera);
            DrawTexture(mapa, screenWidth / 2 - mapa.width /2 ,screenHeight / 2 - mapa.height/2 , RAYWHITE);
            DesenharPersonagem(personagem, perso, andando, posicao);
            DrawText(posx, 200  , 200 , 20, RED);
            
                DrawRectangleLinesEx(perso.hitbox, 2, RED);
                for(int i = 4; i < 6; i++)
            DrawRectangleRec(rec_map[i], BLUE);
            
            
        //EndMode2D();
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    free(rec_map);
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
