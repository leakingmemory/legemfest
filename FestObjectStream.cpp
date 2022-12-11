//
// Created by jeo on 12/8/22.
//

#include "FestObjectStream.h"
#include "XMLParser.h"
#include "Fest/Fest.h"
#include "Fest/FestIdObject.h"
#include "Fest/KatLegemiddelMerkevare.h"
#include "Fest/TidspunktObject.h"
#include "Fest/StatusObject.h"
#include "Fest/XmlLegemiddelMerkevare.h"
#include "Fest/XmlLegemiddel.h"
#include "Fest/XmlPreparattypeObject.h"
#include "Fest/XmlAdministreringLegemiddel.h"
#include "Fest/XmlSortertVirkestoffMedStyrke.h"
#include "Fest/XmlSortering.h"
#include "Fest/XmlRefVirkestoffMedStyrke.h"
#include "Fest/XmlProduktInfo.h"
#include "Fest/XmlReseptgyldighet.h"
#include "Fest/XmlVarighet.h"
#include "Fest/XmlPreparatomtaleavsnitt.h"
#include "Fest/XmlRefVirkestoff.h"
#include "Fest/XmlSortertVirkestoffUtenStyrke.h"
#include "Fest/XmlKjonn.h"
#include "Fest/XmlLegemiddelpakning.h"
#include <iostream>

void FestObjectStream::read() {
    XMLParser parser{};
    parser.AddHandler("FEST", std::make_shared<FestHandler>());
    parser.AddHandler("HentetDato", std::make_shared<HentetDatoHandler>());
    parser.AddHandler("Id", std::make_shared<FestIdHandler>());
    parser.AddHandler("KatLegemiddelMerkevare", std::make_shared<KatLegemiddelMerkevareHandler>());
    parser.AddHandler("OppfLegemiddelMerkevare", std::make_shared<OppfLegemiddelMerkevareHandler>());
    parser.AddHandler("Tidspunkt", std::make_shared<XmlTidspunktObjectHandler>());
    parser.AddHandler("Status", std::make_shared<XmlStatusObjectHandler>());
    parser.AddHandler("LegemiddelMerkevare", std::make_shared<XmlLegemiddelMerkevareHandler>());
    parser.AddHandler("Atc", std::make_shared<XmlAtcHandler>());
    parser.AddHandler("NavnFormStyrke", std::make_shared<XmlNavnFormStyrkeHandler>());
    parser.AddHandler("Reseptgruppe", std::make_shared<XmlReseptgruppeHandler>());
    parser.AddHandler("LegemiddelformKort", std::make_shared<XmlLegemiddelformKortHandler>());
    parser.AddHandler("RefVilkar", std::make_shared<XmlRefVilkarHandler>());
    parser.AddHandler("Preparattype", std::make_shared<XmlPreparattypeObjectHandler>());
    parser.AddHandler("TypeSoknadSlv", std::make_shared<XmlTypeSoknadSlvHandler>());
    parser.AddHandler("AdministreringLegemiddel", std::make_shared<XmlAdministreringLegemiddelHandler>());
    parser.AddHandler("Administrasjonsvei", std::make_shared<XmlAdministrasjonsveiHandler>());
    parser.AddHandler("EnhetDosering", std::make_shared<XmlEnhetDoseringHandler>());
    parser.AddHandler("Varenavn", std::make_shared<XmlVarenavnHandler>());
    parser.AddHandler("LegemiddelformLang", std::make_shared<XmlLegemiddelformLangHandler>());
    parser.AddHandler("SortertVirkestoffMedStyrke", std::make_shared<XmlSortertVirkestoffMedStyrkeHandler>());
    parser.AddHandler("Sortering", std::make_shared<XmlSorteringHandler>());
    parser.AddHandler("RefVirkestoffMedStyrke", std::make_shared<XmlRefVirkestoffMedStyrkeHandler>());
    parser.AddHandler("ProduktInfo", std::make_shared<XmlProduktInfoHandler>());
    parser.AddHandler("Produsent", std::make_shared<XmlProdusentHandler>());
    parser.AddHandler("Reseptgyldighet", std::make_shared<XmlReseptgyldighetHandler>());
    parser.AddHandler("Varighet", std::make_shared<XmlVarighetHandler>());
    parser.AddHandler("BruksomradeEtikett", std::make_shared<XmlBruksomradeEtikettHandler>());
    parser.AddHandler("KanKnuses", std::make_shared<XmlKanKnusesHandler>());
    parser.AddHandler("ForhandsregelInntak", std::make_shared<XmlForhandsregelInntakHandler>());
    parser.AddHandler("Varseltrekant", std::make_shared<XmlVarseltrekantHandler>());
    parser.AddHandler("Referanseprodukt", std::make_shared<XmlReferanseproduktHandler>());
    parser.AddHandler("Preparatomtaleavsnitt", std::make_shared<XmlPreparatomtaleavsnittHandler>());
    parser.AddHandler("Avsnittoverskrift", std::make_shared<XmlAvsnittoverskriftHandler>());
    parser.AddHandler("Lenke", std::make_shared<XmlLenkeHandler>());
    parser.AddHandler("Www", std::make_shared<XmlWwwHandler>());
    parser.AddHandler("Kortdose", std::make_shared<XmlKortdoseHandler>());
    parser.AddHandler("Opioidsoknad", std::make_shared<XmlOpioidsoknadHandler>());
    parser.AddHandler("Deling", std::make_shared<XmlDelingHandler>());
    parser.AddHandler("SvartTrekant", std::make_shared<XmlSvartTrekantHandler>());
    parser.AddHandler("Smak", std::make_shared<XmlSmakHandler>());
    parser.AddHandler("RefVirkestoff", std::make_shared<XmlRefVirkestoffHandler>());
    parser.AddHandler("SortertVirkestoffUtenStyrke", std::make_shared<XmlSortertVirkestoffUtenStyrkeHandler>());
    parser.AddHandler("KanApnes", std::make_shared<XmlKanApnesHandler>());
    parser.AddHandler("Kjonn", std::make_shared<XmlKjonnHandler>());
    parser.AddHandler("Bolus", std::make_shared<XmlBolusHandler>());
    parser.AddHandler("Vaksinestandard", std::make_shared<XmlVaksinestandardHandler>());
    parser.AddHandler("InjeksjonshastighetBolus", std::make_shared<XmlInjeksjonshastighetBolusHandler>());
    parser.AddHandler("Blandingsveske", std::make_shared<XmlBlandingsveskeHandler>());
    parser.AddHandler("KatLegemiddelpakning", std::make_shared<KatLegemiddelpakningHandler>());
    parser.AddHandler("OppfLegemiddelpakning", std::make_shared<OppfLegemiddelpakningHandler>());
    parser.AddHandler("Legemiddelpakning", std::make_shared<XmlLegemiddelpakningHandler>());
    do {
        int num = source->read(&(buf[0]), sizeof(buf));
        if (num < 0) {
            std::cerr << "Read error, xml stream\n";
            return;
        }
        if (num == 0) {
            break;
        }
        std::cout << "Read " << num << " bytes\n";
        if (!parser.ParseBuffer(&(buf[0]), num, false)) {
            std::cerr << "XML Parse error\n";
            return;
        }
    } while (true);
    parser.ParseBuffer(nullptr, 0, true);
}