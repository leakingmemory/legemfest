//
// Created by jeo on 12/9/22.
//

#include "XmlLegemiddel.h"
#include "../Struct/Decoded/AdministreringLegemiddel.h"
#include <iostream>

Atc XmlLegemiddel::GetAtc() const {
    return atc;
}

void XmlLegemiddel::SetAtc(const Atc &atc) {
    this->atc = atc;
}

std::string XmlLegemiddel::GetNavnFormStyrke() {
    return navnFormStyrke;
}

void XmlLegemiddel::SetNavnFormStyrke(const std::string &navnFormStyrke) {
    this->navnFormStyrke = navnFormStyrke;
}

Reseptgruppe XmlLegemiddel::GetReseptgruppe() {
    return reseptgruppe;
}

void XmlLegemiddel::SetReseptgruppe(const Reseptgruppe &reseptgruppe) {
    this->reseptgruppe = reseptgruppe;
}

LegemiddelformKort XmlLegemiddel::GetLegemiddelformKort() const {
    return legemiddelformKort;
}

void XmlLegemiddel::SetLegemiddelformKort(const LegemiddelformKort &legemiddelformKort) {
    this->legemiddelformKort = legemiddelformKort;
}

std::vector<std::string> XmlLegemiddel::GetRefVilkar() const {
    return refVilkar;
}

void XmlLegemiddel::AddRefVilkar(const std::string &refVilkar) {
    this->refVilkar.push_back(refVilkar);
}

TypeSoknadSlv XmlLegemiddel::GetTypeSoknadSlv() const {
    return typeSoknadSlv;
}

void XmlLegemiddel::SetTypeSoknadSlv(const TypeSoknadSlv &typeSoknadSlv) {
    this->typeSoknadSlv = typeSoknadSlv;
}

AdministreringLegemiddel XmlLegemiddel::GetAdministreringLegemiddel() const {
    return administreringLegemiddel;
}

void XmlLegemiddel::SetAdministreringLegemiddel(const AdministreringLegemiddel &administreringLegemiddel) {
    this->administreringLegemiddel = administreringLegemiddel;
}

MaybeBoolean XmlLegemiddel::GetOpioidsoknad() const {
    return opioidsoknad;
}

void XmlLegemiddel::SetOpioidsoknad(bool opioidsoknad) {
    this->opioidsoknad = opioidsoknad ? MaybeBoolean::TRUE : MaybeBoolean::FALSE;
}

SvartTrekant XmlLegemiddel::GetSvartTrekant() const {
    return svartTrekant;
}

void XmlLegemiddel::SetSvartTrekant(const SvartTrekant &svartTrekant) {
    this->svartTrekant = svartTrekant;
}

std::string XmlAtc::GetName() const {
    return "Atc";
}

std::string XmlNavnFormStyrke::GetName() const {
    return "NavnFormStyrke";
}

bool XmlNavnFormStyrke::AppendCharacterData(const std::string &charData) {
    navnFormStyrke.append(charData);
    return true;
}

void XmlNavnFormStyrke::Merge() {
    legemiddel->SetNavnFormStyrke(navnFormStyrke);
}

bool XmlAtcHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlLegemiddel>> obj) {
    obj->GetParent()->SetAtc(Atc(obj->GetValueWithCodeSet()));
    return true;
}

bool XmlNavnFormStyrkeHandler::Merge(std::shared_ptr<XmlLegemiddel> parent, const std::string &content) {
    parent->SetNavnFormStyrke(content);
    return true;
}

bool XmlReseptgruppeHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetReseptgruppe({obj->GetValueWithDistinguishedName()});
    return true;
}

bool XmlLegemiddelformKortHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlLegemiddel>> obj) {
    obj->GetParent()->SetLegemiddelformKort({obj->GetValueWithCodeSet()});
    return true;
}

bool XmlRefVilkarHandler::Merge(std::shared_ptr<XmlLegemiddel> parent, const std::string &content) {
    parent->AddRefVilkar(content);
    return true;
}

bool XmlTypeSoknadSlvHandler::Merge(std::shared_ptr<XmlType> obj) {
    obj->GetParent()->SetTypeSoknadSlv({obj->GetValueWithDistinguishedName()});
    return true;
}

bool XmlOpioidsoknadHandler::Merge(std::shared_ptr<XmlLegemiddel> parent, const std::string &content) {
    if (content == "true") {
        parent->SetOpioidsoknad(true);
        return true;
    } else if (content == "false") {
        parent->SetOpioidsoknad(false);
        return true;
    }
    std::cerr << "Error: Opioidsoknad: Unrecognized value: " << content << "\n";
    return false;
}

bool XmlSvartTrekantHandler::Merge(std::shared_ptr<XmlValueWithCodeSet<XmlLegemiddel>> obj) {
    obj->GetParent()->SetSvartTrekant({obj->GetValueWithCodeSet()});
    return true;
}
