//
// Created by sigsegv on 5/15/24.
//

#include <string>
#include <iostream>
#include <medfest/FestDeserializer.h>


int usage(const std::string &cmd) {
    std::cerr << "Usage:\n " << cmd << " <fest.bin>\n";
    return 2;
}

int cppmain(const std::string &cmd, const std::vector<std::string> &args) {
    if (args.size() != 1) {
        return usage(cmd);
    }
    auto filename = args[0];
    FestDeserializer festDeserializer{filename};
    auto majorVersion = festDeserializer.GetVersionMajor();
    auto minorVersion = festDeserializer.GetVersionMinor();
    auto patchVersion = festDeserializer.GetVersionPatch();
    std::cout << "FEST DB v" << majorVersion << "." << minorVersion << "." << patchVersion << "\n";
    auto refusjonskode_0_0_0 = festDeserializer.GetRefusjonskode_0_0_0();
    if (refusjonskode_0_0_0.empty()) {
        std::cerr << "Warning: Empty list of refusjonskode (v0.0.0)\n";
    }
    if (majorVersion > 0) {
        std::cerr << "Error: Version of DB-file is not supported by check utility\n";
        return 1;
    }
    if (minorVersion >= 1) {
        auto refusjonskode_0_1_0 = festDeserializer.GetRefusjonskode_0_1_0();
        if (refusjonskode_0_0_0.size() != refusjonskode_0_1_0.size()) {
            std::cerr << "Error: Refusjonskode v0.0.0 and v0.1.0 sizes mismatching (v0.1.0)\n";
            std::cerr << " v0.0.0 size = " << refusjonskode_0_0_0.size() << "\n";
            std::cerr << " v0.1.0 size = " << refusjonskode_0_1_0.size() << "\n";
            return 1;
        }
        bool failed{false};
        for (typeof(refusjonskode_0_0_0.size()) i = 0; i < refusjonskode_0_0_0.size(); i++) {
            PRefusjonskode_0_0_0 v0_0_0{refusjonskode_0_0_0[i]};
            PRefusjonskode_0_0_0 v0_1_0{refusjonskode_0_1_0[i]};
            if (v0_0_0 != v0_1_0) {
                failed = true;
                std::cerr << "Error: Refusjonskode v0.0.0 and v0.1.0 is mismatched at index " << i << "\n";
            }
        }
        if (failed) {
            return 1;
        }
        std::cout << "Refusjonskode compat ok, number of records: " << refusjonskode_0_1_0.size() << "\n";
    }
    return 0;
}