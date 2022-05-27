//
// Created by Shubham Sawant on 27/05/22.
//

#ifndef LOGOWL_OWL_H
#define LOGOWL_OWL_H

#include<iostream>

#include "utils.h"
#include "alert.h"

namespace moghya {
    class Owl {
        public:
            Owl(const OwlConfig& options) {
            }
            ~Owl() {
            }

        public:
            virtual void Start() {
                std::cout << OwlInfo() << "\n";
                if (m_listenCommands) {
                    ListenCommands();
                }
                Observe();
            }
            virtual void Stop() {
            }

        protected:
            virtual std::string OwlInfo() = 0;
            virtual bool Observe() = 0;
            virtual bool Reconfigure() {
                return true;
            }
            virtual bool ListenCommands() {
                // TODO(moghya): start a server on another thread to read control commands
                return true;
            }
            virtual bool GenerateAlert(Alert& alert) = 0;

        private:
            bool m_listenCommands;
    };
}


#endif //LOGOWL_OWL_H
