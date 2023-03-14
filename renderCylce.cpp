#define GLFW_INCLUDE_NONE
#define _USE_MATH_DEFINES
#include "windows.h"
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <math.h>
#include <iostream>
#include <cstdlib>
#include "GL/glut.h"
#include "init.h"
#include "engine.h"

GLFWwindow* preRender() {
    // Inizializziamo GLFW
    if (!glfwInit()) {
        std::cerr << "Errore durante l'inizializzazione di GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    // Creiamo la finestra
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Labirinto 2D", nullptr, nullptr);
    if (!window) {
        std::cerr << "Errore durante la creazione della finestra GLFW" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Impostiamo la finestra come contesto corrente
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    return window;
}

void Render() {
    GLFWwindow* window = preRender();
    
    // Ciclo render principale
    while (!glfwWindowShouldClose(window)) {
        // Disegniamo la scena
        
        drawScene();
        // Scambiamo il buffer di disegno con il buffer di visualizzazione


        glfwSwapBuffers(window);

        // Aggiorniamo gli input e gli eventi
        glfwPollEvents();

    }
}