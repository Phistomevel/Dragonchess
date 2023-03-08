#include <map>
#include "griffon.h"
#include "../moves.h"
#include "abstract.h"
namespace game {
    namespace moves {

        Griffon::~Griffon() {}
        std::vector<::game::Moves> Griffon::getMoves(int layer) {
            static std::map<int, std::vector<::game::Moves>> moves;
            if (!moves.size()) {
                moves = {
                     {0, {
                }},
                {1, {
                   {-1,-1,0,"relative"},
                   { 1,-1,0,"relative"},
                   {-1, 1,0,"relative"},
                   { 1, 1,0,"relative"},
                   {-1,-1,1,"relative"},
                   { 1,-1,1,"relative"},
                   {-1, 1,1,"relative"},
                   { 1, 1,1,"relative"}
                }},
                {2,{
                   {-3, 2, 0,"relative"},
                   { 3, 2, 0,"relative"},
                   {-3,-2, 0,"relative"},
                   { 3,-2, 0,"relative"},
                   { 1, 1,-1,"relative"},
                   { 1,-1,-1,"relative"},
                   {-1, 1,-1,"relative"},
                   {-1,-1,-1,"relative"}
                }}
                };
            }
            return moves[layer];
        }
        std::vector<::game::moves::Capture> Griffon::getCaptures(int layer) {
            static std::map<int, std::vector<::game::moves::Capture>> captures;
            if (!captures.size()) {
                captures = {
                    {0,{
                }},
                    {1,{
                        {{-1,-1,0,"relative"}, {-1,-1,0,"relative"}},
                        {{ 1,-1,0,"relative"}, { 1,-1,0,"relative"}},
                        {{-1, 1,0,"relative"}, {-1, 1,0,"relative"}},
                        {{ 1, 1,0,"relative"}, { 1, 1,0,"relative"}},
                        {{-1,-1,1,"relative"}, {-1,-1,1,"relative"}},
                        {{ 1,-1,1,"relative"}, { 1,-1,1,"relative"}},
                        {{-1, 1,1,"relative"}, {-1, 1,1,"relative"}},
                        {{ 1, 1,1,"relative"}, { 1, 1,1,"relative"}}
                }},
                    {2,{
                        {{-3, 2, 0,"relative"},{-3, 2, 0,"relative"}},
                        {{ 3, 2, 0,"relative"},{ 3, 2, 0,"relative"}},
                        {{-3,-2, 0,"relative"},{-3,-2, 0,"relative"}},
                        {{ 3,-2, 0,"relative"},{ 3,-2, 0,"relative"}},
                        {{ 1, 1,-1,"relative"},{ 1, 1,-1,"relative"}},
                        {{ 1,-1,-1,"relative"},{ 1,-1,-1,"relative"}},
                        {{-1, 1,-1,"relative"},{-1, 1,-1,"relative"}},
                        {{-1,-1,-1,"relative"},{-1,-1,-1,"relative"}}
                        
                }}
                };
            }
            return captures[layer];
        }

    }
}