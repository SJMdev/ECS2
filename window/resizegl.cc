#include "window.ih"

void Window::resizeGL(int width, int height)
{
	float aspectRatio = static_cast<float>(width) / static_cast<float>(height);
	
	d_projectionMatrix.toIdentity();	
	d_projectionMatrix.toPerspective(75, aspectRatio, 0,  -2.f);
	SDL_Log("projection matrix looks like: %s", d_projectionMatrix.toString().c_str());
	
} 