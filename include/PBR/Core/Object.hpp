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

#pragma once

#include    <list>

#include    "PBR/Core/Configuration.hpp"
#include    "PBR/Core/Entity.hpp"
#include    "PBR/Core/Scene.hpp"

namespace   PBR
{
    namespace   Core
    {
        class   Mesh;
        ///
        /// \brief This class is used to represent a physical entity.
        ///
        class PBR_CORE_EXPORTS Object : public Entity
        {
            public:
                ///
                /// \brief Default constructor.
                /// \param node the node related to the object.
                ///
                Object(Scene::Node *node); // TODO GSL NOT NULL

                ///
                /// \brief Copy constructor.
                ///
                Object(const Object &other);

                ///
                /// \brief Move constructor.
                ///
                Object(Object &&other) noexcept;

                ///
                /// \brief Destructor.
                ///
                virtual ~Object(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                Object  &operator=(const Object &other) = default;

                ///
                /// \brief Move assigment operator.
                ///
                Object  &operator=(Object &&other) noexcept = default;

            public:
                ///
                /// \brief This method is used to clone the object.
                ///
                virtual Object  *clone(void) const override;

            protected:
                ///
                /// \brief The meshes associated with the object.
                ///
                std::list<Mesh *>     m_meshes; // TODO GSL NOT NULL
        };
    }
}
