#include "GLResource.h"
#include "renderers/utils/GLResourceManager.h"

#include <thread>

namespace carto {

    GLResource::~GLResource() {
    }

    bool GLResource::isValid() const {
        if (auto manager = _manager.lock()) {
            return manager->getGLThreadId() != std::thread::id();
        }
        return false;
    }
      
    GLResource::GLResource(const std::weak_ptr<GLResourceManager>& manager) :
        _manager(manager)
    {
    }

}
