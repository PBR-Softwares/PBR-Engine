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

#include    "PBR/Core/TextureLibrary.hpp"

namespace   PBR
{
    namespace   Core
    {
        TextureLibrary::TextureLibrary(void) :
            Library<std::string, Texture *>()
        {
            // nothing to do.
        }

        TextureLibrary::TextureLibrary(const TextureLibrary &other) :
            Library<std::string, Texture *>()
        {
            for (const auto &key_value : other.resources())
            {
                this->resources().insert(std::make_pair(key_value.first, new Texture(*key_value.second)));
            }
        }

        TextureLibrary::~TextureLibrary(void)
        {
            for (const auto &key_value : this->resources())
            {
                delete key_value.second;
            }
            // nothing to do.
        }



        TextureLibrary &
        TextureLibrary::operator=(const TextureLibrary &other)
        {
            for (const auto &resource : other.resources())
            {
                this->resources().insert(std::make_pair(resource.first, new Texture(*resource.second)));
            }
            return *this;
        }
    }
}
