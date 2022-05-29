#pragma once

#ifdef AS_PLATFORM_WINDOWS

extern AStar::Application* AStar::CreateApplication();

int main(int argc, char** argv)
{
	// dont need new, already did in Sandbox
	auto app = AStar::CreateApplication();
	app->Run();
	delete app;
}
	
#endif