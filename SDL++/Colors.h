#pragma once
#include <SDL.h>

namespace SDL
{
  namespace Colors
  {
    Uint32 fromRGB(SDL_PixelFormat *format, Uint32 r, Uint32 g, Uint32 b)
    {
      return SDL_MapRGB(format, r, g, b);
    }
  }
}
