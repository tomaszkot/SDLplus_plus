#pragma once
#include <SDL++.h>
#include <SDL.h>
#include <memory>
#include <string>

namespace SDL
{
  class Texture;

  class SDL_API AnimatedSprite
  {
    std::unique_ptr<Texture> m_texture;
    int m_frameSize = 0;
    int m_framesCount = 0;
    Uint32 m_frameTime = 60;//[ms]
    int m_currentFrameIndex = 0;
    double m_angle = 0;
    SDL_Point m_position;
    Uint32 frameStartTime = 0; //SDL_GetTicks();

  public:
    AnimatedSprite(std::unique_ptr<Texture>&& texture, const SDL_Point position = {}, double angle = 0);
    ~AnimatedSprite();

    int frameSize() { return m_frameSize; }
    int framesCount() { return m_framesCount; }
    int frameTime() { return m_frameTime; }
    SDL_Point position() { return m_position; }
    void setPosition(SDL_Point& position) { m_position = position; };

    double angle() { return m_angle; }
    void setAngle(double angle) { m_angle = angle; };
    void update();

    std::unique_ptr<Texture>& texture() { return m_texture; }
    int currentFrameIndex() { return m_currentFrameIndex; }
  };

}
