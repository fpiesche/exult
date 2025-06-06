/*
 *  Copyright (C) 2009-2022 Exult Team
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the
 *  Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 *  Boston, MA  02111-1307, USA.
 */

#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include "scale_bilinear.h"

#include "common_types.h"
#include "imagewin.h"
#include "manip.h"

#include <cstring>

//
// 2x Bilinear Filtering
//
void Image_window::show_scaled8to16_bilinear(
		int x, int y, int w, int h    // Area to show.
) {
	increase_area(x, y, w, h, 1, 1, 1, 1, ibuf->width, ibuf->height);

	const SDL_PixelFormatDetails* inter_surface_format
			= SDL_GetPixelFormatDetails(inter_surface->format);
	SDL_Palette* paletted_surface_palette
			= SDL_GetSurfacePalette(paletted_surface);
	const Manip8to16 manip(
			paletted_surface_palette->colors, inter_surface_format);
	Scale_2xBilinear<unsigned char, uint16, Manip8to16>(
			static_cast<uint8*>(draw_surface->pixels), x + guard_band,
			y + guard_band, w, h, ibuf->line_width, ibuf->height + guard_band,
			static_cast<uint16*>(inter_surface->pixels),
			inter_surface->pitch / inter_surface_format->bytes_per_pixel,
			manip);
}

void Image_window::show_scaled8to555_bilinear(
		int x, int y, int w, int h    // Area to show.
) {
	increase_area(x, y, w, h, 1, 1, 1, 1, ibuf->width, ibuf->height);

	const SDL_PixelFormatDetails* inter_surface_format
			= SDL_GetPixelFormatDetails(inter_surface->format);
	SDL_Palette* paletted_surface_palette
			= SDL_GetSurfacePalette(paletted_surface);
	const Manip8to555 manip(
			paletted_surface_palette->colors, inter_surface_format);
	Scale_2xBilinear<unsigned char, uint16, Manip8to555>(
			static_cast<uint8*>(draw_surface->pixels), x + guard_band,
			y + guard_band, w, h, ibuf->line_width, ibuf->height + guard_band,
			static_cast<uint16*>(inter_surface->pixels),
			inter_surface->pitch / inter_surface_format->bytes_per_pixel,
			manip);
}

void Image_window::show_scaled8to565_bilinear(
		int x, int y, int w, int h    // Area to show.
) {
	increase_area(x, y, w, h, 1, 1, 1, 1, ibuf->width, ibuf->height);

	const SDL_PixelFormatDetails* inter_surface_format
			= SDL_GetPixelFormatDetails(inter_surface->format);
	SDL_Palette* paletted_surface_palette
			= SDL_GetSurfacePalette(paletted_surface);
	const Manip8to565 manip(
			paletted_surface_palette->colors, inter_surface_format);
	Scale_2xBilinear<unsigned char, uint16, Manip8to565>(
			static_cast<uint8*>(draw_surface->pixels), x + guard_band,
			y + guard_band, w, h, ibuf->line_width, ibuf->height + guard_band,
			static_cast<uint16*>(inter_surface->pixels),
			inter_surface->pitch / inter_surface_format->bytes_per_pixel,
			manip);
}

void Image_window::show_scaled8to32_bilinear(
		int x, int y, int w, int h    // Area to show.
) {
	increase_area(x, y, w, h, 1, 1, 1, 1, ibuf->width, ibuf->height);

	const SDL_PixelFormatDetails* inter_surface_format
			= SDL_GetPixelFormatDetails(inter_surface->format);
	SDL_Palette* paletted_surface_palette
			= SDL_GetSurfacePalette(paletted_surface);
	const Manip8to32 manip(
			paletted_surface_palette->colors, inter_surface_format);
	Scale_2xBilinear<unsigned char, uint32, Manip8to32>(
			static_cast<uint8*>(draw_surface->pixels), x + guard_band,
			y + guard_band, w, h, ibuf->line_width, ibuf->height + guard_band,
			static_cast<uint32*>(inter_surface->pixels),
			inter_surface->pitch / inter_surface_format->bytes_per_pixel,
			manip);
}

