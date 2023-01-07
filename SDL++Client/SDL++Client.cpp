// SDL++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <Window.h>
#include <Surface.h>
#include <Texture.h>
#include <AnimatedSprite.h>
#include "SDL++Client.h"
#include <Input.h>

#undef main


int main()
{

  auto window = SDL::createWindow();
  auto sprite = SDL::createAnimatedSprite(window, "Images\\hero.bmp", { 0, 0 });
  
  bool quit = false;
  SDL::Input input;
  bool redraw = true;
  while (!quit)
  {
    input.update();
    if (input.isKeyDown(SDLK_LEFT))
    {
      auto pos = sprite->position();
      pos.x -= 5;
      sprite->setPosition(pos);
      
      redraw = true;
    }
    else if (input.isKeyDown(SDLK_RIGHT))
    {
      auto pos = sprite->position();
      pos.x += 5;
      sprite->setPosition(pos);

      redraw = true;
    }

    else if (input.isKeyDown(SDLK_ESCAPE))
      quit = true;

    if (redraw)
    {
      window->render(sprite);

    }
    redraw = false;
    SDL::delay(10);
  }

  return 0;
}


