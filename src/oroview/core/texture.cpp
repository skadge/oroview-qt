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

#include <QGLWidget>

#include "texture.h"

// texture resource

TextureManager texturemanager;

// texture manager

TextureManager::TextureManager() : ResourceManager() {
}

TextureResource* TextureManager::grab(std::string name, int mipmaps, int clamp, int trilinear, bool external_file) {
    //debugLog("grabing %s\n", name.c_str());
    Resource* r = resources[name];

    if(r==0) {
        //debugLog("%s not found. creating resource...\n", name.c_str());

        r = new TextureResource(name, mipmaps, clamp, trilinear, external_file);

        resources[name] = r;
    }
    r->addref();
    return (TextureResource*)r;
}

TextureResource::TextureResource(std::string file, int mipmaps, int clamp, int trilinear, bool external_file) : Resource(file) {
    QPixmap tex = QPixmap(QString::fromStdString(file));
    w = tex.width();
    h = tex.height();

    textureid = bindTexture(tex, GL_TEXTURE_2D);
}

TextureResource::~TextureResource() {
    if(textureid!=0) glDeleteTextures(1, &textureid);
}
