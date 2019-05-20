#include "stdafx.h"
#include "Globals.h"
#include "Window.h"

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
}