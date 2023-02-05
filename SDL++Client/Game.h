
#include <vector>
#include <stdio.h>
#include <Window.h>
#include <Surface.h>
#include <Texture.h>
#include <AnimatedSprite.h>
#include "SDL++Client.h"
#include <Input.h>
using namespace SDL;
const int spriteSize = 128;

class Game
{
private:
	std::vector<std::unique_ptr<AnimatedSprite>> m_trees;
	std::vector<std::unique_ptr<AnimatedSprite>> enemies;
	std::unique_ptr<AnimatedSprite> hero;

	void create(std::unique_ptr<Window>& window);

public:

	Game(std::unique_ptr<Window>& window)
	{
		create(window);
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

	void run(std::unique_ptr<SDL::Window>& window)
	{
		//auto hero = SDL::createAnimatedSprite(window, "Images\\hero.bmp", { 0, 0 });
		bool quit = false;
		SDL::Input input;
		bool redraw = true;
		int speed = spriteSize;
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

				//2
				//drawSprites(trees, numTrees);
				//drawSprites(enemies, numEnemies);

				render(window);
			}
			redraw = false;
			SDL::delay(10);
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