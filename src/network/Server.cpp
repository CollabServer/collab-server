#include "collabserver/network/Server.h"

#include <zmq.hpp>

#include "collabcommon/messaging/MessageFactory.h"
#include "collabcommon/messaging/IMessage.h"
#include "collabcommon/messaging/MessageTypes.h"

namespace collab {


void Server::start() {
    if(!this->m_isRunning) {
        this->m_isRunning = true;

        // TODO To move outside + config
        zmq::context_t context(1);
        zmq::socket_t socket(context, ZMQ_REP);
        socket.bind("tcp://*:5555");

        while(this->m_isRunning) {
            //LOG_DEBUG(0, "Waiting for message...");
            zmq::message_t request;
            socket.recv(&request);

            //NetHelper::processMessage(static_cast<char*>(request.data()), request.size());

            //TODO To update, for now, required by ZMQ_REP pattern.
            zmq::message_t reply(11);
            memcpy(reply.data(), "Acknowledge", 11);
            socket.send(reply);
        }
    }
}

void Server::stop() {
    this->m_isRunning = false;
}


} // End namespace

