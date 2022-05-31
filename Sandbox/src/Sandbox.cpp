#include <AStar.h>

class Sandbox : public AStar::Application
{
public:
	Sandbox()
	{
		std::cout << "Welcome to AStar Engine" << std::endl;
	}

	~Sandbox()
	{

	}
};

// Creates the game
AStar::Application* AStar::CreateApplication()
{
	return new Sandbox();
}