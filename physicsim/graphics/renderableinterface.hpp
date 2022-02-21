#ifndef RENDERABLEINTERFACE
#define RENDERABLEINTERFACE
#include <cstdio>

namespace graphics {

class RenderableInterface {

public:
    virtual void render() = 0;

};

} // namespace graphics

#endif