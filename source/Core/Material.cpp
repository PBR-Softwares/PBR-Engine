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

#include    "PBR/Core/Material.hpp"
#include    "PBR/Core/Texture.hpp"
#include    "PBR/Core/TextureLibrary.hpp"

namespace   PBR
{
    namespace   Core
    {
        Material::Material() :
            m_name("DefaultMaterial")
        {
            // Nothing to do.
        }

        Material::Material(const Material &other) :
            m_name(other.m_name)
        {
            // Nothing to do.
        }

        Material::Material(Material &&other) noexcept :
            m_name(std::move(other.m_name))
        {
            // Nothing to do.
        }

        Material::~Material(void) noexcept
        {
            // Nothing to do.
        }


        Material &
        Material::operator=(const Material &other)
        {
            this->m_name = other.m_name;
            return *this;
        }

        Material &
        Material::operator=(Material &&other) noexcept
        {
            this->m_name = std::move(other.m_name);
            return *this;
        }
    }
}
