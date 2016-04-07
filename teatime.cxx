#include <SDL2/SDL.h> 
#include <stdio.h> 

SDL_Window* gWindow = NULL; 
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gTeaTime= NULL;

SDL_Event e;
bool quit=false;

#define SCREEN_WIDTH 574
#define SCREEN_HEIGHT 800

bool init() 
{
	bool success = true; 

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) 
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() ); 
		success = false;
	} 
	else 
	{
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN ); 
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() ); 
			success = false;
		}
		else
		{
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
	}
	
	return success;
}

bool loadMedia()
{
	bool success = true; 
	gTeaTime = SDL_LoadBMP( "alarm.bmp" ); 

	if( gTeaTime == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "alarm.bmp", SDL_GetError() ); 
		success = false;
	}
	
	return success; 
}

void close()
{
	SDL_FreeSurface( gTeaTime ); 
	gTeaTime = NULL; 

	SDL_DestroyWindow( gWindow ); 
	gWindow = NULL;
}

int main(int argc, char* argv[])
{
	SDL_Delay( 2000 );

	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{

		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			SDL_BlitSurface( gTeaTime, NULL, gScreenSurface, NULL );
			
			SDL_UpdateWindowSurface( gWindow );

			while( !quit )
			{
				while( SDL_PollEvent( &e ) != 0 )
				{
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					else
					{
						SDL_UpdateWindowSurface( gWindow );
					}
				}
			}
		}
	}

	close();
	
	return 0;
}
