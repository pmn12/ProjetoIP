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
    Rectangle recRun;
    Rectangle hitbox;
    Rectangle recAttack;
} Personagem;


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

void initPerso(Personagem *perso, int screenWidth, int screenHeight, float frameWidthIdle, float frameHeightIdle, float frameWidthRun, float frameHeightRun, float FWattack, float FHattack) {
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
    perso -> recAttack.width = FWattack;
    perso -> recAttack.height = FHattack;
}

void updatePerso(Personagem *perso, int screenWidth, int screenHeight, float frameWidthIdle, float frameHeightIdle, float frameWidthRun, float frameHeightRun, int *frame, int *frameIdle, float *time, int *x, int *y, Rectangle *rec_map, int *andando, int *i) {
    int xaux, yaux, posicao = 0;
        xaux = *x;
        yaux = *y;
        perso -> posicao.x = screenWidth/2 + *x;
        perso -> posicao.y = screenHeight/2 + *y;
        perso -> hitbox.x = (screenWidth / 2 + frameWidthRun / 4 + frameWidthRun / 8) + *x;
        perso -> hitbox.y = (screenHeight / 2 + frameHeightRun / 4 + frameWidthRun / 8) + *y;
        
        if(*i == 1) {
            perso -> rec.width = frameWidthIdle;
            perso -> recRun.width = frameWidthRun;
        }
        else {
            perso -> rec.width = -frameWidthIdle;
            perso -> recRun.width = -frameWidthRun;
        }
        perso -> rec.x = (*frameIdle) * frameWidthIdle;
        perso -> recRun.x = (*frame) * frameWidthRun;
        if(IsKeyDown(KEY_A) == true) {
            xaux = xaux - 2;
            *andando = 1;
            posicao = 1;
            *i = -1;
            verificaColisao(andando, rec_map, *perso, posicao);
            
            if(*andando == 1) *x = xaux;
        }
        else if(IsKeyDown(KEY_D) == true) {
            xaux = xaux + 2;
            *andando = 1;
            posicao = 2;
            *i = 1;
            verificaColisao(andando, rec_map, *perso, posicao);
            
            if(*andando == 1) *x = xaux;
        }
        else if(IsKeyDown(KEY_W) == true) {
            yaux = yaux -2;
            *andando = 1;
            posicao = 3;
            verificaColisao(andando, rec_map, *perso, posicao);
            
            if(*andando == 1) *y = yaux;

        }
        else if(IsKeyDown(KEY_S) == true) {
            yaux = yaux + 2;
            *andando = 1;
            posicao = 0;
            verificaColisao(andando, rec_map, *perso, posicao);
            
            if(*andando == 1) *y = yaux;
        }
        else *andando = 0;

        

        if(*andando == 1) {
            *time += GetFrameTime();
            if(*time >= 0.2f) {
                (*frame)++;
                *time = 0.0f;
            }
            *frame = *frame % 8;
            *frameIdle = 0;
        }
        else {
            *frame = 0;

            *time += GetFrameTime();
            if(*time >= 0.2f) {
                (*frameIdle)++;
                *time = 0.0f;
            }
            *frameIdle = *frameIdle % 10;
         }   
}

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
    int x = 0, y = 0, andando = 0, i = 1;
    
    Camera2D camera;
    initCamera(&camera);
     
    Texture2D mapa = LoadTexture("./Assets/MapaDefinitivo.png");
    Texture2D persoIdle = LoadTexture("./Assets/Idle.png");
    Texture2D persoRun = LoadTexture("./Assets/Run.png");
    Texture2D attack0 = LoadTexture("./Assets/Attack1.png");
    Texture2D attack1 = LoadTexture("./Assets/Attack2.png");
    Texture2D attack2 = LoadTexture("./Assets/Attack3.png");
    float frameWidthIdle = persoIdle.width / 10.0;
    float frameHeightIdle = persoIdle.height;
    float frameWidthRun = persoRun.width / 8.0;
    float frameHeightRun = persoRun.height;
    float FWattack = attack0.width / 7.0;
    float FHattack = (float) attack0.height;
    float timeAttack = 0.0f;
    int frameIdle = 0;
    int frame = 0;
    float time = 0.0f;
    int frameAttack = 0;

    

    Rectangle *rec_map = (Rectangle *) malloc(10 * sizeof(Rectangle));
    carregarRetangulos(rec_map, screenWidth, screenHeight, mapa);

    Personagem perso;
    initPerso(&perso, screenWidth, screenHeight, frameWidthIdle, frameHeightIdle, frameWidthRun, frameHeightRun, FWattack, FHattack);
    
    int attackMode = 0, attacking = 0;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //---------------------------------------------------------------------------------
            //camera.target.x = perso.posicao.x - (screenWidth /2) /1.5;
            //camera.target.y = perso.posicao.y - (screenHeight /2) / 1.5;
        //updateCamera(&camera, &perso, screenWidth, screenHeight, mapa);
        //updatePerso(&perso, &x, &y, &frame, &time, frameWidth, frameHeight, &andando, &posicao, screenWidth, screenHeight, rec_map);
        if(IsKeyPressed(KEY_Z) == true) {
            attacking = 1;
        }
       updatePerso(&perso, screenWidth, screenHeight, frameWidthIdle, frameHeightIdle, frameWidthRun, frameHeightRun, &frame, &frameIdle, &time, &x, &y, rec_map, &andando, &i);
       updateCamera(&camera, &perso, screenWidth, screenHeight, mapa);
       if(i == 1) {
            perso.rec.width = frameWidthIdle;
            perso.recRun.width = frameWidthRun;
            perso.recAttack.width = FWattack;
        }
        else {
            perso.rec.width = -frameWidthIdle;
            perso.recRun.width = -frameWidthRun;
            perso.recAttack.width = -FWattack;
        }

        
        // Draw----------------------------------------
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode2D(camera);
           DrawTexture(mapa, screenWidth / 2 - mapa.width /2 ,screenHeight / 2 - mapa.height/2 , RAYWHITE);
            desenharPerso(persoIdle, persoRun, &perso, andando, &attacking, FWattack, &timeAttack, &attackMode, attack0, attack1, attack2, FHattack, &frameAttack);
            
            
          
            
            
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
