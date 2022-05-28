#pragma once

#include "Macros.h"

namespace AStar 
{
	class ASTAR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// defined in client (game)
	Application* CreateApplication();

}

