/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The Original Code is Copyright (C) 2001-2002 by NaN Holding BV.
 * All rights reserved.
 */

/** \file RAS_Prewitt2DFilter.h
 *  \ingroup bgerastoglfilters
 */

#ifndef __RAS_PREWITT2DFILTER_H__
#define __RAS_PREWITT2DFILTER_H__

static const char *PrewittFragmentShader = STRINGIFY(
uniform sampler2D bgl_RenderedTexture;
uniform vec2 bgl_TextureCoordinateOffset[9];

void main(void)
{
	vec4 sample[9];

	for (int i = 0; i < 9; i++)
	{
		sample[i] = texture2D(bgl_RenderedTexture,
		                      gl_TexCoord[0].st + bgl_TextureCoordinateOffset[i]);
	}

	vec4 horizEdge = sample[2] + sample[5] + sample[8] -
	        (sample[0] + sample[3] + sample[6]);

	vec4 vertEdge = sample[0] + sample[1] + sample[2] -
	        (sample[6] + sample[7] + sample[8]);

	gl_FragColor.rgb = sqrt((horizEdge.rgb * horizEdge.rgb) +
	                        (vertEdge.rgb * vertEdge.rgb));
	gl_FragColor.a = 1.0;
}

);
#endif
