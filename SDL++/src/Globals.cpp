#include "stdafx.h"
#include "Globals.h"
#include "Window.h"
#include "AnimatedSprite.h"

namespace SDL
{
  inline void delay(Uint32 delay)
  {
    SDL_Delay(delay);
  }

  inline void quit()
  {
    SDL_Quit();
  }

  std::unique_ptr<Window> createWindow()
  {
    return std::make_unique<Window>(true);
  }

  std::unique_ptr<AnimatedSprite> createAnimatedSprite
  (
    const std::unique_ptr<Window>& window,
    const std::string& texturePath,
    const SDL_Point position /*= {}*/
  )
  {
    auto sprite = std::make_unique<AnimatedSprite>(window->loadBMP(texturePath), position);
    return std::move(sprite);
  }
}