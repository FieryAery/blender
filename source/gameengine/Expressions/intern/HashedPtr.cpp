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

/** \file gameengine/Expressions/KX_HashedPtr.cpp
 *  \ingroup expressions
 */


#include "EXP_HashedPtr.h"


CHashedPtr::CHashedPtr(void* val) : m_valptr(val)
{
}


unsigned int CHashedPtr::hash() const
{
#if defined(_WIN64)
	unsigned __int64 key = (unsigned __int64)m_valptr;
#else
	unsigned long key = (unsigned long)m_valptr;
#endif

	key += ~(key << 16);
	key ^=  (key >>  5);
	key +=  (key <<  3);
	key ^=  (key >> 13);
	key += ~(key <<  9);
	key ^=  (key >> 17);

	return (unsigned int)(key & 0xffffffff);
}
