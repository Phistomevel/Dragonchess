#include <map>
#include "dragon.h"
#include "../moves.h"
#include "abstract.h"
namespace game {
    namespace moves {
        
        Dragon::~Dragon() {}
        std::vector<::game::Moves> Dragon::getMoves(int layer) {
            static std::map<int, std::vector<::game::Moves>> moves;
            if (!moves.size()) {
                moves = {
                     {0, {
                }},
                {1, {
                }},
                {2,{
                   { 1, 1,0,"relative"},
                   { 2, 2,0,"relative"},
                   { 3, 3,0,"relative"},
                   { 4, 4,0,"relative"},
                   { 5, 5,0,"relative"},
                   { 6, 6,0,"relative"},
                   { 7, 7,0,"relative"},
                   { 8, 8,0,"relative"},
                   {-1, 1,0,"relative"},
                   {-2, 2,0,"relative"},
                   {-3, 3,0,"relative"},
                   {-4, 4,0,"relative"},
                   {-5, 5,0,"relative"},
                   {-6, 6,0,"relative"},
                   {-7, 7,0,"relative"},
                   {-8, 8,0,"relative"},
                   { 1,-1,0,"relative"},
                   { 2,-2,0,"relative"},
                   { 3,-3,0,"relative"},
                   { 4,-4,0,"relative"},
                   { 5,-5,0,"relative"},
                   { 6,-6,0,"relative"},
                   { 7,-7,0,"relative"},
                   { 8,-8,0,"relative"},
                   {-1,-1,0,"relative"},
                   {-2,-2,0,"relative"},
                   {-3,-3,0,"relative"},
                   {-4,-4,0,"relative"},
                   {-5,-5,0,"relative"},
                   {-6,-6,0,"relative"},
                   {-7,-7,0,"relative"},
                   {-8,-8,0,"relative"},
                   { 1, 0,0,"relative"},
                   { 1, 0,0,"relative"},
                   { 0, 1,0,"relative"},
                   { 0,-1,0,"relative"}
                }}
                };
            }
            return moves[layer];
        }
        std::vector<::game::moves::Capture> Dragon::getCaptures(int layer) {
            static std::map<int, std::vector<::game::moves::Capture>> captures;
            if (!captures.size()) {
                captures = {
                    {0,{
                }},
                    {1,{
                }},
                    {2,{
                        {{0,0,0, "relative"},{0,0,-1,"relative"}},
                        {{ 1, 1,0,"relative"},{ 1, 1,0,"relative"}},
                        {{ 2, 2,0,"relative"},{ 2, 2,0,"relative"}},
                        {{ 3, 3,0,"relative"},{ 3, 3,0,"relative"}},
                        {{ 4, 4,0,"relative"},{ 4, 4,0,"relative"}},
                        {{ 5, 5,0,"relative"},{ 5, 5,0,"relative"}},
                        {{ 6, 6,0,"relative"},{ 6, 6,0,"relative"}},
                        {{ 7, 7,0,"relative"},{ 7, 7,0,"relative"}},
                        {{ 8, 8,0,"relative"},{ 8, 8,0,"relative"}},
                        {{-1, 1,0,"relative"},{-1, 1,0,"relative"}},
                        {{-2, 2,0,"relative"},{-2, 2,0,"relative"}},
                        {{-3, 3,0,"relative"},{-3, 3,0,"relative"}},
                        {{-4, 4,0,"relative"},{-4, 4,0,"relative"}},
                        {{-5, 5,0,"relative"},{-5, 5,0,"relative"}},
                        {{-6, 6,0,"relative"},{-6, 6,0,"relative"}},
                        {{-7, 7,0,"relative"},{-7, 7,0,"relative"}},
                        {{-8, 8,0,"relative"},{-8, 8,0,"relative"}},
                        {{ 1,-1,0,"relative"},{ 1,-1,0,"relative"}},
                        {{ 2,-2,0,"relative"},{ 2,-2,0,"relative"}},
                        {{ 3,-3,0,"relative"},{ 3,-3,0,"relative"}},
                        {{ 4,-4,0,"relative"},{ 4,-4,0,"relative"}},
                        {{ 5,-5,0,"relative"},{ 5,-5,0,"relative"}},
                        {{ 6,-6,0,"relative"},{ 6,-6,0,"relative"}},
                        {{ 7,-7,0,"relative"},{ 7,-7,0,"relative"}},
                        {{ 8,-8,0,"relative"},{ 8,-8,0,"relative"}},
                        {{-1,-1,0,"relative"},{-1,-1,0,"relative"}},
                        {{-2,-2,0,"relative"},{-2,-2,0,"relative"}},
                        {{-3,-3,0,"relative"},{-3,-3,0,"relative"}},
                        {{-4,-4,0,"relative"},{-4,-4,0,"relative"}},
                        {{-5,-5,0,"relative"},{-5,-5,0,"relative"}},
                        {{-6,-6,0,"relative"},{-6,-6,0,"relative"}},
                        {{-7,-7,0,"relative"},{-7,-7,0,"relative"}},
                        {{-8,-8,0,"relative"},{-8,-8,0,"relative"}},
                        {{ 1, 0,0,"relative"},{ 1, 0,0,"relative"}},
                        {{ 1, 0,0,"relative"},{ 1, 0,0,"relative"}},
                        {{ 0, 1,0,"relative"},{ 0, 1,0,"relative"}},
                        {{ 0,-1,0,"relative"},{ 0,-1,0,"relative"}}
                }}
                };
            }
            return captures[layer];
        }
        
    }
}