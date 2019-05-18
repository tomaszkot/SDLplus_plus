#pragma once
#include "SDL++.h"
#include "Globals.h"
#include <SDL.h>

namespace SDL
{
  class SDL_API Window
  {
    SDL_Window* window = NULL;

    SDL_Surface* screenSurface = NULL;

  public:
    Window(bool autoCreate = false);
    ~Window();

    void create();
    void fillRect(const SDL_Rect * rect, Uint32 r, Uint32 g, Uint32 b);
    void fillRect(Uint32 r, Uint32 g, Uint32 b);
  };
}

