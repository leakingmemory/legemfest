//
// Created by sigsegv on 2/4/23.
//

#include "POppfVirkestoff.h"
#include "../Decoded/OppfVirkestoff.h"

POppfVirkestoff::POppfVirkestoff(const OppfVirkestoff &oppf, FestUuidList &festUuidList, std::vector<FestUuid> &idblock,
                                 std::string &strblock, std::map<std::string, uint32_t> &cache) :
        POppf(oppf, idblock, strblock, cache),
        PVirkestoff(oppf.virkestoff, festUuidList, idblock, strblock, cache)
{
}