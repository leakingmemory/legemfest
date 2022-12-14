//
// Created by sigsegv on 12/12/22.
//

#include "XmlMarkedsforingsinfo.h"

std::string XmlMarkedsforingsinfo::GetName() const {
    return "Markedsforingsinfo";
}

void XmlMarkedsforingsinfo::SetMarkedsforingsdato(const std::string &markedsforingsdato) {
    this->markedsforingsdato = markedsforingsdato;
}

void XmlMarkedsforingsinfo::SetVarenrUtgaende(const std::string &varenrUtgaende) {
    this->varenrUtgaende = varenrUtgaende;
}

void XmlMarkedsforingsinfo::SetMidlUtgattDato(const std::string &midlUtgattDato) {
    this->midlUtgattDato = midlUtgattDato;
}

void XmlMarkedsforingsinfo::SetAvregDato(const std::string &avregDato) {
    this->avregDato = avregDato;
}

bool XmlMarkedsforingsinfo::Merge() {
    parent->SetMarkedsforingsinfo({markedsforingsdato, varenrUtgaende, midlUtgattDato, avregDato});
    return true;
}

std::shared_ptr<XMLObject> XmlMarkedsforingsinfoHandler::StartElement(const std::shared_ptr<XMLObject> &parent,
                                                                      const std::map<std::string, std::string> &attributes) {
    std::shared_ptr<XmlLegemiddelpakning> typedParent = std::dynamic_pointer_cast<XmlLegemiddelpakning>(parent);
    if (!typedParent) {
        std::cerr << "Error: Unexpected Markedsforingsinfo\n";
        return {};
    }
    return std::make_shared<XmlMarkedsforingsinfo>(typedParent);
}

bool XmlMarkedsforingsinfoHandler::EndElement(const std::shared_ptr<XMLObject> &obj) {
    auto *mi = dynamic_cast<XmlMarkedsforingsinfo*>(&(*obj));
    if (mi == nullptr) {
        std::cerr << "Error: Not ending Markedsforingsinfo\n";
        return false;
    }
    return mi->Merge();
}

bool XmlMarkedsforingsdatoHandler::Merge(std::shared_ptr<XmlMarkedsforingsinfo> parent, const std::string &content) {
    parent->SetMarkedsforingsdato(content);
    return true;
}

bool XmlVarenrUtgaendeHandler::Merge(std::shared_ptr<XmlMarkedsforingsinfo> parent, const std::string &content) {
    parent->SetVarenrUtgaende(content);
    return true;
}

bool XmlMidlUtgattDatoHandler::Merge(std::shared_ptr <XmlMarkedsforingsinfo> parent, const std::string &content) {
    parent->SetMidlUtgattDato(content);
    return true;
}

bool XmlAvregDatoHandler::Merge(std::shared_ptr <XmlMarkedsforingsinfo> parent, const std::string &content) {
    parent->SetAvregDato(content);
    return true;
}