#include "stdafx.h"
#include "Game.h"
#include <random>
void Game::create(std::unique_ptr<Window>& window)
{
	for (int i = 0; i < 10; i++)
	{
		m_trees.push_back(createSprite(window, "Images\\tree.bmp"));
	}
	for (int i = 0; i < 4; i++)
	{
		m_enemies.push_back(createSprite(window, "Images\\bear.bmp"));
	}
	m_hero = SDL::createAnimatedSprite(window, "Images\\hero.bmp", { 0, 0 });
}


void Game::render(std::unique_ptr<Window>& window)
{
	window->render(m_hero);

	for (auto& i : m_trees)
	{
		window->render(i);
	}

	for (auto& i : m_enemies)
	{
		window->render(i);
	}
}

//template <typename Prob = double>
bool generateRandomBool()
{
	/*auto dev = std::random_device();
	auto gen = std::mt19937{ dev() };
	auto dist = std::uniform_real_distribution<Prob>(0, 1);
	return (dist(gen) < p);*/
	/*auto gen = std::bind(std::uniform_int_distribution<>(0, 1), std::default_random_engine());
	auto gerRes = gen();
	return gerRes;*/
	static const int shift = static_cast<int>(std::log2(RAND_MAX));
	return (rand() >> shift) & 1;
}

void Game::run(std::unique_ptr<SDL::Window>& window)
{
	//auto hero = SDL::createAnimatedSprite(window, "Images\\hero.bmp", { 0, 0 });
	bool quit = false;
	SDL::Input input;
	bool redraw = true;
	int speed = g_spriteSize;
	while (!quit)
	{
		input.update();
		if (input.isKeyDown(SDLK_LEFT))
		{
			moveSprite(m_hero.get(), -1 * speed, 0);
			redraw = true;
		}
		else if (input.isKeyDown(SDLK_RIGHT))
		{
			moveSprite(m_hero.get(), 1 * speed, 0);
			redraw = true;
		}
		else if (input.isKeyDown(SDLK_UP))
		{
			moveSprite(m_hero.get(), 0, -1 * speed);
			redraw = true;
		}
		else if (input.isKeyDown(SDLK_DOWN))
		{
			moveSprite(m_hero.get(), 0, 1 * speed);
			redraw = true;
		}
		else if (input.isKeyDown(SDLK_ESCAPE))
			quit = true;

		//TODO 
		//move enemies in a loop, rand by x=+/-1 or y=+-1
		if (redraw)
		{
			for (auto& enemy : m_enemies)
			{
				int deltaX = 0;
				int deltaY = 0;
				bool changeX = generateRandomBool();
				int  sign = 1;
				if (generateRandomBool())
					sign = -1;
				if (changeX)
				{
					deltaX = sign  * speed;
				}
				else
				{
					deltaY = sign * speed;
				}
				moveSprite(enemy.get(), deltaX, deltaY);
			}
		}
		

		if (redraw)
		{
			window->clear();
			
			this->render(window);
		}
		redraw = false;
		SDL::delay(10);
	}
}

bool isPositionSame(SDL_Point p1, SDL_Point p2)
{
	return p1.x == p2.x && p1.y == p2.y;
}

bool isSpriteAtPosition(std::vector<std::unique_ptr<AnimatedSprite>>& sprites, SDL_Point pos)
{
	for (int i = 0; i < sprites.size(); i++)
	{
		auto treePos = sprites[i]->position();
		if (isPositionSame(treePos, pos))
		{
			return true;
		}
	}
	return false;
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
	if (isSpriteAtPosition(m_trees, pos))
	    return;
	
	if (isSpriteAtPosition(m_enemies, pos))
		return;
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
	auto sprite = SDL::createAnimatedSprite(window, spriteImage, { g_spriteSize * dx, g_spriteSize * dy });
	return sprite;
}
