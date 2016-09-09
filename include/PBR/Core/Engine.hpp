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

#include    "PBR/Core/Configuration.hpp"
#include    "PBR/Core/SceneManager.hpp"

namespace   PBR
{
    namespace   Core
    {
        class Event;
        ///
        /// \brief The Engine class of the PBR-Engine library. This class is the core class of the library.
        ///
        /// The Engine is used to do everything with the library, you can retrieve the scene manager, push new event or update the engine.
        ///
        class PBR_CORE_EXPORTS Engine final
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                Engine(void);

                ///
                /// \brief Copy constructor.
                /// \param other The other engine that should be copied into the new engine.
                ///
                Engine(const Engine &other);

                ///
                /// \brief Move constructor.
                /// \param other The other engine that should be move into this new one.
                ///
                Engine(Engine &&other) noexcept;

                ///
                /// \brief Destructor
                ///
                virtual ~Engine(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                /// \param other The other Engine that should be copied in this instance.
                ///
                Engine &operator=(const Engine &other);

                ///
                /// \brief Move assignment operator.
                /// \param other The other Engine that should be move into this one.
                ///
                Engine &operator=(Engine &&other) noexcept;

            public:
                ///
                /// \brief This function is used to update the active scene of the scene manager.
                ///
                void    update(void);

                ///
                /// \brief This function is used to produce an event on the engine.
                /// \param event The event that will be propagated in the active scene of the scene manager.
                ///
                void    push_event(const Event &event);

            public:
                ///
                /// \brief Getter for the scene manager.
                /// \return A reference to the scene manager.
                ///
                SceneManager    &scene_manager(void);

                ///
                /// \brief Const getter for the scene manager.
                /// \return A const reference to the scene manager.
                ///
                const SceneManager  &scene_manager(void) const;

            private:
                ///
                /// \brief The scene manager that is used by the engine to store and retrieve the scenes.
                ///
                SceneManager    m_scene_manager;
        };
    }
}
