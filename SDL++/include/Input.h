#pragma once
#include <SDL++.h>
#include <SDL.h>
#include <functional>
#include <set>

namespace SDL
{
  class SDL_API Input
  {
    std::set<SDL_Keycode> m_codes;

  public:

    bool isKeyDown(SDL_Keycode key);
    void update();

  };
}
