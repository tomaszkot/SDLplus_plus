#include "stdafx.h"
#include "Window.h"
#include "Colors.h"
#include "Surface.h"
#include "AnimatedSprite.h"

namespace SDL
{
  //default screen dimension constants
  const int SCREEN_WIDTH = 1920;
  const int SCREEN_HEIGHT = 1080;

  Window::Window(bool autoCreate /*= false*/)
  {
    if (autoCreate)
      create();
  }

  Window::~Window()
  {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    
  }

  void Window::create()
  {
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
      printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
      screenSurface = SDL_GetWindowSurface(window);
      renderer = SDL_CreateRenderer(window, -1, 0);
    }
        
  }

  void Window::fillRect(Uint32 r, Uint32 g, Uint32 b)
  {
    fillRect(NULL, r, g, b);
  }

  void Window::fillRect(const SDL_Rect *rect, Uint32 r, Uint32 g, Uint32 b)
  {
    SDL_FillRect(screenSurface, rect, SDL::Colors::fromRGB(screenSurface->format, r, g, b));

    SDL_UpdateWindowSurface(window);
  }

  void Window::blit(const Surface *surface)
  {
    //Apply the image
    SDL_BlitSurface(surface->get(), NULL, screenSurface, NULL);
    SDL_UpdateWindowSurface(window);
  }

  void Window::blitBMP(const std::string& path)
  {
    Surface surface;
    surface.loadBMP(path);
    blit(&surface);
  }

  std::unique_ptr<Texture> Window::loadBMP(const std::string& path)
  {
    auto txt = std::make_unique<Texture>();
    txt->load(path, renderer);

    return txt;
  }

  void Window::render(const std::unique_ptr<Texture>& texture, SDL_Rect* frame /*= NULL*/,
    int x /*= 0*/, int y/* = 0*/, double angle/* = 0*/)
  {
    texture->render(x, y, frame, renderer, angle);
    //SDL_UpdateWindowSurface(window);
  }

  void Window::clear()
  {
      SDL_RenderClear(renderer);
  }

  void Window::render(const std::unique_ptr<AnimatedSprite>& sprite)
  {
    
    sprite->update();
    auto frameSize = sprite->frameSize();
    SDL_Rect frame{ sprite->currentFrameIndex() *frameSize, 0, frameSize, frameSize };
    render(sprite->texture(), &frame, sprite->position().x, sprite->position().y, sprite->angle());
  }
}