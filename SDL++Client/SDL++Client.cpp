// SDL++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <stdio.h>
#include <Window.h>
#include <Surface.h>
#include <Texture.h>
#include <AnimatedSprite.h>
#include "SDL++Client.h"
#include <Input.h>
#include "Game.h"

#undef main
using namespace SDL;
int width = 1920;// SDL::SCREEN_WIDTH;
int height = 1080;


/// <summary>
/// 
/// 
/// </summary>
/// <returns></returns>
int main()
{

	auto window = SDL::createWindow();
	Game game(window);
	game.run(window);

	return 0;
}




