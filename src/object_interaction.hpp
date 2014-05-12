#pragma once
#ifndef GL_OBJECT_INTERACTION_HPP
#define GL_OBJECT_INTERACTION_HPP

#include "message_box_screen.hpp"
#include "object.hpp"

namespace green_leaf {
  class ObjectInteraction {
  public:
    ObjectInteraction(const std::vector<Object>& objects);

    std::unique_ptr<Screen> update(ScreenManager& screen_manager, const Vector2 facing, PlayerInput& input) const;

  private:
    const std::vector<Object>& objects_;
  };
}

#endif
