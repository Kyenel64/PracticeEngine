#include <AStar.h>

class Sandbox : public AStar::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

AStar::Application* AStar::CreateApplication()
{
	return new Sandbox();
}