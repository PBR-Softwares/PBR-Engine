//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; If not, see <http://www.gnu.org/licenses/>.
//
// Copyright (C) 2016 PBR-Softwares (contact@pbr-softwares.com)
//

#include    "PBR/Core/Object.hpp"
#include    "PBR/Core/Scene.hpp"

namespace   PBR
{
    namespace   Core
    {
        Object::Object(Scene::Node *node) :
            Entity(node),
            m_meshes()
        {

        }

        Object::~Object(void)
        {

        }



        Object *
        Object::clone(void) const
        {
            return new Object(*this);
        }
    }
}
