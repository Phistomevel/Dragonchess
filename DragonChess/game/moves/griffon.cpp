#include <map>
#include "griffon.h"
#include "../moves.h"
#include "abstract.h"
#include "../board.h"
namespace game {
    namespace moves {

        Griffon::~Griffon() {}
        std::vector<::game::Moves> Griffon::getMovesRaw(::game::Board &board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::Moves> ret;
            std::map<int, std::vector<::game::Moves>> moves;
            moves = {
                {0,{
            }},
                {1,{
                    ::game::Moves(-1,-1,0,"relative"),
                    ::game::Moves( 1,-1,0,"relative"),
                    ::game::Moves(-1, 1,0,"relative"),
                    ::game::Moves( 1, 1,0,"relative"),
                    ::game::Moves(-1,-1,1,"relative"),
                    ::game::Moves( 1,-1,1,"relative"),
                    ::game::Moves(-1, 1,1,"relative"),
                    ::game::Moves( 1, 1,1,"relative")
            }},
                {2,{
                    ::game::Moves(-3, 2, 0,"relative"),
                    ::game::Moves( 3, 2, 0,"relative"),
                    ::game::Moves(-3,-2, 0,"relative"),
                    ::game::Moves( 3,-2, 0,"relative"),

                    ::game::Moves(-2, 3, 0,"relative"),
                    ::game::Moves( 2, 3, 0,"relative"),
                    ::game::Moves(-2,-3, 0,"relative"),
                    ::game::Moves( 2,-3, 0,"relative"),

                    ::game::Moves( 1, 1,-1,"relative"),
                    ::game::Moves( 1,-1,-1,"relative"),
                    ::game::Moves(-1, 1,-1,"relative"),
                    ::game::Moves(-1,-1,-1,"relative")

            }}
            };
            ret = moves[ActivePiece.getPosition().z];
            for (int i = 0; i < ret.size(); i++) {
                if (ret[i].moveType == ::game::Moves::MOVE_RELATIVE) {
                    ret[i].x += ActivePiece.getPosition().x;
                    ret[i].y += ActivePiece.getPosition().y;
                    ret[i].z += ActivePiece.getPosition().z;
                }
            }
            return ret;
        }
        std::vector<::game::moves::Capture> Griffon::getCapturesRaw(::game::Board &board, ::game::pieces::Abstract& ActivePiece) {
            std::map<int, std::vector<::game::moves::Capture>> captures;
            std::vector<::game::moves::Capture> ret;
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

                        {{-2, 3, 0,"relative"},{-2, 3, 0,"relative"}},
                        {{ 2, 3, 0,"relative"},{ 2, 3, 0,"relative"}},
                        {{-2,-3, 0,"relative"},{-2,-3, 0,"relative"}},
                        {{ 2,-3, 0,"relative"},{ 2,-3, 0,"relative"}},

                        {{ 1, 1,-1,"relative"},{ 1, 1,-1,"relative"}},
                        {{ 1,-1,-1,"relative"},{ 1,-1,-1,"relative"}},
                        {{-1, 1,-1,"relative"},{-1, 1,-1,"relative"}},
                        {{-1,-1,-1,"relative"},{-1,-1,-1,"relative"}}
                        
                }}
                };
            }
            ret = captures[ActivePiece.getPosition().z];
            return ret;
        }
        std::vector<::game::moves::Capture> Griffon::getThreatsInverted(::game::Board &board, ::game::pieces::Abstract& ActivePiece) {
            std::vector<::game::moves::Capture> ret;
            if (ActivePiece.getPosition().z==1) {
                ret.push_back(::game::moves::Capture(::game::Moves( -1,-1,0,"relative")));
                ret.push_back(::game::moves::Capture(::game::Moves(-1,1,0,"relative")));
                ret.push_back(::game::moves::Capture(::game::Moves(1,-1,0,"relative")));
                ret.push_back(::game::moves::Capture(::game::Moves(1,1,0,"relative")));
                ret.push_back(::game::moves::Capture(::game::Moves(1,1,1,"relative")));
                ret.push_back(::game::moves::Capture(::game::Moves(-1,1,1,"relative")));
                ret.push_back(::game::moves::Capture(::game::Moves(1,-1,1,"relative")));
                ret.push_back(::game::moves::Capture(::game::Moves(-1,-1,1,"relative")));
            }
            if (ActivePiece.getPosition().z == 2) {
                ret.push_back(::game::moves::Capture(::game::Moves(-3, 2, 0,"relative")) );
                ret.push_back(::game::moves::Capture(::game::Moves( 3, 2, 0,"relative")));
                ret.push_back(::game::moves::Capture(::game::Moves(-3,-2, 0,"relative")));
                ret.push_back(::game::moves::Capture(::game::Moves( 3,-2, 0,"relative")));
                ret.push_back(::game::moves::Capture(::game::Moves( 2, -3,0,"relative")));
                ret.push_back(::game::moves::Capture(::game::Moves(-2, 3, 0,"relative")));
                ret.push_back(::game::moves::Capture(::game::Moves( 2, 3, 0,"relative")));
                ret.push_back(::game::moves::Capture(::game::Moves(-2,-3, 0,"relative")));
                ret.push_back(::game::moves::Capture(::game::Moves(1,1,.1,"relative"  )));
                ret.push_back(::game::moves::Capture(::game::Moves(-1,1,-1,"relative" )));
                ret.push_back(::game::moves::Capture(::game::Moves(1,-1,-1,"relative" )));
                ret.push_back(::game::moves::Capture(::game::Moves(-1,-1,-1,"relative")));
            } 
            return ret;
        }
    }
}