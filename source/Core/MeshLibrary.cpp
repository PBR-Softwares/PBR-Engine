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

#include    "PBR/Core/MeshLibrary.hpp"
#include    "PBR/Core/Mesh.hpp"

namespace   PBR
{
    namespace   Core
    {
        MeshLibrary::MeshLibrary(void) :
            Library<unsigned int, Mesh *>()
        {
            // nothing to do.
        }

        MeshLibrary::MeshLibrary(const MeshLibrary &other) :
            Library<unsigned int, Mesh *>()
        {
            for (const auto &key_value : other.resources())
            {
                this->resources().insert(std::make_pair(key_value.first, new Mesh(*key_value.second)));
            }
        }

        MeshLibrary::~MeshLibrary(void)
        {
            for (const auto &key_value : this->resources())
            {
                delete key_value.second;
            }
        }



        MeshLibrary &
        MeshLibrary::operator=(const MeshLibrary &other)
        {
            for (const auto &key_value : other.resources())
            {
                this->resources().insert(std::make_pair(key_value.first, new Mesh(*key_value.second)));
            }
            return *this;
        }
    }
}
