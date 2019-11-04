#include <Decathect.h>

class Sandbox : public Decathect::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Decathect::Application* Decathect::CreateApp()
{
	return new Sandbox();
}

