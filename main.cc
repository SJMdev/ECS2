#include <entt/entt.hpp>
#include "components/position.h"
#include <cstdint>

int main()
{
    entt::registry entityRegistry;
    std::uint64_t dt = 16;

    auto entity = entityRegistry.create();

    entityRegistry.assign<Position>(entity, 1.f, 1.f);
}