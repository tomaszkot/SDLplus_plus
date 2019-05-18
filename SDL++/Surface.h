#pragma once
#include "SDL++.h"
#include "Globals.h"
#include <SDL.h>
#include <string>

namespace SDL
{
  class Surface
  {
    SDL_Surface * surface = NULL;

  public:
    Surface();
    ~Surface();

    void loadBMP(std::string path);
    SDL_Surface *get() { return surface; }
  };
}
