#pragma once
#include "abstract.h"
namespace game {
    namespace moves {
        class Sylph : public ::game::moves::Abstract
        {
        public:
            Sylph();
            virtual ~Sylph();
            virtual std::vector<::game::Moves> getMoves(int layer);
            virtual std::vector<::game::moves::Capture> getCaptures(int layer);
        };
    }
}
