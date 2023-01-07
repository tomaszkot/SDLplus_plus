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
using namespace SDL;
/// <summary>
/// 
/// </summary>
void moveSprite(AnimatedSprite* sprite, int deltaX, int deltaY)
{
	auto pos = sprite->position();
	pos.x += deltaX;
	pos.y += deltaY;
	sprite->setPosition(pos);


}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
int main()
{

	auto window = SDL::createWindow();
	auto sprite = SDL::createAnimatedSprite(window, "Images\\hero.bmp", { 0, 0 });

	

	bool quit = false;
	SDL::Input input;
	bool redraw = true;
	int speed = 128;
	while (!quit)
	{
		input.update();
		if (input.isKeyDown(SDLK_LEFT))
		{
			moveSprite(sprite.get(), -1*speed, 0);
			redraw = true;
		}
		else if (input.isKeyDown(SDLK_RIGHT))
		{
			moveSprite(sprite.get(), 1 * speed, 0);
			redraw = true;
		}
		else if (input.isKeyDown(SDLK_UP))
		{
			moveSprite(sprite.get(), 0, -1 * speed);
			redraw = true;
		}
		else if (input.isKeyDown(SDLK_DOWN))
		{
			moveSprite(sprite.get(), 0, 1 * speed);
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


