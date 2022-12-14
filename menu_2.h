#ifndef MENU
#define MENU

#include "menu.h"
#include "raylib.h"

int abrirMenu(){
    
    const int screen_weight = 1640;
    const int screen_height = 924;
    int bloqueador = 0;
    int fechar = 0;
    
    Sound Menu_Music = LoadSound("C:\\Users\\paulo\\Downloads\\21 - Dream.wav");
    
    SetSoundVolume(Menu_Music, 0.18);
    
    PlaySound(Menu_Music);

    InitWindow(screen_weight, screen_height , "raylib [core] example - keyboard input");

    Texture2D menu = LoadTexture("C:\\Users\\paulo\\OneDrive\\Imagens\\Menu.png");        // Carrega as texturas a partir de imagens da galeria
    Texture2D tutorial = LoadTexture("C:\\Users\\paulo\\OneDrive\\Imagens\\Tutorial.png");
    
    SetTargetFPS(60);
    
    while(IsKeyUp(KEY_ENTER)){

        BeginDrawing();
        
        if(bloqueador == 0)
            DrawTexture(menu, screen_weight/2 - menu.width/2, screen_height/2 - menu.height/2, WHITE); //desenha o mapa no centro da tela);

        if(IsKeyDown(KEY_H)){
            bloqueador = 1;
            DrawTexture(tutorial, screen_weight/2 - tutorial.width/2, screen_height/2 - tutorial.height/2, WHITE); //desenha o mapa no centro da tela);
        }

        if(IsKeyDown(KEY_ESCAPE))
            fechar = 1;

        EndDrawing();

    }

        StopSound(Menu_Music);   
           
        CloseWindow();

        return fechar;
    }

    void abrirJogo(){

        const int screenWidth = 1760;       //define a largura da tela
        const int screenHeight = 1000; 

        InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    }

#endif




