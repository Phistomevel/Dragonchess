#pragma once
#include "abstract.h"
namespace game {
    namespace moves {
        class Griffon :
            public ::game::moves::Abstract
        {
        public:
            virtual ~Griffon();
            virtual std::vector<::game::Moves> getMoves(int layer);
            virtual std::vector<::game::moves::Capture> getCaptures(int layer);
        };
    }
}