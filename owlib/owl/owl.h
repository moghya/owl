//
// Created by Shubham Sawant on 27/05/22.
//

#ifndef LOGOWL_OWL_H
#define LOGOWL_OWL_H

#include<iostream>

#include "../utils.h"
#include "../alert/alert.h"

namespace moghya {

    class OwlConfig {
        public:
            OwlConfig(bool listenCommands) :
                    listenCommands(listenCommands){
            }
            bool listenCommands;
    };

    class Owl {
        public:
            Owl(OwlConfig& options) :
                m_listenCommands(options.listenCommands){
            }
            virtual ~Owl() {
            }

        public:
            virtual void Start() {
                std::cout << Info() << "\n";
                if (m_listenCommands) {
                    ListenCommands();
                }
                Observe();
            }
            virtual void Stop() {
            }

        protected:
            virtual std::string Info() = 0;
            virtual bool Observe() = 0;
            virtual bool ListenCommands() {
                // TODO(moghya): start a server on another thread to read control commands
                return true;
            }

        private:
            bool m_listenCommands;
    };
}


#endif //LOGOWL_OWL_H
