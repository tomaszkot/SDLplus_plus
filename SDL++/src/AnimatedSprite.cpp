#include "stdafx.h"
#include "AnimatedSprite.h"
#include "Texture.h"
#include <iostream>

namespace SDL
{
  AnimatedSprite::AnimatedSprite(std::unique_ptr<Texture>&& texture, const SDL_Point position /*= {}*/,
    double angle /*= 0*/)
  {
    m_texture = std::move(texture);
    m_frameSize = m_texture->height();
    _ASSERT(m_texture->width() % m_frameSize == 0);
    m_framesCount = m_texture->width() / m_frameSize;
    m_position = position;
    m_angle = angle;
    frameStartTime = SDL_GetTicks();
  }
  
  AnimatedSprite::~AnimatedSprite()
  {
  }

  void AnimatedSprite::update()
  {
    auto now = SDL_GetTicks();
    auto diff = now - frameStartTime;
    if (diff > m_frameTime)
    {
      std::cout << "m_currentFrameIndex = " << m_currentFrameIndex << std::endl;
      m_currentFrameIndex++;
      frameStartTime = now;
      if (m_currentFrameIndex >= m_framesCount)
        m_currentFrameIndex = 0;
    }
  }
}