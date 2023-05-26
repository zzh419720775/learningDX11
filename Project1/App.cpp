#include "App.h"
#include <sstream>
#include <iomanip>

App::App():
	wnd(800, 600, "Donkey Fart Box")
{ }

int App::Go()
{
	while (true) {
		// process all messages pending, but to not block for new messages
		if (const auto ecode = Window::ProcessMessages())
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame()
{
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().ClearBuffer(c, c, 1.f);
	wnd.Gfx().EndFrame();
	//test code 
	//const float t = timer.Peek();
	//std::ostringstream oss;
	//oss << "Time elapsed: " << std::setprecision(1) << std::fixed << t << "s";
	//wnd.SetTitle(oss.str());
}