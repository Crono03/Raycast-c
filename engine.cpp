#define GLFW_INCLUDE_NONE
#define _USE_MATH_DEFINES
#include "windows.h"
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <math.h>
#include <cstdlib>
#include "GL/glut.h"
#include "init.h"
#include "game.h"

// Funzione per disegnare una linea
void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void drawScene() {
    // Impostiamo il colore di sfondo
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    // Attiviamo il depth test
    glEnable(GL_DEPTH_TEST);

    // Impostiamo la trasformazione di proiezione
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fov * 180.0f / M_PI, (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 200.0f);

    // Impostiamo la trasformazione di vista
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(playerPosX, 1.0f, playerPosZ, playerPosX + cos(angle), 1.0f, playerPosZ + sin(angle), 0.0f, 1.0f, 0.0f);

    

    // Disegniamo i muri
    glColor3f(0.0f, 1.0f, 0.0f); // colore verde
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (map[i][j] == 1) {
                // calcoliamo le coordinate dei vertici del quadrato corrispondente al muro
                float x1 = i;
                float z1 = j;
                float x2 = i + 1;
                float z2 = j + 1;
                
                // disegniamo il quadrato come un muro
                glVertex3f(x1, 0.0f, z1);
                glVertex3f(x2, 0.0f, z1);
                glVertex3f(x2, 1.0f, z1);
                glVertex3f(x1, 1.0f, z1);

                glVertex3f(x2, 0.0f, z1);
                glVertex3f(x2, 0.0f, z2);
                glVertex3f(x2, 1.0f, z2);
                glVertex3f(x2, 1.0f, z1);

                glVertex3f(x2, 0.0f, z2);
                glVertex3f(x1, 0.0f, z2);
                glVertex3f(x1, 1.0f, z2);
                glVertex3f(x2, 1.0f, z2);

                glVertex3f(x1, 0.0f, z2);
                glVertex3f(x1, 0.0f, z1);
                glVertex3f(x1, 1.0f, z1);
                glVertex3f(x1, 1.0f, z2);
                
            }
        }
    }

    // Disegniamo il soffitto
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-10.0f, 10.0f, -10.0f);
    glVertex3f(-10.0f, 10.0f, 10.0f);
    glVertex3f(10.0f, 10.0f, 10.0f);
    glVertex3f(10.0f, 10.0f, -10.0f);
    glEnd();

    // Disegniamo il pavimento come scacchiera
    glBegin(GL_QUADS);
    for (int x = -10; x < 10; x++) {
        for (int z = -10; z < 10; z++) {
            if ((x + z) % 2 == 0) {
                glColor3f(1.0f, 1.0f, 1.0f); // quadrato bianco
            }
            else {
                glColor3f(0.0f, 0.0f, 0.0f); // quadrato nero
            }
            glVertex3f(x, 0.0f, z);
            glVertex3f(x + 1, 0.0f, z);
            glVertex3f(x + 1, 0.0f, z + 1);
            glVertex3f(x, 0.0f, z + 1);
        }
    }
    glEnd();


    // Disegniamo il giocatore
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(playerPosX - 0.1f, 0.0f, playerPosZ - 0.1f);
    glVertex3f(playerPosX - 0.1f, 0.0f, playerPosZ + 0.1f);
    glVertex3f(playerPosX + 0.1f, 0.0f, playerPosZ + 0.1f);
    glVertex3f(playerPosX + 0.1f, 0.0f, playerPosZ - 0.1f);
    glEnd();

    // Disegniamo la direzione dello sguardo del giocatore
    glColor3f(1.0f, 1.0f, 0.0f);
    drawLine(playerPosX, 0.0f, playerPosX + playerDirX, playerDirZ);

    // Disabilitiamo il depth test per il rendering dell'HUD
    glDisable(GL_DEPTH_TEST);

    // Impostiamo la trasformazione di proiezione per l'HUD
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT, -1, 1);

    // Impostiamo la trasformazione di vista per l'HUD
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();



}