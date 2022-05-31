#pragma once

#ifdef AS_PLATFORM_WINDOWS

// declares function from external class so this file can use it.
extern AStar::Application* AStar::CreateApplication();

// main function which is in engine
int main(int argc, char** argv)
{
	AStar::Log::Init();
	AS_CORE_WARN("Initialized Log!");
	AS_INFO("Hello");

	// dont need new, already did in Sandbox
	auto app = AStar::CreateApplication();
	app->Run();
	delete app;
}
	
#endif