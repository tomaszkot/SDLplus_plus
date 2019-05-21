// SDL++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <Window.h>
#include <Surface.h>
#include <Texture.h>
#include <AnimatedSprite.h>

#undef main

int main()
{
  SDL::delay(500);
  auto window = SDL::createWindow();

  auto texture = window->loadBMP("Images\\home.bmp");
  window->render(texture);

  auto sprite = SDL::createAnimatedSprite(window, "Images\\idle2.bmp", { 0, texture->height() });
  for (int i = 0; i < 360; i++)
  {
    sprite->setAngle(i);
    window->render(sprite);
    SDL::delay(10);
  }
  
  //Wait two seconds
  SDL::delay(4000);
  SDL::quit();

  return 0;
}

