#include "network/Server.h"

#include <logger/elephant.h>
#include <zmq.hpp>

using namespace collab;


Server::Server() {
    this->isRunning = false;
}

Server::~Server() {
    this->isRunning = false;
}

void Server::start() {
    if(!this->isRunning) {
        this->isRunning = true;
        zmq::context_t context(1);
        zmq::socket_t socket(context, ZMQ_REP);
        socket.bind("tcp://*:5555");

        while(this->isRunning) {
            LOG_DEBUG(0, "Waiting for message...");
            zmq::message_t request;
            socket.recv(&request);
            LOG_DEBUG(0, "Message received");

            this->router.processMessage(static_cast<char*>(request.data()), request.size());

            //TODO To update, for now, required by ZMQ_REP pattern.
            zmq::message_t reply(11);
            memcpy(reply.data(), "Acknowledge", 11);
            socket.send(reply);
            LOG_DEBUG(0, "Replay (acknowledge) sent");
        }
    }
}

void Server::stop() {
    this->isRunning = false;
}
