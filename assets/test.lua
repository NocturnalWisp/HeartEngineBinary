
body = addComponent("RectanglePhysicsBody", "Physics Body", {300, 200, 20, 20}, 10)

rect = addComponent("RectangleComponent", "Rectangle", {300, 100, 20, 20}, {0, 0}, 0, {0, 0, 255, 255})

floor = engine:addNode("Floor")
floorRectangle = floor:addComponent("RectangleComponent", "Rectangle", {250, 400, 200, 10}, {0, 0}, 0, {255, 0, 0, 255})
floorBody = floor:addComponent("RectanglePhysicsBody", "Physics Body", {250, 400, 200, 10}, 10)

floorBody.body.enabled = false

function _on_update()
    rect.rect.x = body.body.position.x
    rect.rect.y = body.body.position.y
end

engine.events["fixed_update"]:addListener(_on_update)
