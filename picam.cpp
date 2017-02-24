#include <stdio.h>
#include <unistd.h>
#include "camera.h"
#include "graphics.h"

void CameraCallback(CCamera* cam, const void* buffer, int buffer_length)
{
	//printf("Do stuff with %d bytes of data\n",buffer_length);
	WriteToRandomBuffer(buffer,buffer_length);
}

int main(int argc, const char **argv)
{
	printf("PI Cam api tester\n");
	InitGraphics();
	printf("Starting camera\n");
	StartCamera(1280,720,30,CameraCallback);

	printf("Running frame loop\n");
	for(int i = 0; i < 3000; i++)
	{
		BeginFrame();
		DrawWhiteRect(-0.9f,-0.9f,0.9f,0.9f);
		EndFrame();
	}

	StopCamera();
}
