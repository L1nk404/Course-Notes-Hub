/******************************************************************************
 * File: Bouncy.c
 * Author: Link
 * Description: [brief description of the program's purpose]
 *
 * Created: 2025-06-09
 * Last Modified: [last modification date]
 *
 * Compiler: gcc (GCC) 15.1.1 2025042
 ******************************************************************************/

#include <SDL2/SDL.h>
#include <stdio.h>

#define WIDTH 900
#define HEIGHT 600
#define DELAY 3000

// Colors
#define PINK 0xf56f97
#define WHITE 0xFFFFFFFF
#define BLACK 0x00000000

// // Physics constans
// #define G 9.80665
// #define A 15
#define LOSS_ENERGY 1

struct Circle
{

    double x;
    double y;
    double radius;

    // Velocity
    double a_x;
    double a_y;

    // Creating flags to track movement direction:
    int direction_y; // -1: ascending / 1: descending
    int direction_x; // -1: left / 1: right
};

void FillCircle(SDL_Surface *surface, struct Circle circle)
{
    double low_x = circle.x - circle.radius;
    double low_y = circle.y - circle.radius;
    double high_x = circle.x + circle.radius;
    double high_y = circle.y + circle.radius;

    double radius_squared = circle.radius * circle.radius;

    for (int x = low_x; x < high_x; x++)
    {
        for (int y = low_y; y < high_y; y++)
        {
            // Check if ||x² + y²|| < r² (is inside ball)
            double center_distance_square = (x - circle.x) * (x - circle.x) +
                                            (y - circle.y) * (y - circle.y);

            if (center_distance_square < radius_squared)
            {
                // Creating a retangle object
                SDL_Rect pixel = (SDL_Rect){x, y,  // coordinates (x,y)
                                            1, 1}; // Width, Height
                // Coloring the retangle
                SDL_FillRect(surface,      // Destination surface Pointer
                             &pixel,       // Rect object Pointer
                             COLOR_WHITE); // Unitd32 color
            }
        }
    }
}

void step(struct Circle *circle)
{
    double G = 9.8;

    int ascending_counter = 10;

    if (circle->direction_y == 1) // Descending
    {

        if (circle->y > (HEIGHT - circle->radius))
        {
            circle->direction_y = -1 * circle->direction_y;
        }

        circle->a_y = G;
        circle->y = circle->y + circle->a_y;
    }
    else if (circle->direction_y == -1) // Ascending
    {
        double potencial_energy = ascending_counter * LOSS_ENERGY;
        double A = G + 1 - potencial_energy;

        if (circle->y < circle->radius)
        {
            ascending_counter++;
            circle->direction_y = -1 * circle->direction_y;
        }
        circle->a_y = A;
        circle->y = circle->y - circle->a_y;
    }
}

int main()
{
    // Initialises Data
    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;

    /*
     Initialises the SDL video (as well as the events subsystem).
     Return 0 on sucess or a negative error code on failure using SDL_GetError()
    */
    if (SDL_Init(SDL_INIT_VIDEO) != 0) // if error
    {
        fprintf(stderr, "SDL failed to initialise %s\n", SDL_GetError());
        return 1;
    }

    // Creates a SDL window
    window =
        SDL_CreateWindow("Particle Simulator",   // Title of the SDL window
                         SDL_WINDOWPOS_CENTERED, // Position x of the window
                         SDL_WINDOWPOS_CENTERED, // Position y of the window
                         WIDTH, HEIGHT, // Width, height of the window in pixels
                         0);            // Additional flag(s)

    // Creates Window surface to be able to drawing pixels to the window's
    // display memory using CPU
    surface = SDL_GetWindowSurface(window);

    struct Circle circle = (struct Circle){
        (WIDTH / 2 - 25), // x
        50,               // y
        50,               // radius
        0,                // a_x
        0,                // a_y
        1,                // Start descending
        1,                // Start moving to right
    };

    SDL_Event event;

    SDL_Rect erase_rect = (SDL_Rect){0, 0, WIDTH, HEIGHT};
    int simulation_running = 1;
    while (simulation_running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                simulation_running = 0;
            }
        }
        SDL_FillRect(surface, &erase_rect, BLACK);
        // Create a cricle object
        FillCircle(surface, circle);

        step(&circle);

        // Update the Window surface
        SDL_UpdateWindowSurface(window);

        SDL_Delay(10);
    }

    // Checks if window has been created; if not, exits program
    if (window == NULL)
    {
        fprintf(stderr, "Window failed to initialise: %s\n", SDL_GetError());
        return 1;
    }

    // Pauses all SDL subsystems for a variable amount of milliseconds
    SDL_Delay(DELAY);

    // Free memory - Close Window
    SDL_DestroyWindow(window);

    // Shuts down all SDL subsystems
    SDL_Quit();

    return 0;
}