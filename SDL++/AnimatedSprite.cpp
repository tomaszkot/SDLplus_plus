#include "stdafx.h"
#include "AnimatedSprite.h"
#include "Texture.h"

namespace SDL
{
  AnimatedSprite::AnimatedSprite(std::unique_ptr<Texture>&& texture, SDL_Point* position /*= NULL*/)
    //m_texture(texture)
  {
    m_texture = std::move(texture);
    m_frameSize = m_texture->height();
    _ASSERT(m_texture->width() % m_frameSize == 0);
    m_framesCount = m_texture->width() / m_frameSize;
    m_position = { 0, 0 };
    if (position)
      m_position = *position;
  }


  AnimatedSprite::~AnimatedSprite()
  {
  }
}