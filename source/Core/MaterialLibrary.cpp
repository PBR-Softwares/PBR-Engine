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

#include    "PBR/Core/MaterialLibrary.hpp"
#include    "PBR/Core/Material.hpp"

namespace   PBR
{
    namespace   Core
    {
        MaterialLibrary::MaterialLibrary(void) :
            Library<unsigned int, Material *>()
        {
            // nothing to do.
        }

        MaterialLibrary::MaterialLibrary(const MaterialLibrary &other) :
            Library<unsigned int, Material *>()
        {
            for (const auto &key_value : other.resources())
            {
                this->resources().insert(std::make_pair(key_value.first, new Material(*key_value.second)));
            }
        }

        MaterialLibrary::~MaterialLibrary(void)
        {
            for (const auto &key_value : this->resources())
            {
                delete key_value.second;
            }
        }


        MaterialLibrary &
        MaterialLibrary::operator=(const MaterialLibrary &other)
        {
            for (const auto &key_value : other.resources())
            {
                this->resources().insert(std::make_pair(key_value.first, new Material(*key_value.second)));
            }
            return *this;
        }
    }
}
