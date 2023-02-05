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

#undef main
using namespace SDL;
int width = 1920;// SDL::SCREEN_WIDTH;
int height = 1080;
const int spriteSize = 128;
//const int numTrees = 10;
//const int numEnemies = 4;
//std::unique_ptr<Window> window;


class Game
{
private:
	std::vector<std::unique_ptr<AnimatedSprite>> m_trees;
	std::vector<std::unique_ptr<AnimatedSprite>> enemies;

public:

	void create(std::unique_ptr<Window>& window)
	{
		for (int i = 0; i < 10; i++)
		{
			m_trees.push_back(createSprite(window, "Images\\tree.bmp"));
		}
		for (int i = 0; i < 4; i++)
		{
			enemies.push_back(createSprite(window, "Images\\bear.bmp"));
		}

	}

	void render(std::unique_ptr<Window>& window)
	{
		for (auto& i : m_trees)
		{
			window->render(i);
		}

		for (int i = 0; i < enemies.size(); i++)
		{
			window->render(enemies[i]);
		}
	}

	//std::unique_ptr<AnimatedSprite> drawSprites(numTrees);
	/// <summary>
	/// 
	/// </summary>
	void moveSprite(AnimatedSprite* sprite, int deltaX, int deltaY)
	{
		auto pos = sprite->position();
		auto newX = pos.x + deltaX;
		pos.x = newX;

		if (pos.x >= 1920)
		{
			return;
		}
		else if (pos.x < 0)
		{
			return;
		}
		pos.y += deltaY;
		if (pos.y > 1080)
		{
			return;
		}
		else if (pos.y < 0)
		{
			return;
		}
		for (int i = 0; i < m_trees.size(); i++)
		{
			auto treePos = m_trees[i]->position();
			if (treePos.x == pos.x && treePos.y == pos.y)
			{
				return;
			}

		}
		for (int i = 0; i < enemies.size(); i++)
		{
			auto enemyPos = enemies[i]->position();
			if (enemyPos.x == pos.x && enemyPos.y == pos.y)
			{
				return;
			}


		}
		//1) jak jest enemy to dac return

		sprite->setPosition(pos);


	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="window"></param>
	/// <param name="spriteImage"></param>
	/// <returns></returns>
	std::unique_ptr<AnimatedSprite> createSprite(std::unique_ptr<Window>& window, std::string spriteImage)
	{
		int a = 3;
		int ay = 1;
		int by = 10;
		int bx = 15;
		int dx = rand() % (bx - a) + a;
		int dy = rand() % (by - a) + ay;
		auto sprite = SDL::createAnimatedSprite(window, spriteImage, { spriteSize * dx,spriteSize * dy });
		return sprite;
	}

};



/// <summary>
/// 
/// 
/// </summary>
/// <returns></returns>
int main()
{

	auto window = SDL::createWindow();
	auto hero = SDL::createAnimatedSprite(window, "Images\\hero.bmp", { 0, 0 });
	Game game;
	game.create(window);
	//3
	//createSprites(trees, numTrees, &window,"Images\\tree.bmp");
	//createSprites(enemies, numEnemies, &window,"Images\\bear.bmp");
	
	
	bool quit = false;
	SDL::Input input;
	bool redraw = true;
	int speed = spriteSize;
	while (!quit)
	{
		input.update();
		if (input.isKeyDown(SDLK_LEFT))
		{
			game.moveSprite(hero.get(), -1 * speed, 0);
			redraw = true;
		}
		else if (input.isKeyDown(SDLK_RIGHT))
		{
			game.moveSprite(hero.get(), 1 * speed, 0);
			redraw = true;
		}
		else if (input.isKeyDown(SDLK_UP))
		{
			game.moveSprite(hero.get(), 0, -1 * speed);
			redraw = true;
		}
		else if (input.isKeyDown(SDLK_DOWN))
		{
			game.moveSprite(hero.get(), 0, 1 * speed);
			redraw = true;
		}
		else if (input.isKeyDown(SDLK_ESCAPE))
			quit = true;

		if (redraw)
		{
			window->clear();
			window->render(hero);
			
			//2
			//drawSprites(trees, numTrees);
			//drawSprites(enemies, numEnemies);
			
			game.render(window);
		}    
		redraw = false;
		SDL::delay(10);
	}  

	return 0;
}


