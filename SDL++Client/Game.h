
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
	/// <summary>
	/// 
	/// </summary>
	/// <param name="window"></param>
	/// <param name="spriteImage"></param>
	/// <returns></returns>
	std::unique_ptr<AnimatedSprite> createSprite(std::unique_ptr<Window>& window, std::string spriteImage);

	//std::unique_ptr<AnimatedSprite> drawSprites(numTrees);
	/// <summary>
	/// 
	/// </summary>
	void moveSprite(AnimatedSprite* sprite, int deltaX, int deltaY);

	void render(std::unique_ptr<Window>& window);
	
protected:
	

public:

	Game(std::unique_ptr<Window>& window)
	{
		create(window);
	}

	void run(std::unique_ptr<SDL::Window>& window);
};