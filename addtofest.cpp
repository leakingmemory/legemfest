//
// Created by sigsegv on 2/19/23.
//

#include <medfest/FestSerializer.h>
#include <medfest/FestDeserializer.h>
#include <medfest/FestZip.h>

int usage(const std::string &cmd) {
    std::cerr << "Usage:\n " << cmd << " <src-db.bin> <fest1.zip> ... <dst-db.bin>\n";
    return 2;
}

int cppmain(const std::string &cmd, const std::vector<std::string> &args) {
    if (args.size() < 3) {
        return usage(cmd);
    }
    const auto &input = args[0];
    const auto top = args.size() - 1;
    const auto &output = args[top];
    if (input == output) {
        std::cerr << "Error: Do not output to the input db\n";
        return usage(cmd);
    }
    FestSerializer festSerializer{output};
    {
        const FestDeserializer festDeserializer{input};
        festDeserializer.Preload(festSerializer);
    }
    for (std::remove_const<typeof(top)>::type i = 1; i < top; i++) {
        auto filename = args[i];
        FestZip festzip{filename};
        auto fest = festzip.Decode();
        if (fest) {
            festSerializer.Serialize(*fest);
        } else {
            std::cerr << "Error: Failed to decode fest file " << filename << "\n";
        }
    }
    festSerializer.Write();
    return 0;
}
