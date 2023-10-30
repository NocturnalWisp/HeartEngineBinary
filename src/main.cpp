#include <iostream>

#include "heart/engine.h"

#include "module/raylib_core.h"
#include "module/raymath.h"
#include "module/raylib_gui.h"
#include "module/raylib_input.h"

#include "module/raylib_camera.h"
#include "module/raylib_shapes.h"
#include "module/raylib_textures.h"

#include "module/physac_core.h"

using namespace HeartEngine;

int main()
{
    Engine engine = Engine();

    engine.registerModule(HeartRayLib::RayLibCore());
    engine.registerModule(HeartRayLib::RayMath());
    engine.registerModule(HeartRayLib::RayLibGUI());
    engine.registerModule(HeartRayLib::RayLibInput());
    engine.registerModule(HeartRayLib::RayLibCamera());

    engine.registerModule(HeartRayLib::RayLibTextures());
    engine.registerModule(HeartRayLib::RayLibShapes());

    engine.registerModule(HeartPhysac::PhysacCore());

    engine.addNode<Node>("Main", nullptr, "main.lua");

    engine.init();
    engine.run();
}