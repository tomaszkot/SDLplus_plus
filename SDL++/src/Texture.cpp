#include "stdafx.h"
#include "Texture.h"
#include "Surface.h"

namespace SDL
{
  Texture::Texture()
  {
  }

  void Texture::load(std::string path, SDL_Renderer *renderer)
  {
    Surface surface;
    surface.loadBMP(path);
    if (surface.get() == NULL)
    {
      printf("Unable to load image %s!", path.c_str());
    }
    else
    {
      texture = SDL_CreateTextureFromSurface(renderer, surface.get());
      SDL_QueryTexture(texture, NULL, NULL, &w, &h);
      int  k = 0;
     }
  }

  void Texture::render(SDL_Renderer *renderer)
  {
    render(0, 0, NULL, renderer);
  }

  void Texture::render(int x, int y, SDL_Rect* frame, SDL_Renderer *renderer)
  {
    SDL_Rect renderQuad = { x, y, w, h };

    //Set clip rendering dimensions
    if (frame != NULL)
    {
      renderQuad.w = frame->w;
      renderQuad.h = frame->h;
    }

    //Render to screen
    SDL_RenderCopy(renderer, texture, frame, &renderQuad);
    //SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
  }

  Texture::~Texture()
  {
  }
}
