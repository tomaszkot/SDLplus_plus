#pragma once
#include <SDL.h>

namespace SDL
{
  class Window
  {
    SDL_Window* window = NULL;

    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

  public:
    Window(bool autoCreate = false);
    ~Window();

    void create();
    void fillRect(const SDL_Rect * rect, Uint32 r, Uint32 g, Uint32 b);
    void fillRect(Uint32 r, Uint32 g, Uint32 b);
  };
}

