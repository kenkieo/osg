/* -*-c++-*- OpenSceneGraph - Copyright (C) 1998-2003 Robert Osfield 
 *
 * This library is open source and may be redistributed and/or modified under  
 * the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
 * (at your option) any later version.  The full license is in LICENSE file
 * included with this distribution, and on the openscenegraph.org website.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * OpenSceneGraph Public License for more details.
*/
#include <osg/Stencil>

using namespace osg;

Stencil::Stencil()
{
    // set up same defaults as glStencilFunc.
    _func = ALWAYS;
    _funcRef = 0;
    _funcMask = ~0;
        
    // set up same defaults as glStencilOp.
    _sfail = KEEP;
    _zfail = KEEP;
    _zpass = KEEP;

    // set up same defaults as glStencilMask.
    _writeMask = ~0;
}


Stencil::~Stencil()
{
}

void Stencil::apply(State&) const
{
    glStencilFunc((GLenum)_func,_funcRef,_funcMask);
    glStencilOp((GLenum)_sfail,(GLenum)_zfail,(GLenum)_zpass);
    glStencilMask(_writeMask);
}

