#include "App.h"
#include "Box.h"
#include <memory>
#include <algorithm>
#include "ChiliMath.h"
#include "Surface.h"
#include "GDIPlusManager.h"
#include "imgui/imgui.h"

GDIPlusManager dfipm;

namespace dx = DirectX;

App::App():
	wnd(800, 600, "Donkey Fart Box"),
	light(wnd.Gfx())
{ 
	class Factory {
	public:
		Factory(Graphics& gfx)
			:gfx(gfx)
		{}
		std::unique_ptr<Drawable> operator()()
		{
				return std::make_unique<Box>(
					gfx, rng, adist, ddist,
					odist, rdist, bdist
				);
		}

	private:
		Graphics& gfx;
		std::mt19937 rng{ std::random_device{}() };
		std::uniform_real_distribution<float> adist{ 0.0f, PI * 2.0f };
		std::uniform_real_distribution<float> ddist{ 0.0f, PI * 0.5f };
		std::uniform_real_distribution<float> odist{ 0.0f, PI * 0.08f };
		std::uniform_real_distribution<float> rdist{ 6.0f, 20.0f };
		std::uniform_real_distribution<float> bdist{ 0.4f,3.0f };

	};


	drawables.reserve(nDrawables);

	std::generate_n(std::back_inserter(drawables), nDrawables, Factory{ wnd.Gfx() });
	
	wnd.Gfx().SetProjection(DirectX::XMMatrixPerspectiveLH(1.0f, 3.0f / 4.0f, 0.5f, 40.0f));


}

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

App::~App()
{
}

void App::DoFrame()
{
	const auto dt = timer.Mark();


	wnd.Gfx().BeginFrame(0.07f, 0.0f, 0.12f);

	wnd.Gfx().SetCamera(cam.GetMatrix());
	
	light.Bind(wnd.Gfx());

	for (auto& d : drawables)
	{
		d->Update(wnd.kbd.KeyIsPressed(VK_SPACE) ? 0.0f : dt);
		d->Draw(wnd.Gfx());
	}

	light.Draw(wnd.Gfx());
	
	static char buffer[1024];

	//imgui window to control simulation speed
	if (ImGui::Begin("Simulation Speed")) {
		ImGui::SliderFloat("Speed Factor", &speed_factor, 0.0f, 4.0f);
		ImGui::Text(" %.3f ms/frame (%.1f FPS)", 1000.f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::Text("Status: %s", wnd.kbd.KeyIsPressed(VK_SPACE) ? "PAUSED" : "RUNNING(hold spacebar to pause)");
	}
	ImGui::End();

	//imgui window to control camera and light
	cam.SpawnControlWindow();
	light.SpawnControlWindow();


	//present
	wnd.Gfx().EndFrame();
}



