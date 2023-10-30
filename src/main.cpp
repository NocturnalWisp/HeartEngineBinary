#include <iostream>

#include "heart/engine.h"

#include "module/raylib_core.h"
#include "module/raymath.h"
#include "module/raylib_gui.h"
#include "module/raylib_input.h"
#include "module/raylib_camera.h"

#include "module/physac_core.h"

#include "module/raylib_shapes.h"

#include "module/components/camera2d.h"

#include "module/components/raylib_label.h"
#include "module/components/raylib_button.h"

#include "module/components/follow_vector2.h"

#include "module/components/raylib_rectangle.h"

using namespace HeartEngine;

int main()
{
    Engine engine = Engine();

    engine.registerModule(HeartRayLib::RayLibCore());
    engine.registerModule(HeartRayLib::RayMath());
    engine.registerModule(HeartRayLib::RayLibGUI());
    engine.registerModule(HeartRayLib::RayLibInput());
    engine.registerModule(HeartRayLib::RayLibCamera());

    engine.registerModule(HeartRayLib::RayLibShapes());

    engine.registerModule(HeartPhysac::PhysacCore());

    auto game = engine.addNode<Container>("Game");

    auto cameraNode = engine.addNode<Node>("Camera", game);
    auto cameraComponent = cameraNode->addComponent(HeartRayLib::Camera2DComponent("Camera"));
    cameraComponent->zoom = 1;

    // Move Camera
    // engine.events["update"].addListener([cameraComponent]()
    //     { cameraComponent->offset = Vector2AddValue(cameraComponent->offset, 0.4);});

    auto test = engine.addNode<Node>("Parent Transform", game);

    auto label1 = test->addComponent(HeartRayLib::Label("Text Component", "Parent text!",
        {50, 50}, 20, 90, BLACK));
    // label1->setdrawCall({"draw", "Camera", "0"});

    auto label2 = test->addComponent(
        HeartRayLib::Label("Text Component", "This is a test!",
            {20, 20}, 20, 0, PURPLE));
    // label2->setdrawCall({"draw", "Camera", "1"});

    Vector2 offset = {5, 5};

    test->addComponent(HeartRayLib::FollowVector2("Label2 Follow Label1",
        &label2->position, &label1->position, offset
    ));

    engine.events["update"].addListener([&engine, label1]()
        {
            label1->position = Vector2Add(label1->position, Vector2Scale({60, 60}, engine.deltaTime));
        });
    
    test->addComponent(HeartRayLib::Button("Button", {200, 200, 100, 20}));

    test->events["Button"]["pressed"].addListener([](){ Debug::print("Pressed!"); });

    test->addComponent(
        HeartRayLib::RectangleComponent("Rectangle", {400, 200, 100, 100}, {50, 50}, 10, GREEN));
    
    engine.addNode<Node>("Lua Test", game, "test.lua");

    engine.init();
    engine.run();
}