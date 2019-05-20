#pragma once
#include "SDL++.h"
#include <SDL.h>
#include <memory>

namespace SDL
{
  class Window;

  SDL_API void delay(Uint32 delay);
  
  SDL_API void quit();

  SDL_API std::unique_ptr<Window> createWindow();
}