#pragma once

#ifdef DCTHCT_PLATFORM_WINDOWS

extern Decathect::Application* Decathect::CreateApp();

int main(int argc, char** argv)
{ 
	/* -- Testing the Engine/Client side logging -- */
	Decathect::Log::Init();
	DCTHCT_CORE_WARN("Initialised Log!");	
	int a = 5;
	DCTHCT_INFO("int a = {0}", a);
	/* -------------------------------------------- */

	auto app = Decathect::CreateApp();
	app->Run();
	delete app;
}

#endif