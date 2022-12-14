//
// Created by sigsegv on 12/23/22.
//

#ifndef LEGEMFEST_OPPFREFUSJON_H
#define LEGEMFEST_OPPFREFUSJON_H

#include <string>
#include "Status.h"
#include "Refusjonshjemmel.h"

class OppfRefusjon {
private:
    std::string id;
    std::string tidspunkt;
    Status status;
    Refusjonshjemmel refusjonshjemmel;
public:
    OppfRefusjon() : id(), tidspunkt(), status(), refusjonshjemmel() {}
    OppfRefusjon(const std::string &id, const std::string &tidspunkt, const Status &status,
                 const Refusjonshjemmel &refusjonshjemmel) :
            id(id), tidspunkt(tidspunkt), status(status), refusjonshjemmel(refusjonshjemmel) {}
    [[nodiscard]] std::string GetId() const;
    [[nodiscard]] std::string GetTidspunkt() const;
    [[nodiscard]] Status GetStatus() const;
    [[nodiscard]] Refusjonshjemmel GetRefusjonshjemmel() const;
};

#endif //LEGEMFEST_OPPFREFUSJON_H
