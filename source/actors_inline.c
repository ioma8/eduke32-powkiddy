//-------------------------------------------------------------------------
/*
Copyright (C) 2010 EDuke32 developers and contributors

This file is part of EDuke32.

EDuke32 is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License version 2
as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
//-------------------------------------------------------------------------

#ifndef __actors_inline_c__
#define __actors_inline_c__

#include "compat.h"
#include "build.h"
#include "global.h"
#include "duke3d.h"
#include "actors_inline.h"

ACTOR_INLINE int32_t A_SetSprite(int32_t i,uint32_t cliptype)
{
    vec3_t davect = {(sprite[i].xvel*(sintable[(sprite[i].ang+512)&2047]))>>14,
                     (sprite[i].xvel*(sintable[sprite[i].ang&2047]))>>14,
                     sprite[i].zvel
                    };
    return (A_MoveSprite(i,&davect,cliptype)==0);
}


EXTERN_INLINE void G_UpdateInterpolations(void)  //Stick at beginning of G_DoMoveThings
{
    int32_t i=g_numInterpolations-1;
    for (; i>=0; i--) oldipos[i] = *curipos[i];
}


EXTERN_INLINE void G_RestoreInterpolations(void)  //Stick at end of drawscreen
{
    int32_t i=g_numInterpolations-1;

    if (--g_interpolationLock)
        return;

    for (; i>=0; i--) *curipos[i] = bakipos[i];
}

EXTERN_INLINE int32_t G_CheckForSpaceCeiling(int32_t sectnum)
{
    return ((sector[sectnum].ceilingstat&1) && sector[sectnum].ceilingpal == 0 &&
            (sector[sectnum].ceilingpicnum==MOONSKY1 || sector[sectnum].ceilingpicnum==BIGORBIT1));
}

EXTERN_INLINE int32_t G_CheckForSpaceFloor(int32_t sectnum)
{
    return ((sector[sectnum].floorstat&1) && sector[sectnum].ceilingpal == 0 &&
            (sector[sectnum].floorpicnum==MOONSKY1 || sector[sectnum].floorpicnum==BIGORBIT1));
}

EXTERN_INLINE int32_t A_CheckEnemySprite(const spritetype *s)
{
    return A_CheckEnemyTile(s->picnum);
}

#endif
