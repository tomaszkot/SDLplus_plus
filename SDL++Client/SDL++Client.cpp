// SDL++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include "../SDL++/Window.h"
#include "../SDL++/Surface.h"
#include "../SDL++/Texture.h"
#include "../SDL++/AnimatedSprite.h"

#undef main

int main()
{
  SDL::delay(500);
  auto window = SDL::createWindow();

  auto texture = window->loadBMP("Images\\home.bmp");
  window->render(texture);

  window->render(SDL::createAnimatedSprite(window, "Images\\idle2.bmp", { 0, texture->height() }));
  
  //Wait two seconds
  SDL::delay(4000);
  SDL::quit();

  return 0;
}

