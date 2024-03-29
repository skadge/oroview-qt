/*
    Copyright (c) 2009 Andrew Caudwell (acaudwell@gmail.com)
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:
    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
    3. The name of the author may not be used to endorse or promote products
       derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
    IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
    OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
    IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
    NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
    DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
    THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
    THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glu.h>

#include "resource.h"



class TextureException : public ResourceException {
public:
    TextureException(std::string& texture_file) : ResourceException(texture_file) {}
};

class TextureResource : public Resource {
    void loadTexture(std::string file, int mipmaps, int clamp, int trilinear, bool external_file);
public:
        int w, h;
    GLuint textureid;
    TextureResource(std::string name, int mipmaps, int clamp, int trilinear, bool external_file);
    ~TextureResource();
};

class TextureManager : public ResourceManager {
public:
    TextureManager();
    TextureResource* grab(std::string file, int mipmaps=1, int clamp=1, int trilinear=0, bool external_file = false);
};

extern TextureManager texturemanager;
#endif
