#pragma once
#include "SDL++.h"
#include "Globals.h"
#include <SDL.h>
#include <string>
#include "Texture.h"

namespace SDL
{
  class Surface;
  class AnimatedSprite;

  class SDL_API Window
  {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Surface *screenSurface = NULL;

  public:
    Window(bool autoCreate = false);
    ~Window();

    void create();
    void fillRect(const SDL_Rect *rect, Uint32 r, Uint32 g, Uint32 b);
    void fillRect(Uint32 r, Uint32 g, Uint32 b);
    void blit(Surface *surface);
    void blitBMP(const std::string path);
    std::unique_ptr<Texture> loadBMP(const std::string path);
    void render(std::unique_ptr<Texture>& texture, SDL_Rect* frame = NULL, int x = 0, int y = 0, double angle = 0);
    void render(std::unique_ptr<AnimatedSprite>& sprite);
  };
}

