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

void initCamera(Camera2D *camera) {
    camera -> offset.x = 0;
    camera -> offset.y = 0; 
    camera -> rotation = 0.0f;
    camera -> zoom = 1.5;
}

void updateCamera(Camera2D *camera, Personagem *perso, int screenWidth, int screenHeight, Texture2D mapa) {
    if(perso -> posicao.x -(screenWidth /2) /1.5 <= (screenWidth /2 - mapa.width /2)) {
        camera -> target.x = (screenWidth /2 - mapa.width /2);
                     
    }
    else if(perso -> posicao.x -(screenWidth /2) /1.5 >= mapa.width /2 - ((screenWidth / 2) / 1.5) / 2 ) {
        camera -> target.x = mapa.width /2 - ((screenWidth / 2) / 1.5) /2 ;
                
    }
    else {
        camera -> target.x = perso -> posicao.x - (screenWidth /2) /1.5;
    }
            
    if(perso -> posicao.y - (screenHeight / 2) / 1.5 <=(screenHeight /2 - mapa.height /2) + ((screenHeight / 2) / 1.5) / 8 ) {
        camera -> target.y = (screenHeight /2 - mapa.height /2) + ((screenHeight / 2) / 1.5) / 8;
    }
    else if(perso -> posicao.y - (screenHeight / 2) / 1.5 >= mapa.height /2 - ((screenHeight / 2) / 1.5) / 2) {
        camera -> target.y = mapa.height /2 - ((screenHeight / 2) / 1.5) / 2;
    }
    else {
        camera -> target.y = perso -> posicao.y - (screenHeight /2) / 1.5;
    }
}

void initPerso(Personagem *perso, float frameWidth, float frameHeight) {
    perso -> rec.height = frameHeight;
    perso -> rec.width = frameWidth;
    perso -> hitbox.width = frameWidth / 2;
    perso -> hitbox.height = frameHeight / 2 + 10;
}

void updatePerso(Personagem *perso, int *x, int *y, int *frame, float *time, int frameWidth, int frameHeight, int *andando, int *posicao, int screenWidth, int screenHeight, Rectangle *rec_map) {
        perso -> rec.x = (*frame) * frameWidth;
        perso -> rec.y = (*posicao) * frameHeight;
        perso -> posicao.x = screenWidth / 2 + *x;
        perso -> posicao.y = screenHeight /2 + *y;
        perso -> hitbox.x = (screenWidth / 2 + frameWidth /4) + *x;
        perso -> hitbox.y = (screenHeight / 2 + frameHeight / 4) + *y;

        int yaux = *y;
        int xaux = *x;

        if(IsKeyDown(KEY_A) == true) {
            xaux = xaux - 2;
            *andando = 1;
            *posicao = 1;
            verificaColisao(andando, rec_map, *perso, *posicao);
            if(*andando == 1) *x = xaux;
        }
        else if(IsKeyDown(KEY_D) == true) {
            xaux = xaux + 2;
            *andando = 1;
            *posicao = 2;
            verificaColisao(andando, rec_map, *perso, *posicao);
            if(*andando == 1) *x = xaux;
        }
        else if(IsKeyDown(KEY_W) == true) {
            yaux = yaux -2;
            *andando = 1;
            *posicao = 3;
            verificaColisao(andando, rec_map, *perso, *posicao);
            if(*andando == 1) *y = yaux;

        }
        else if(IsKeyDown(KEY_S) == true) {
            yaux = yaux + 2;
            *andando = 1;
            *posicao = 0;
            verificaColisao(andando, rec_map, *perso, *posicao);
            if(*andando == 1) *y = yaux;
        }
        else {
            *andando = 0;
            *frame = 0;
        }

        if(*andando == 1) {
            *time += GetFrameTime();
            if(*time >= 0.2f) {
                (*frame)++;
                *time = 0.0f;
            }
            *frame = *frame % 4;
        }
}






//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1200;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    // Textures:
    int x = 0, y = 0, andando = 0, posicao = 0;
    Personagem perso;
    
    Camera2D camera;
    initCamera(&camera);
     
    Texture2D mapa = LoadTexture("./Assets/MapaDefinitivo.png");
    Texture2D personagem = LoadTexture("./Assets/perso.png");
    float frameWidth = personagem.width / 4.0;
    float frameHeight = personagem.height / 4.0;
    int frame = 0;
    float time = 0.0f;

    initPerso(&perso, frameWidth, frameHeight);

    Rectangle *rec_map = (Rectangle *) malloc(10 * sizeof(Rectangle));
    carregarRetangulos(rec_map, screenWidth, screenHeight, mapa);
    
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //---------------------------------------------------------------------------------
            //camera.target.x = perso.posicao.x - (screenWidth /2) /1.5;
            //camera.target.y = perso.posicao.y - (screenHeight /2) / 1.5;
        updateCamera(&camera, &perso, screenWidth, screenHeight, mapa);
        updatePerso(&perso, &x, &y, &frame, &time, frameWidth, frameHeight, &andando, &posicao, screenWidth, screenHeight, rec_map);    
         
        // Draw----------------------------------------
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode2D(camera);
            DrawTexture(mapa, screenWidth / 2 - mapa.width /2 ,screenHeight / 2 - mapa.height/2 , RAYWHITE);
            DesenharPersonagem(personagem, perso, andando, posicao);

            
          
            
            
        EndMode2D();
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
