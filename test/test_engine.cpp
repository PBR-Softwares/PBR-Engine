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

#include    "gtest/gtest.h"
#include    "PBR/Core/Core.hpp"
#include    "PBR/Core/Scene.hpp"
#include    "PBR/Core/Light.hpp"
#include    "PBR/Core/Camera.hpp"

TEST(test, test_instantiation_engine)
{
    PBR::Core::Engine  engine;

    EXPECT_EQ(true, true);
}
