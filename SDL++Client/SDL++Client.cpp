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
int width = 1920;// SDL::SCREEN_WIDTH;
int height = 1080;
/// <summary>
/// 
/// </summary>
void moveSprite(AnimatedSprite* sprite, int deltaX, int deltaY)
{
	auto pos = sprite->position();
	auto newX = pos.x + deltaX;
	pos.x = newX;
	//if (pos.x >1080)
	//{
//		break;
	//}
	//	pos.x = newX;

	if (pos.x > 1920)
	{
		exit(0);
	}
	else if (pos.x < 0)
	{
		exit(0);
	}
	pos.y += deltaY;
	if (pos.y > 1080)
	{
		exit(0);
	}
	else if (pos.y < 0)
	{
		exit(0);
	}
	sprite->setPosition(pos);


}
std::unique_ptr<AnimatedSprite> createTree()
{
	return 0;
}



/// <summary>
/// 
/// </summary>
/// <returns></returns>
int main()
{

	auto window = SDL::createWindow();
	auto hero = SDL::createAnimatedSprite(window, "Images\\hero.bmp", { 0, 0 });
	auto bear = SDL::createAnimatedSprite(window, "Images\\bear.bmp", { 128, 1 });
	int t[10] = { 1,2 };
	std::unique_ptr<AnimatedSprite> trees[10];
	
	for (int i = 0; i < 10; i++)
	{
		//int randomNumberX = rand();
		int a = 3;
		int ay = 1;
		int by = 10;
		int bx = 15;
		int dx = rand() % (bx - a) + a;
		int dy = rand() % (by - a) + ay;
		trees[i] = SDL::createAnimatedSprite(window, "Images\\tree.bmp", { 128 *  dx,128* dy });
	}

	bool quit = false;
	SDL::Input input;
	bool redraw = true;
	int speed = 128;
	while (!quit)
	{
		input.update();
		if (input.isKeyDown(SDLK_LEFT))
		{
			moveSprite(hero.get(), -1 * speed, 0);
			redraw = true;
		}
		else if (input.isKeyDown(SDLK_RIGHT))
		{
			moveSprite(hero.get(), 1 * speed, 0);
			redraw = true;
		}
		else if (input.isKeyDown(SDLK_UP))
		{
			moveSprite(hero.get(), 0, -1 * speed);
			redraw = true;
		}
		else if (input.isKeyDown(SDLK_DOWN))
		{
			moveSprite(hero.get(), 0, 1 * speed);
			redraw = true;
		}
		else if (input.isKeyDown(SDLK_ESCAPE))
			quit = true;

		if (redraw)
		{
			window->clear();
			window->render(hero);
			window->render(bear);
			for (int i = 0; i < 10; i++)
			{
				window->render(trees[i]);
			}
		}
		redraw = false;
		SDL::delay(10);
	}

	return 0;
}


