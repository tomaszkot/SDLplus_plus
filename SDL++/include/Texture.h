#pragma once
#include "SDL++.h"
#include <SDL.h>
#include <string>

namespace SDL
{
  class SDL_API Texture
  {
    SDL_Texture* texture = NULL;
    
    int w;
    int h;
    

  public:
    Texture();
    ~Texture();

    void load(std::string path, SDL_Renderer *renderer);
    void render(int x, int y, SDL_Rect* frame, SDL_Renderer *renderer, double angle = 0);
    void render(SDL_Renderer *renderer);

    SDL_Texture* get() 
    {
      return texture;
    }
    int width() { return w; }
    int height() { return h; }
  };
}
