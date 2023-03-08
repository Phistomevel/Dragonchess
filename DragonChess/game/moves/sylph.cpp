#include <map>
#include "sylph.h"
#include "../moves.h"
#include "abstract.h"
namespace game {
    namespace moves {
        
        Sylph::Sylph() {}
        Sylph::~Sylph() {}
        std::vector<::game::Moves> Sylph::getMoves(int layer) {
            static std::map<int, std::vector<::game::Moves>> moves;
            if (!moves.size()) {
                moves = {
                     {0, {
                }},
                {1, {
                   { 0,0,1,"relative"},
                   { 1,2,2,"absolute"},
                   { 3,2,2,"absolute"},
                   { 5,2,2,"absolute"},
                   { 7,2,2,"absolute"},
                   { 9,2,2,"absolute"},
                   {11,2,2,"absolute"}
                }},
                {2,{
                   {-1,1,0,"relative"},
                   { 1,1,0,"relative"}
                }}
                };
            }
            return moves[layer];
        }
        std::vector<::game::moves::Capture> Sylph::getCaptures(int layer) {
            static std::map<int, std::vector<::game::moves::Capture>> captures;
            if (!captures.size()) {
                captures = {
                    {0,{
                }},
                    {1,{
                }},
                    {2,{
                        {{0,0,-1, "relative"},{0,0,-1,"relative"}}
                }}
                };
            }
            return captures[layer];
        }
        
    }
}