#include "object_interaction.hpp"

#include "player_input.hpp"

namespace green_leaf {
  ObjectInteraction::ObjectInteraction(const std::vector<Object>& objects)
    : objects_(objects)
  {
  }

  std::unique_ptr<Screen> ObjectInteraction::update(ScreenManager& screen_manager, const Vector2 destination, PlayerInput& input) const {
    if(!input.aPressed()) {
      return nullptr;
    }

    for(auto object : objects_) {
      if(object.rectangle().contains(destination)) {
        return std::make_unique<MessageBoxScreen>(screen_manager, object.messages());
      }
    }

    return nullptr;
  }
}
