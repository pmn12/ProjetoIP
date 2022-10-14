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
    InitAudioDevice();
  
    int t = abrirMenu();

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60); 

    int x = 0, y = 0, andando = 0, i = 1;
    
    Camera2D camera;
    initCamera(&camera);
     
    Texture2D mapa = LoadTexture("C:\\Users\\luant\\Desktop\\ProjetoPasta\\.vscode\\Assets\\MapaDefinitivo.png");
    Texture2D persoIdle = LoadTexture("C:\\Users\\luant\\Desktop\\ProjetoPasta\\.vscode\\Assets\\Idle.png");
    Texture2D persoRun = LoadTexture("C:\\Users\\luant\\Desktop\\ProjetoPasta\\.vscode\\Assets\\Run.png");
    Texture2D attack0 = LoadTexture("C:\\Users\\luant\\Desktop\\ProjetoPasta\\.vscode\\Assets\\Attack1.png");
    Texture2D attack1 = LoadTexture("C:\\Users\\luant\\Desktop\\ProjetoPasta\\.vscode\\Assets\\Attack2.png");
    Texture2D attack2 = LoadTexture("C:\\Users\\luant\\Desktop\\ProjetoPasta\\.vscode\\Assets\\Attack3.png");
    //----------------------------------------------------------------------------------------------
    Texture2D vilao1 = LoadTexture("C:\\Users\\luant\\Desktop\\ProjetoPasta\\.vscode\\Assets\\messi.png");
    Texture2D vilao2 = LoadTexture("C:\\Users\\luant\\Desktop\\ProjetoPasta\\.vscode\\Assets\\messi2.png");
    Texture2D torreimg = LoadTexture("C:\\Users\\luant\\Desktop\\ProjetoPasta\\.vscode\\Assets\\torre.png");

    Enemy *Recvilao;
    Recvilao = (Enemy *)malloc(7 * sizeof(Enemy));

    //----------------------------------------------------------------------------------------------
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
    int time2 = 0;

    Rectangle *rec_map = (Rectangle *) malloc(10 * sizeof(Rectangle));
    carregarRetangulos(rec_map, screenWidth, screenHeight, mapa);

    Personagem perso;
    initPerso(&perso, screenWidth, screenHeight, frameWidthIdle, frameHeightIdle, frameWidthRun, frameHeightRun, FWattack, FHattack);
    
    Recvilao = initVilao(Recvilao, mapa);

    int attackMode = 0, attacking = 0;
    int morreu = 0;
    Sound Tema = LoadSound("C:\\Users\\luant\\Desktop\\ProjetoPasta\\.vscode\\Assets\\Christopher Larkin - Hollow Knight (Original Soundtrack) - 25 Radiance.wav");
    SetSoundVolume(Tema, 0.18);

    while (!WindowShouldClose() && morreu == 0 && t==0)    
    {
        time2 = GetTime();

        if(IsSoundPlaying(Tema) == 0){
            PlaySound(Tema);
        }
        
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

        movimentarvilao(perso.hitbox, Recvilao, time2);

        BeginDrawing();

        ClearBackground(BLACK);

        BeginMode2D(camera);

        desenharMapa(perso, mapa, andando, i);

        DrawRectangleLines(perso.posicao.x + 47, perso.posicao.y + 25, 70, 15, BLACK);
        personagemAcertado(&perso, Recvilao, &morreu, &Tema);

        if(perso.ativo == 0 && morreu == 0){
            x=0;
            y=0;
            initPerso(&perso, screenWidth, screenHeight, frameWidthIdle, frameHeightIdle, frameWidthRun, frameHeightRun, FWattack, FHattack);
            Recvilao = initVilao(Recvilao, mapa);
        }

        desenharPerso(persoIdle, persoRun, &perso, andando, &attacking, FWattack, &timeAttack, &attackMode, attack0, attack1, attack2, FHattack, &frameAttack);

        DrawTexture(torreimg, 750, 340, WHITE);            
        desenharvilao(time2, vilao1, vilao2, Recvilao);
        Recvilao = inimigoAcertado(perso, Recvilao, i, &morreu, &Tema);
        DrawText(TextFormat("Tempo -> %i", time2), screenWidth/2, screenHeight/2 - 100, 40, RED);
        EndDrawing();
    }

    free(rec_map);
    free(Recvilao);
    
    StopSound(Tema);
    
    CloseAudioDevice();

    CloseWindow();    

    return 0; 
}