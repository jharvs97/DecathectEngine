#pragma once

#ifdef DCTHCT_PLATFORM_WINDOWS

extern Decathect::Application* Decathect::CreateApp();

int main(int argc, char** argv)
{ 
	Decathect::Log::Init();

	auto app = Decathect::CreateApp();
	app->Run();
	delete app;
}

#endif