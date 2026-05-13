#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL3/SDL.h>

class TextureManager {
public:
	TextureManager();

	~TextureManager();

	void loadTexture(SDL_Renderer* renderer, const char* filename);
	void loadTextureRotated(SDL_Renderer* renderer, const char* filename, float angle);

	SDL_Texture* getTexture();
private:
	SDL_Texture* texture = nullptr;
};

#endif