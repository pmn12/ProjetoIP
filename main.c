#include "raylib.h"
#include "menu.h"
#include "stdio.h"
#include "movimenta_player.h"


int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1760;       //define a largura da tela
    const int screenHeight = 1000;      //define a altura da tela
    int posicaoAuxX1 = 0, posicaoAuxX2 = 0, posicaoAuxY1 = 0, posicaoAuxY2 = 0;
    int fechar;
    //int flag2 = 0;

    fechar = AbrirMenu();
    abrir_jogo();

        Texture2D texture = LoadTexture("C:\\Users\\luant\\Desktop\\MapaDefinitivo.png");      
        Texture2D texture2 = LoadTexture("C:\\Users\\luant\\Desktop\\imagens\\kirito_direita-fococlipping-standard.png");
        Texture2D texture3 = LoadTexture("C:\\Users\\luant\\Desktop\\imagens\\kirito_esquerda.png");
        Texture2D texture4 = LoadTexture("C:\\Users\\luant\\Desktop\\imagens\\Screenshot_1-fococlipping-standard.png");
        Texture2D texture5 = LoadTexture("C:\\Users\\luant\\Desktop\\mario_cima.png");
        Texture2D texture6 = LoadTexture("C:\\Users\\luant\\Desktop\\mario_baixo.png");
        Texture2D texture7 = LoadTexture("C:\\Users\\luant\\Desktop\\pilar1.png");

    //inicia o personagem no centro da tela
    Rectangle cr7 = {500, 500, 300, 300};
    Rectangle mario = {200, 200, 50, 63};
    float frameWidth = (float)(texture2.width / 4);
    Vector2 parametro = {0,0};
    float timer = 0.0f;
    int frame = 0;
    int maxFrames = ((int)texture2.width / (int)frameWidth);

    SetShapesTexture(texture7, cr7);

    SetTargetFPS(60);           
 

    while (!WindowShouldClose()){   

        
       movimenta_player( &mario, cr7, texture2, texture, &posicaoAuxX1, &posicaoAuxX2, &posicaoAuxY1, &posicaoAuxY2);
        

//------------------------------------------------------------------------------------------------- 
        BeginDrawing();
        
         
        RLAPI void HideCursor(void);                                      // Hides cursor


            ClearBackground(RAYWHITE);
            
            timer += GetFrameTime();
            
            DrawTexture(texture, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2, WHITE); //desenha o mapa no centro da tela
            
            DrawTexture(texture7, 500, 500, WHITE);
            
            if(timer >= 0.2f){
                timer = 0.0f;
                frame += 1;
            }
            
            frame = frame % maxFrames;
            
            Rectangle pessoa = { frameWidth * frame, 0, frameWidth, (float)texture2.height};
            
            if(posicaoAuxX1 < posicaoAuxX2)                     //usa as variaveis auxiliares para saber se houve algm movimento,
            DrawTexturePro(texture2, pessoa, mario, parametro , 0 ,RAYWHITE);       //dependendo de como de moveu, a imagem do mario q aparece muda
            
            else if(posicaoAuxX1 > posicaoAuxX2)
            DrawTexturePro(texture3, pessoa, mario, parametro , 0 ,RAYWHITE); 
        
            else if(posicaoAuxY1 > posicaoAuxY2)
            DrawTexturePro(texture4, pessoa, mario, parametro , 0 ,RAYWHITE); 
        
            else if(posicaoAuxY1 < posicaoAuxY2)
            DrawTexturePro(texture5, pessoa, mario, parametro , 0 ,RAYWHITE); 

            else if(posicaoAuxY1 == posicaoAuxY2 || posicaoAuxX1 == posicaoAuxX2)
            DrawTexturePro(texture6, pessoa, mario, parametro , 0 ,RAYWHITE); 
       
        
            //DrawCircleV(personagem, 50, MAROON);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}