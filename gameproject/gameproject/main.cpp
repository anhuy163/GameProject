#include "stdafx.h"
#include <SDL.h>
#include <SDL_image.h>
#include "BaseObject.h"
 
 
BaseObject g_background;

bool InitData()
{
	bool success = true;
	int ret = SDL_Init(SDL_INIT_VIDEO);
	if (ret<0)
		return false;
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	g_window = SDL_CreateWindow("GameCuaAnHuy", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if(g_window == NULL)
	{
		success = false;
	}
	else
	{
		g_screen =SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
		if(g_screen == NULL)
		{
			success =false;
		}
		else
		{
			SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
			int imgFlags = IMG_INIT_PNG;
			if(!(IMG_Init(imgFlags)&& imgFlags))
				success = false;
		}
	}
	return success;
	
}
void close()
{
	g_background.Free();

	SDL_DestroyRenderer(g_screen);
	g_screen=NULL;

	SDL_DestroyWindow(g_window);
	g_window=NULL;

	IMG_Quit;
	SDL_QUIT;
}

bool LoadBG()
{
	bool ret = g_background.LoadIMG("bg.png", g_screen);
	if (ret == NULL)
		return false;
	else
		return true;
}

int main(int arc, char*argv[])
{
	if(InitData() == false)
		return -1;
	if(LoadBG() == false)
		return -1;

	bool inquit = false;
	while(!inquit)
	{
		while(SDL_PollEvent(&g_event)!=0)
		{
			if(g_event.type == SDL_QUIT)
			{
				inquit = true;
			}
		}
		SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
		SDL_RenderClear(g_screen);

		g_background.Render(g_screen, NULL);

		SDL_RenderPresent(g_screen);

	}
	close();
	return 0;
}