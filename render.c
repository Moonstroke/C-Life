#include "render.h"

#include <SDL2/SDL_mouse.h>


void renderBoard(Board *const b, SDL_Renderer *const ren, const int d) {
	if(b->changed) {
		SDL_RenderClear(ren);
		const unsigned int w = b->w, h = b->h;
		unsigned int i, j;
		SDL_Rect r;
		for(j = 0; j < h; ++j) {
			for(i = 0; i < w; ++i) {
				const unsigned char c = getCell(b, i, j) ? 0 : 255;
				SDL_SetRenderDrawColor(ren, c, c, c, 255);
				r.x = d * i;
				r.y = d * j;
				r.w = d;
				r.h = d;
				SDL_RenderFillRect(ren, &r);
			}
		}
		SDL_RenderPresent(ren);
		b->changed = false;
	}
}

void getHoverCoord(const int d, int *const x, int *y) {
	SDL_GetMouseState(x, y);
	*x /= d;
	*y /= d;
}
