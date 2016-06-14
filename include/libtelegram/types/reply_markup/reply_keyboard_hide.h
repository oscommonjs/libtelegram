#ifndef TELEGRAM_TYPES_REPLY_MARKUP_REPLY_KEYBOARD_HIDE_H_INCLUDED
#define TELEGRAM_TYPES_REPLY_MARKUP_REPLY_KEYBOARD_HIDE_H_INCLUDED

#include "base.h"

namespace telegram {
namespace types {
namespace reply_markup {

struct reply_keyboard_hide final : base<reply_keyboard_hide> {
  /// See https://core.telegram.org/bots/api/#replykeyboardhide
  enum class selective_type : char {
    SELECTIVE,
    NOT_SELECTIVE,
    DEFAULT = NOT_SELECTIVE
  } selective = selective_type::DEFAULT;                                        // Optional. Use this parameter if you want to hide keyboard for specific users only. Targets: 1) users that are @mentioned in the text of the Message object; 2) if the bot's message is a reply (has reply_to_message_id), sender of the original message.

  void get(boost::property_tree::ptree &target_tree) const;
};

void reply_keyboard_hide::get(boost::property_tree::ptree &tree) const {
  /// Get this reply markup into a property tree
  tree.put("reply_markup.hide_keyboard", "True");
  if(selective != selective_type::DEFAULT) {
    switch(selective) {
    case selective_type::SELECTIVE:
      tree.put("reply_markup.selective", true);
      break;
    case selective_type::NOT_SELECTIVE:
      tree.put("reply_markup.selective", false);
      break;
    }
  }
}

}
}
}

#endif // TELEGRAM_TYPES_REPLY_MARKUP_REPLY_KEYBOARD_HIDE_H_INCLUDED
