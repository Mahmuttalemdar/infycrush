#include <king/Application.h>

int main(int argc, char *argv[])
{
    // get main application instance & start it
    King::Application* app = King::Application::GetInstance();
    return app->Execute(argc, argv);
}
