#include "stdafx.h"
#include "Globals.h"

namespace SDL
{
  inline void delay(Uint32 delay)
  {
    SDL_Delay(delay);
  }

  inline void quit()
  {
    //SDL_Quit();
  }
}