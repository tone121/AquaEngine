#include <stdlib.h>
#include <iostream>
#include <graphics/Graphics.h>

using namespace std;

int main(int argv, char** args)
{
	(void)argv;
	(void)args;

	Display display(800, 600, "AquaGL");
	Graphics graphics(display);
	
	Shader shader("./resources/shaders/primitives/vert_quad.glsl", "./resources/shaders/primitives/frag_quad.glsl");

	while(!display.Close) {
		display.Update();
		graphics.Clear(0.1, 0.1, 0.1);
	}

	return 0;
}
