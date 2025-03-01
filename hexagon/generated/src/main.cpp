#include <moss/includes.hpp>
#include <moss/core/init.hpp>
#include <moss/render/systems.hpp>
#include <hexagon/components/serialization.hpp>
#include <hexagon/entities/systems.hpp>
#include <fstream>


int main() {
    entt::registry registry;
    const json& gameConfig = json::parse(std::ifstream("hexagon/data/gameConfig.json"));
    moss::initRaylib(gameConfig);

    moss::ComponentRegistry componentRegistry; moss::buildComponentRegistry(registry, componentRegistry);
    REGISTER_COMPONENT(hexagon::RotationDevice);
    REGISTER_TAG(hexagon::BallTag);
    REGISTER_TAG(hexagon::HexTag);
    moss::initEntt(gameConfig, registry, componentRegistry);

    while (!raylib::WindowShouldClose()) {
        hexagon::hex::update(registry);
        hexagon::ball::update(registry);
        moss::render::update(registry);
    }

    raylib::CloseWindow();
}
