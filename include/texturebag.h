#ifndef TEXTURE_BAG_H
#define TEXTURE_BAG_H

#include <SDL3\SDL.h>
#include "texturemanager.h"

struct TextureBag {
	TextureManager upArrow;
	TextureManager upArrowHovered;
	TextureManager downArrow;
	TextureManager downArrowHovered;
	TextureManager pause;
	TextureManager pauseHovered;
	TextureManager play;
	TextureManager playHovered;
	TextureManager rewind;
	TextureManager rewindHovered;
	TextureManager ffw;
	TextureManager ffwHovered;
};

#endif