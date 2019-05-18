// SDL++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <SDL.h>
#include <stdio.h>
#include "Window.h"

#undef main

int main()
{
  SDL::Window window(true);
  window.fillRect(255, 0, 0);
  //Wait two seconds
  SDL_Delay(2000);
  SDL_Quit();

  return 0;
}

