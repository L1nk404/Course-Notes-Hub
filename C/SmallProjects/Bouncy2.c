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
#define DELAY 20

#define TRAJECTORY_LENGHT 100
#define TRAJECTORY_WIDTH 5
// Colors
#define COLOR_PINK 0xf56f97
#define COLOR_WHITE 0xFFFFFFFF
#define COLOR_BLACK 0x00000000
#define COLOR_BRACKGROUND 0x1E1F29
#define COLOR_ORANGE 0xff763b

// // Physics constans
// #define G 9.80665
#define G 7
#define LOSS_ENERGY 1

struct Circle
{
    double x;
    double y;
    double radius;

    // Aceleration
    double a_x;
    double a_y;

    // Creating flags to track movement direction:
    int direction_y; // -1: ascending / 1: descending
    int direction_x; // -1: left / 1: right
};

void FillCircle(SDL_Surface *surface, struct Circle circle, Uint32 color)
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
                SDL_FillRect(surface, // Destination surface Pointer
                             &pixel,  // Rect object Pointer
                             color);  // Unitd32 color
            }
        }
    }
}

void FillTrajectory(SDL_Surface *surface,
                    struct Circle trajectory[TRAJECTORY_LENGHT],
                    int current_trajectory_index, Uint32 color)
{
    for (int i = 0; i < current_trajectory_index; i++)
    {
        // double tractory_size = TRAJECTORY_WIDTH * (double)i /
        // TRAJECTORY_LENGHT; trajectory[i].radius = tractory_size;
        FillCircle(surface, trajectory[i % TRAJECTORY_LENGHT], color);
    }
}

void UpdateTrajectory(struct Circle trajectory[TRAJECTORY_LENGHT],
                      struct Circle circle, int current_index)
{
    double radius;
    int index_cache;
    int mod_current_index = current_index % TRAJECTORY_LENGHT;

    if (current_index < TRAJECTORY_LENGHT)
    {
        index_cache = current_index;
    }
    else
    {
        index_cache = TRAJECTORY_LENGHT;
    }

    radius = TRAJECTORY_WIDTH * (double)index_cache / TRAJECTORY_LENGHT;
    printf("ENTER CASE, MOD=%d,CACHE = %d, RADIUS = %lf\n", mod_current_index,
           index_cache, radius);

    struct Circle tracer = (struct Circle){
        circle.x,           // x
        circle.y,           // y
        radius,             // radius
        circle.a_x,         // a_x
        circle.a_y,         // a_y
        circle.direction_y, // Start descending
        circle.direction_x, // Start moving to right
    };

    // Better aproax
    trajectory[mod_current_index] = tracer;
}

void step(struct Circle *circle)
{
    // Y axis
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

        double A = G + 1;

        if (circle->y < circle->radius)
        {
            circle->direction_y = -1 * circle->direction_y;
        }
        circle->a_y = A;
        circle->y = circle->y - circle->a_y;
    }

    // X axis
    if (circle->direction_x == 1) // right
    {
        if (circle->x > (WIDTH - circle->radius))
        {
            circle->direction_x = -1 * circle->direction_x;
        }
        circle->x = circle->x + circle->a_x;
    }
    else if (circle->direction_x == -1)
    {
        if (circle->x < circle->radius)
        {
            circle->direction_x = -1 * circle->direction_x;
        }
        circle->x = circle->x - circle->a_x;
    }
}

int main()
{
    // Objects
    struct Circle circle = (struct Circle){
        50, // x
        50, // y
        30, // radius
        G,  // a_x
        0,  // a_y
        1,  // Start descending
        1,  // Start moving to right
    };

    struct Circle trajectory[TRAJECTORY_LENGHT];

    // FLAGS
    int current_trajectory_index = 0;
    int simulation_running = 1;

    // Initialises Data
    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;
    SDL_Event event;
    SDL_Rect erase_rect = (SDL_Rect){0, 0, WIDTH, HEIGHT};

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

    /*
     Creates Window surface to be able to drawing pixels to the window's
     display memory using CPU
    */
    surface = SDL_GetWindowSurface(window);

    while (simulation_running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                simulation_running = 0;
            }
            if (event.type == SDL_KEYDOWN)
            {
                // If press Space bar
                if (event.key.keysym.sym == SDLK_SPACE)
                {
                    simulation_running = 0;
                }
            }
        }

        SDL_FillRect(surface, &erase_rect, COLOR_BRACKGROUND);

        // Create a cricle object
        FillCircle(surface, circle, COLOR_WHITE);
        // Create the ball trajectory
        FillTrajectory(surface, trajectory, current_trajectory_index,
                       COLOR_ORANGE);

        step(&circle);
        UpdateTrajectory(trajectory, circle, current_trajectory_index);

        ++current_trajectory_index;
        // if (current_trajectory_index < TRAJECTORY_LENGHT)
        // {
        // }

        // Update the Window surface
        SDL_UpdateWindowSurface(window);

        SDL_Delay(DELAY);
    }

    // Checks if window has been created; if not, exits program
    if (window == NULL)
    {
        fprintf(stderr, "Window failed to initialise: %s\n", SDL_GetError());
        return 1;
    }

    // Free memory - Close Window
    SDL_DestroyWindow(window);

    // Shuts down all SDL subsystems
    SDL_Quit();

    return 0;
}