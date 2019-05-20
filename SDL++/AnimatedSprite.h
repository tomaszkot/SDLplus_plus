#pragma once
#include "SDL++.h"
#include <SDL.h>
#include <string>

namespace SDL
{
  class Texture;

  class SDL_API AnimatedSprite
  {
    std::unique_ptr<Texture> m_texture;
    int m_frameSize = 0;
    int m_framesCount = 0;
    int m_frameTime = 60;//[ms]
    SDL_Point m_position;

  public:
    AnimatedSprite(std::unique_ptr<Texture>&& texture, const SDL_Point position = {});
    ~AnimatedSprite();

    int frameSize() { return m_frameSize; }
    int framesCount() { return m_framesCount; }
    int frameTime() { return m_frameTime; }
    SDL_Point position() { return m_position; }

    std::unique_ptr<Texture>& texture() { return m_texture; }
  };

}