//
// 2x Bilinear Plus Filtering
//
void Image_window::show_scaled8to16_BilinearPlus(
		int x, int y, int w, int h    // Area to show.
) {
	increase_area(x, y, w, h, 1, 1, 1, 1, ibuf->width, ibuf->height);

	const SDL_PixelFormatDetails* inter_surface_format
			= SDL_GetPixelFormatDetails(inter_surface->format);
	SDL_Palette* paletted_surface_palette
			= SDL_GetSurfacePalette(paletted_surface);
	const Manip8to16 manip(
			paletted_surface_palette->colors, inter_surface_format);
	Scale_2xBilinearPlus<unsigned char, uint16, Manip8to16>(
			static_cast<uint8*>(draw_surface->pixels), x + guard_band,
			y + guard_band, w, h, ibuf->line_width, ibuf->height + guard_band,
			static_cast<uint16*>(inter_surface->pixels),
			inter_surface->pitch / inter_surface_format->bytes_per_pixel,
			manip);
}

void Image_window::show_scaled8to555_BilinearPlus(
		int x, int y, int w, int h    // Area to show.
) {
	increase_area(x, y, w, h, 1, 1, 1, 1, ibuf->width, ibuf->height);

	const SDL_PixelFormatDetails* inter_surface_format
			= SDL_GetPixelFormatDetails(inter_surface->format);
	SDL_Palette* paletted_surface_palette
			= SDL_GetSurfacePalette(paletted_surface);
	const Manip8to555 manip(
			paletted_surface_palette->colors, inter_surface_format);
	Scale_2xBilinearPlus<unsigned char, uint16, Manip8to555>(
			static_cast<uint8*>(draw_surface->pixels), x + guard_band,
			y + guard_band, w, h, ibuf->line_width, ibuf->height + guard_band,
			static_cast<uint16*>(inter_surface->pixels),
			inter_surface->pitch / inter_surface_format->bytes_per_pixel,
			manip);
}

void Image_window::show_scaled8to565_BilinearPlus(
		int x, int y, int w, int h    // Area to show.
) {
	increase_area(x, y, w, h, 1, 1, 1, 1, ibuf->width, ibuf->height);

	const SDL_PixelFormatDetails* inter_surface_format
			= SDL_GetPixelFormatDetails(inter_surface->format);
	SDL_Palette* paletted_surface_palette
			= SDL_GetSurfacePalette(paletted_surface);
	const Manip8to565 manip(
			paletted_surface_palette->colors, inter_surface_format);
	Scale_2xBilinearPlus<unsigned char, uint16, Manip8to565>(
			static_cast<uint8*>(draw_surface->pixels), x + guard_band,
			y + guard_band, w, h, ibuf->line_width, ibuf->height + guard_band,
			static_cast<uint16*>(inter_surface->pixels),
			inter_surface->pitch / inter_surface_format->bytes_per_pixel,
			manip);
}

void Image_window::show_scaled8to32_BilinearPlus(
		int x, int y, int w, int h    // Area to show.
) {
	increase_area(x, y, w, h, 1, 1, 1, 1, ibuf->width, ibuf->height);

	const SDL_PixelFormatDetails* inter_surface_format
			= SDL_GetPixelFormatDetails(inter_surface->format);
	SDL_Palette* paletted_surface_palette
			= SDL_GetSurfacePalette(paletted_surface);
	const Manip8to32 manip(
			paletted_surface_palette->colors, inter_surface_format);
	Scale_2xBilinearPlus<unsigned char, uint32, Manip8to32>(
			static_cast<uint8*>(draw_surface->pixels), x + guard_band,
			y + guard_band, w, h, ibuf->line_width, ibuf->height + guard_band,
			static_cast<uint32*>(inter_surface->pixels),
			inter_surface->pitch / inter_surface_format->bytes_per_pixel,
			manip);
}
