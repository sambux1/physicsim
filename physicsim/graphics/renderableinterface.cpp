#include "renderableinterface.hpp"
#include "graphicsmanager.hpp"
#include <cstdio>

namespace graphics {

int RenderableInterface::register_graphics() {
    printf("Hey\n");
    GraphicsManager::add_to_render_list(this);
    return 1;
}

int RenderableInterface::unregister_graphics() {
    printf("Hey2\n");
    GraphicsManager::remove_from_render_list(this);
    return 1;
}

} // namespace graphics