#include "menu.h"
#include "player.h"
#include "mapa.h"
#include "raylib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "inimigo.h"


int main(){
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1600;
    const int screenHeight = 800;
    abrirMenu();

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60); 

    int x = 0, y = 0, andando = 0, i = 1;
    
    Camera2D camera;
    initCamera(&camera);
     
    Texture2D mapa = LoadTexture("C:\\Users\\luant\\Desktop\\ProjetoPasta\\.vscode\\Assets\\MapaDefinitivo.png");
    Texture2D persoIdle = LoadTexture("C:\\Users\\luant\\Desktop\\ProjetoPasta\\.vscode\\Assets\\Idle.png");
    Texture2D persoRun = LoadTexture("C:\\Users\\luant\\Desktop\\ProjetoPasta\\.vscode\\Assets\\Run.png");
    Texture2D texture7 = LoadTexture("C:\\Users\\luant\\Desktop\\ProjetoPasta\\.vscode\\Assets\\GameOver.png");
    Texture2D barravida = LoadTexture("C:\\Users\\luant\\Desktop\\ProjetoPasta\\.vscode\\Assets\\barravida1.png");
    Texture2D attack0 = LoadTexture("C:\\Users\\luant\\Desktop\\ProjetoPasta\\.vscode\\Assets\\Attack1.png");
    Texture2D attack1 = LoadTexture("C:\\Users\\luant\\Desktop\\ProjetoPasta\\.vscode\\Assets\\Attack2.png");
    Texture2D attack2 = LoadTexture("C:\\Users\\luant\\Desktop\\ProjetoPasta\\.vscode\\Assets\\Attack3.png");

    Rectangle inimigo;
    Vector2 inimig;
    float frameWidthIdle = persoIdle.width / 10.0;
    float frameHeightIdle = persoIdle.height;
    float frameWidthRun = persoRun.width / 8.0;
    float frameHeightRun = persoRun.height;
    float FWattack = attack0.width / 7.0;
    float FHattack = (float) attack0.height;
    int frameIdle = 0;
    int frame = 0;
    float timeAttack = 0.0f;
    float time = 0.0f;
    int frameAttack = 0;

    


    Rectangle *rec_map = (Rectangle *) malloc(10 * sizeof(Rectangle));
    carregarRetangulos(rec_map, screenWidth, screenHeight, mapa);


    Personagem perso;
    initPerso(&perso, screenWidth, screenHeight, frameWidthIdle, frameHeightIdle, frameWidthRun, frameHeightRun, FWattack, FHattack);
    int attackMode = 0, attacking = 0;
    
    while (!WindowShouldClose() && perso.ativo == 1)    
    {
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

        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode2D(camera);
        desenharMapa(perso, &inimigo, &inimig, mapa, barravida, texture7, andando, i);
        DrawRectangleLines(perso.posicao.x + 47, perso.posicao.y + 25, 70, 15, BLACK);
        personagemAcertado(&perso, inimigo);
        desenharPerso(persoIdle, persoRun, &perso, andando, &attacking, FWattack, &timeAttack, &attackMode, attack0, attack1, attack2, FHattack, &frameAttack);
        EndDrawing();
    }

    free(rec_map);

    CloseWindow();    

    return 0; 
}