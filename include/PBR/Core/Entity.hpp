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

#include    <string>

#include    "PBR/Core/Configuration.hpp"
#include    "PBR/Core/Scene.hpp"

namespace   PBR
{
    namespace   Core
    {
        ///
        /// \brief This class is used to represent something physically or not in the 3D world.
        ///
        class PBR_CORE_EXPORTS Entity
        {
            public:
                ///
                /// \brief Default constructor
                /// \param node the node which the entity is attached.
                ///
                Entity(Scene::Node *node); // TODO GSL NOT NULL

                ///
                /// \brief Copy constructor.
                ///
                Entity(const Entity &other);

                ///
                /// \brief Move constructor.
                ///
                Entity(Entity &&other);

                ///
                /// \brief Destructor.
                ///
                virtual ~Entity(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                Entity  &operator=(const Entity &other);

                ///
                /// \brief Move assignment operator.
                ///
                Entity  &operator=(Entity &&other);

            public:
                ///
                /// \brief clone pattern
                ///
                virtual Entity  *clone(void) const = 0;

            public:
                ///
                /// \brief method used to update the entity.
                ///
                virtual void    update(void);

            protected:
                ///
                /// \brief The node which the entity is attached.
                ///
                Scene::Node     *m_node; // TODO GSL NOT NULL
        };
    }
}
