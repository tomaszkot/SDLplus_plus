#include "stdafx.h"
#include "Window.h"
#include "Colors.h"

namespace SDL
{
  //Screen dimension constants
  const int SCREEN_WIDTH = 640;
  const int SCREEN_HEIGHT = 480;

  Window::Window(bool autoCreate /*= false*/)
  {
    if (autoCreate)
      create();
  }
  
  Window::~Window()
  {
    SDL_DestroyWindow(window);
  }

  void Window::create()
  {
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
      printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    }
    screenSurface = SDL_GetWindowSurface(window);
  }

  void Window::fillRect(Uint32 r, Uint32 g, Uint32 b)
  {
    fillRect(NULL, r, g, b);
  }

  void Window::fillRect(const SDL_Rect * rect, Uint32 r, Uint32 g, Uint32 b)
  {
    SDL_FillRect(screenSurface, rect, SDL::Colors::fromRGB(screenSurface->format, r, g, b));

    SDL_UpdateWindowSurface(window);
  }
}