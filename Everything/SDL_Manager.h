#pragma once

#include "SDL.h"

class SDL_Manager {
private:
public:
	SDL_Manager(void);
	~SDL_Manager(void);
};

#define SDL_MANAGER Singleton<SDL_Manager>::instance()