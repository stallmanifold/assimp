/*
---------------------------------------------------------------------------
Open Asset Import Library (ASSIMP)
---------------------------------------------------------------------------

Copyright (c) 2006-2008, ASSIMP Development Team

All rights reserved.

Redistribution and use of this software in source and binary forms, 
with or without modification, are permitted provided that the following 
conditions are met:

* Redistributions of source code must retain the above
  copyright notice, this list of conditions and the
  following disclaimer.

* Redistributions in binary form must reproduce the above
  copyright notice, this list of conditions and the
  following disclaimer in the documentation and/or other
  materials provided with the distribution.

* Neither the name of the ASSIMP team, nor the names of its
  contributors may be used to endorse or promote products
  derived from this software without specific prior
  written permission of the ASSIMP Development Team.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
---------------------------------------------------------------------------
*/

/** @file Defines the aiCamera data structure
 */

#ifndef AI_CAMERA_H_INC
#define AI_CAMERA_H_INC

#include "aiTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

// ---------------------------------------------------------------------------
/** Helper structure to describe a virtual camera. 
 *
 * Cameras have a representation in the node graph and can be animated.
 *
*/
struct aiCamera
{
	/** The name of the camera.
	 *
	 *  There must be a node in the scenegraph with the same name.
	 *  This node specifies the position of the camera in the scene
	 *  hierarchy and can be animated.
	 */
	aiString mName;

	/** Half horizontal field of view angle, in radians. 
	 *
	 *  The field of view angle is the angle between the center
	 *  line of the screen and the left or right border.
	 *  The default value is 1/4PI.
	 */
	float mHorizontalFOV;

	/** Distance of the near clipping plane from the camera.
	 *
	 * The value may not be 0.f (for arithmetic reasons to prevent
	 * a division through zero). The default value is 0.1f.
	 */
	float mClipPlaneNear;

	/** Distance of the far clipping plane from the camera.
	 *
	 * The far clipping plane must, of course, be farer away than the
	 * near clipping plane. The default value is 1000.f. The radio
	 * between the near and the far plane should not be too
	 * large (between 1000-10000 should be ok) to avoid floating-point
	 * inaccuracies which could lead to z-fighting.
	 */
	float mClipPlaneFar;


	/** Screen aspect ratio.
	 *
	 * This is the ration between the width and the height of the
	 * screen. Typical values are 4/3, 1/2 or 1/1. This value is
	 * 0 if the aspect ratio is not defined in the source file.
	 * 0 is also the default value.
	 */
	float mAspect;

#ifdef __cplusplus

	aiCamera()
		: mHorizontalFOV	(0.25f * (float)AI_MATH_PI)
		, mClipPlaneNear	(0.1f)
		, mClipPlaneFar		(1000.f)
		, mAspect			(0.f)
	{
	}

#endif
};


#ifdef __cplusplus
}
#endif

#endif // AI_CAMERA_H_INC