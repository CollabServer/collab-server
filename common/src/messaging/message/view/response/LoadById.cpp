#include "messaging/message/view/response/LoadById.h"

#include <msgpack.hpp>


using namespace collab;
namespace msg = messaging::message::view::response;


void msg::LoadById::apply() {
    if(this->m_event != nullptr) {
        this->m_event->receive(*this);
    }
}

bool msg::LoadById::serialize(std::stringstream & buffer) const {
    // TODO
    return true;
}

bool msg::LoadById::unserialize(std::stringstream & stream) {
    // TODO
    return true;
}

MessageTypes msg::LoadById::getType() const {
    return MessageTypes::VIEW_RESPONSE_LOAD_BY_ID;
}

