#include "textureManager.h"
#include <iostream>

TextureManager::TextureManager() {}

TextureManager::~TextureManager() {
	SDL_DestroyTexture(texture);
}

void TextureManager::loadTexture(SDL_Renderer* renderer, const char* filename) {
	SDL_Surface* surface = SDL_LoadBMP(filename);
	//	TO-DO: Check that the file was properly loaded

	//	Get the format details
	const SDL_PixelFormatDetails* details = SDL_GetPixelFormatDetails(surface->format);
	//	Get the color palette, if there is one
	SDL_Palette* palette = SDL_GetSurfacePalette(surface);
	//	Map a particular RGB value to a 32-bit color key
	Uint32 colorKey = SDL_MapRGB(details, palette, 0, 0, 0);
	bool colorKeySuccess = SDL_SetSurfaceColorKey(surface, true, colorKey);
	if (!colorKeySuccess) {
		SDL_Log("Error: Transparent pixel unsuccessfully set\n");
	}

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_DestroySurface(surface);
	if (texture == nullptr) {
		SDL_Log("Texture creation failed");
	}
}

void TextureManager::loadTextureRotated(SDL_Renderer* renderer, const char* filename, float angle) {
	SDL_Surface* surface = SDL_LoadBMP(filename);
	surface = SDL_RotateSurface(surface, angle);
	//	TO-DO: Check that the file was properly loaded

	//	Get the format details
	const SDL_PixelFormatDetails* details = SDL_GetPixelFormatDetails(surface->format);
	//	Get the color palette, if there is one
	SDL_Palette* palette = SDL_GetSurfacePalette(surface);
	//	Map a particular RGB value to a 32-bit color key
	Uint32 colorKey = SDL_MapRGB(details, palette, 0, 0, 0);
	bool colorKeySuccess = SDL_SetSurfaceColorKey(surface, true, colorKey);
	if (!colorKeySuccess) {
		SDL_Log("Error: Transparent pixel unsuccessfully set\n");
	}

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_DestroySurface(surface);
	if (texture == nullptr) {
		SDL_Log("Texture creation failed");
	}
}

SDL_Texture* TextureManager::getTexture() {
	return texture;
}