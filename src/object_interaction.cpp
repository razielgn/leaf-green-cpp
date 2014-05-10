#include "object_interaction.hpp"

#include "player_input.hpp"
#include "sign_message_box_screen.hpp"
#include "blue_message_box_screen.hpp"

namespace green_leaf {
  ObjectInteraction::ObjectInteraction(const std::vector<Object>& objects)
    : objects_(objects)
  {
  }

  std::unique_ptr<Screen> ObjectInteraction::update(ScreenManager& screen_manager, const Vector2 facing, PlayerInput& input) const {
    for(auto object : objects_) {
      if(object.rectangle().contains(facing)) {
        if(input.aPressed()) {
          if(object.isSign()) {
            return std::make_unique<SignMessageBoxScreen>(screen_manager, object.messages());
          } else {
            return std::make_unique<BlueMessageBoxScreen>(screen_manager, object.messages());
          }
        }
      }
    }

    return nullptr;
  }
}
