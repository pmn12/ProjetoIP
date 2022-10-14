#ifndef CRISTAL
#define CRISTAL


#include "cristal.h"
#include "raylib.h"
#include "stdio.h"
#include "stdlib.h"
#include "player.h"


typedef struct{
    float vida_cristal;
    bool ativo_cristal;
    Rectangle hitbox_cristal;
}Cristal;

Cristal* initCristal(Cristal *cristal, Texture2D mapa){
    
    const int screenWidth = 1600;
    const int screenHeight = 800;

    for(int i=0;i<2;i++){
        
        cristal[i].vida_cristal = 68;
        cristal[i].ativo_cristal = 1;
        
    }
    
    cristal[0].hitbox_cristal.x = (screenWidth / 2 - mapa.width /2) + 1500;
    cristal[0].hitbox_cristal.y = 330;
    cristal[0].hitbox_cristal.height = 120;
    cristal[0].hitbox_cristal.width = 120;
    cristal[1].hitbox_cristal.x = (screenWidth / 2 - mapa.width /2) + 140;
    cristal[1].hitbox_cristal.y = 330;
    cristal[1].hitbox_cristal.height = 120;
    cristal[1].hitbox_cristal.width = 120;
    
    return cristal;
}

#endif 