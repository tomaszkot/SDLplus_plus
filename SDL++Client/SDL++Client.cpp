// SDL++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//#include <SDL.h>
#include <stdio.h>
#include "../SDL++/Window.h"

#undef main

int main()
{
  SDL::Window window(true);
  window.fillRect(255, 0, 0);
  //Wait two seconds
  SDL::delay(2000);
  SDL::quit();

  return 0;
}

