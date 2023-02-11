#include "stdafx.h"
#include "Game.h"

void Game::create(std::unique_ptr<Window>& window)
{
	for (int i = 0; i < 10; i++)
	{
		m_trees.push_back(createSprite(window, "Images\\tree.bmp"));
	}
	for (int i = 0; i < 4; i++)
	{
		enemies.push_back(createSprite(window, "Images\\bear.bmp"));
	}
	hero = SDL::createAnimatedSprite(window, "Images\\hero.bmp", { 0, 0 });
}

void Game::render(std::unique_ptr<Window>& window)
{
	for (auto& i : m_trees)
	{
		window->render(i);
	}

	for (auto& i : enemies)
	{
		window->render(i);
	}
}

void Game::run(std::unique_ptr<SDL::Window>& window)
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

		//TODO 
		// move functions to cpp file
		// wrte short loop[s
		//move enemies in a loop, rand by x=+/-1 or y=+-1

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

void Game::moveSprite(AnimatedSprite* sprite, int deltaX, int deltaY)
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

std::unique_ptr<AnimatedSprite> Game::createSprite(std::unique_ptr<Window>& window, std::string spriteImage)
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
