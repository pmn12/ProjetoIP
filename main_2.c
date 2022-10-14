#include "menu.h"
#include "player.h"
#include "mapa.h"
#include "raylib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitAudioDevice();
    const int screenWidth = 1600;
    const int screenHeight = 800;
    abrirMenu();
    
    Sound Theme_Music = LoadSound("C:\\Users\\paulo\\Downloads\\Christopher Larkin - Hollow Knight (Original Soundtrack) - 25 Radiance.wav");
    
    SetSoundVolume(Theme_Music, 0.18);
    
    PlaySound(Theme_Music);

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60); 

    int x = 0, y = 0, andando = 0, i = 1;
    
    Camera2D camera;
    initCamera(&camera);
     
    Texture2D mapa = LoadTexture("C:\\Users\\paulo\\OneDrive\\Imagens\\MapaDefinitivo.png");
    Texture2D persoIdle = LoadTexture("C:\\Users\\paulo\\OneDrive\\Imagens\\Idle.direita.png");
    Texture2D persoRun = LoadTexture("C:\\Users\\paulo\\OneDrive\\Imagens\\Run.direita.png");
    Texture2D persoAtac = LoadTexture("C:\\Users\\paulo\\OneDrive\\Imagens\\Attack1.direita.png");
    Texture2D texture7 = LoadTexture("C:\\Users\\paulo\\OneDrive\\Imagens\\GameOver.png");

    float frameWidthIdle = persoIdle.width / 10.0;
    float frameHeightIdle = persoIdle.height;
    float frameWidthRun = persoRun.width / 8.0;
    float frameHeightRun = persoRun.height;
    float frameWidthAtac = persoAtac.width / 7.0;
    float frameHeightAtac = persoAtac.height;
    int frameIdle = 0;
    int frame = 0;
    int frameAtac = 0;
    float time = 0.0f;

    

    Rectangle *rec_map = (Rectangle *) malloc(10 * sizeof(Rectangle));
    carregarRetangulos(rec_map, screenWidth, screenHeight, mapa);

    Rectangle inimigo;
    inimigo.x = 500;
    inimigo.y = 500;
    inimigo.width = 100;
    inimigo.height = 100;
    Vector2 inimig;
    inimig.x = 500;
    inimig.y = 500;

    Personagem perso;
    initPerso(&perso, screenWidth, screenHeight, frameWidthIdle, frameHeightIdle, frameWidthRun, frameHeightRun, frameWidthAtac, frameHeightAtac);
    
    
    while (!WindowShouldClose())    
    {
       updatePerso(&perso, screenWidth, screenHeight, frameWidthIdle, frameHeightIdle, frameWidthRun, frameHeightRun, frameHeightAtac, frameWidthAtac, &frame, &frameIdle, &frameAtac, &time, &x, &y, rec_map, &andando, &i);
       updateCamera(&camera, &perso, screenWidth, screenHeight, mapa);
       
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode2D(camera);
        DrawTexture(mapa, screenWidth / 2 - mapa.width /2 ,screenHeight / 2 - mapa.height/2 , RAYWHITE);
        DrawTextureRec(texture7, inimigo, inimig, RAYWHITE);
        desenharPerso(persoIdle, persoRun, persoAtac, perso, andando);
            
        EndDrawing();
    }

    free(rec_map);
    
    StopSound(Theme_Music);
    
    CloseAudioDevice();

    CloseWindow();     


    return 0;
}
