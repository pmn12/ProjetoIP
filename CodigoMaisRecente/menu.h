#ifndef MENU
#define MENU

#include "player.h"
#include "menu.h"
#include "raylib.h"

int abrirMenu(){
    
    const int screen_weight = 1640;
    const int screen_height = 924;
    int bloqueador = 0;
    int fechar = 0;
    
    Sound Menu = LoadSound("C:\\Users\\luant\\Desktop\\ProjetoPasta\\.vscode\\Assets\\21 - Dream.wav");
    SetSoundVolume(Menu, 0.18);

    InitWindow(screen_weight, screen_height , "raylib [core] example - keyboard input");

    Texture2D menu = LoadTexture("C:\\Users\\luant\\Desktop\\ProjetoPasta\\.vscode\\Assets\\Menu.png");        // Carrega as texturas a partir de imagens da galeria
    Texture2D tutorial = LoadTexture("C:\\Users\\luant\\Desktop\\ProjetoPasta\\.vscode\\Assets\\Tutorial.png");
    SetTargetFPS(60);
    
    PlaySound(Menu);
    
    while(IsKeyUp(KEY_ENTER)==1 && IsKeyUp(KEY_ESCAPE)==1){

        BeginDrawing();
        
        if(bloqueador == 0)
            DrawTexture(menu, screen_weight/2 - menu.width/2, screen_height/2 - menu.height/2, WHITE); //desenha o mapa no centro da tela);

        if(IsKeyDown(KEY_H)){
            bloqueador = 1;
            DrawTexture(tutorial, screen_weight/2 - tutorial.width/2, screen_height/2 - tutorial.height/2, WHITE); //desenha o mapa no centro da tela);
        }

        EndDrawing();
        
        if(IsKeyDown(KEY_ESCAPE)){
            fechar = 1;
        }

    }
        
        StopSound(Menu);

        CloseWindow();

        return fechar;
    }

    void abrirJogo(){

        const int screenWidth = 1760;       //define a largura da tela
        const int screenHeight = 1000; 

        InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    }

void abrirGameOver(int **morreu, Sound **Tema){
    
    StopSound(**Tema);

    const int screen_weight = 1600;
    const int screen_height = 800;
    Texture2D GameOver = LoadTexture("C:\\Users\\luant\\Desktop\\ProjetoPasta\\.vscode\\Assets\\GameOver.png");
    SetTargetFPS(60);
    **morreu = 1;

    while(IsKeyUp(KEY_ESCAPE) && IsKeyUp(KEY_ENTER)){
        BeginDrawing();
        DrawTexture(GameOver, screen_weight/2 - GameOver.width/2, screen_height/2 - GameOver.height/2, WHITE);
        EndDrawing();
        if(IsKeyPressed(KEY_ENTER)){
           **morreu = 0;
        }
    }
}

#endif
