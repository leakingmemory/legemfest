//
// Created by sigsegv on 2/19/23.
//

#ifndef LEGEMFEST_COPYFESTDATA_CPP
#define LEGEMFEST_COPYFESTDATA_CPP

#include <medfest/FestDeserializer.h>
#include <medfest/FestSerializer.h>
#include <iostream>

int usage(const std::string &cmd) {
    std::cerr << "Usage:\n " << cmd << " <src.bin> <dst.bin>\n";
    return 2;
}

int cppmain(const std::string &cmd, const std::vector<std::string> &args) {
    if (args.size() != 2) {
        return usage(cmd);
    }
    const auto &src = args[0];
    const auto &dst = args[1];
    FestDeserializer festDeserializer{src};
    FestSerializer festSerializer{dst};
    festDeserializer.Preload(festSerializer);
    if (!festSerializer.Write()) {
        std::cerr << "Error: Write copy\n";
        return 1;
    }
    return 0;
}

#endif //LEGEMFEST_COPYFESTDATA_CPP
