#pragma once
#include "SDL++.h"
#include "Globals.h"
#include <SDL.h>
#include <string>

namespace SDL
{
  class SDL_API Surface
  {
    SDL_Surface * surface = nullptr;

  public:
    Surface(const std::string& path = "");
    ~Surface();

    void loadBMP(const std::string& path);
    SDL_Surface *get() const { return surface; }
  };
}
