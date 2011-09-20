/*
    Copyright (c) 2010 Séverin Lemaignan (slemaign@laas.fr)
    Copyright (C) 2009 Andrew Caudwell (acaudwell@gmail.com)

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version
    3 of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef EDGE_RENDERER_H
#define EDGE_RENDERER_H

#include "core/vectors.h"

#include "constants.h"

#include "styles.h"
#include "spline.h"

class OroView;
class FXFont;

class EdgeRenderer
{
    float idle_time;
    
    int tagid;
    
    vec2f label_pos;
        
    std::string label;

    SplineEdge spline;
    
    float getAlpha() { return std::max(0.0f, FADE_TIME - idle_time)/FADE_TIME; }

    void drawName(FXFont& font);


public:
    void increment_idle_time(float dt) {idle_time += dt;}

    EdgeRenderer(int tagid, const std::string& label = "");

    void draw(rendering_mode mode, OroView& env);

    void update(vec2f pos1, vec4f col1, vec2f pos2, vec4f col2, vec2f spos);

};

#endif // EDGE_RENDERER_H
