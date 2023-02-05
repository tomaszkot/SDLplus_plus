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