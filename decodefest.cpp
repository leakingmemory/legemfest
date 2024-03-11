//
// Created by jeo on 12/8/22.
//

#include <iostream>
#include "cppmain.h"
#include <medfest/FestZip.h>
#include <medfest/FestSerializer.h>

int DecodeFest(const std::string &zipname, const std::string &outputFile) {
    FestZip festzip{zipname};
    auto fest = festzip.Decode();
    if (fest) {
        FestSerializer serializer{outputFile};
        if (serializer.is_open() && serializer.Serialize(*fest)) {
            if (serializer.Write()) {
                return 0;
            } else {
                std::cerr << "Error: Failed to output fest binary\n";
                return 1;
            }
        } else {
            std::cerr << "Error: Failed to decode and output fest\n";
            return 1;
        }
    } else {
        std::cerr << "Error: Failed to read in FEST\n";
        return 1;
    }
}

int usage(const std::string &cmd) {
    std::cerr << "Usage:\n " << cmd << " <fest.zip> <output.bin>\n";
    return 2;
}

int cppmain(const std::string &cmd, const std::vector<std::string> &args) {
    if (args.size() != 2) {
        return usage(cmd);
    }
    const std::string &festZip = args.at(0);
    const std::string &outputFile = args.at(1);
    return DecodeFest(festZip, outputFile);
}