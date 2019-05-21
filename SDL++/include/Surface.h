#pragma once
#include "SDL++.h"
#include "Globals.h"
#include <SDL.h>
#include <string>

namespace SDL
{
  class SDL_API Surface
  {
    SDL_Surface * surface = NULL;

  public:
    Surface(std::string path = "");
    ~Surface();

    void loadBMP(std::string path);
    SDL_Surface *get() { return surface; }
  };
}
