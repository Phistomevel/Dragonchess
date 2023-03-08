#pragma once
#include "abstract.h"
namespace game {
    namespace moves {
        class Dragon : public ::game::moves::Abstract
        {
        public:
            virtual ~Dragon();
            virtual std::vector<::game::Moves> getMoves(int layer);
            virtual std::vector<::game::moves::Capture> getCaptures(int layer);
        };
    }
}
