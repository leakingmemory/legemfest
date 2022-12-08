//
// Created by sigsegv on 12/8/22.
//

#include "Fest.h"
#include <iostream>

std::string HentetDato::GetName() {
    return "HentetDato";
}

bool HentetDato::AppendCharacterData(const std::string &charData) {
    date.append(charData);
    return true;
}

void HentetDato::Merge() {
    fest->SetHentetDato(date);
}

std::string Fest::GetName() {
    return "FEST";
}

std::shared_ptr<XMLObject> FestHandler::StartElement(const std::shared_ptr<XMLObject> &parent, const std::vector<NameValue> &attributes) {
    return std::make_shared<Fest>();
}

bool FestHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    return dynamic_cast<Fest*>(&(*obj)) != nullptr;
}

std::shared_ptr<XMLObject> HentetDatoHandler::StartElement(const std::shared_ptr<XMLObject> &parent, const std::vector<NameValue> &attributes) {
    std::shared_ptr<Fest> fest = std::dynamic_pointer_cast<Fest>(parent);
    if (!fest) {
        std::cerr << "Error: HentetDato parent is not Fest\n";
        return {};
    }
    return std::make_shared<HentetDato>(fest);
}

bool HentetDatoHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    std::shared_ptr<HentetDato> hentetDato = std::dynamic_pointer_cast<HentetDato>(obj);
    if (!hentetDato) {
        std::cerr << "Error: HentetDato is wrong type\n";
        return false;
    }
    hentetDato->Merge();
    return true;
}