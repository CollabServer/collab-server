#pragma once

#include <zmq.hpp>


namespace collab {
class IMessage;


/**
 * Utils for Messages communication over network.
 * Abstract class with only static functions.
 *
 * \date    Dec 2017
 * \author  Constantin Masson
 * \since   0.1.0
 */
class MessageHelper {
    private:
        MessageHelper() = default;
        ~MessageHelper() = default;

    public:
        /**
         * Send the given message on the socket.
         * This doesn't block.
         *
         * \param socket Socket where to send message.
         * \param msg The message to send.
         */
        static void sendMessage(zmq::socket_t & socket, const IMessage & msg);
};


} // End namespace
