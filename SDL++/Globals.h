#pragma once
#include "SDL++.h"
#include <SDL.h>
#include <memory>
#include <string>

namespace SDL
{
  class Window;
  class AnimatedSprite;

  SDL_API void delay(Uint32 delay);
  
  SDL_API void quit();

  SDL_API std::unique_ptr<Window> createWindow();

  SDL_API std::unique_ptr<AnimatedSprite> createAnimatedSprite
  (
    const std::unique_ptr<Window>& window, 
    const std::string& texturePath, 
    const SDL_Point position = {}
  );
}