// https://github.com/djsoftware1/keep-going
// Created by David Joffe 2026
// file created 6 Jan 2026
// Part of a series of useful utilities.
// MIT License
// Copyright (c) 2026 David Joffe

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[]) {
    static const std::vector<std::string> messages = {
        "Keep Going!",
        "You've got this. Keep going.",
        "Still standing. Keep going.",
        "One step at a time. Keep going.",
        "Ship it. Keep going."
    };

    bool random = false;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--random" || arg == "-r") {
            random = true;
        }
        if (arg == "--help" || arg == "-h") {
            std::cout <<
                "keep-going - tiny morale booster\n\n"
                "Usage:\n"
                "  keep-going           Print \"Keep Going!\"\n"
                "  keep-going --random  Print a random encouraging message\n"
                "  keep-going --help    Show this help\n";
            return 0;
        }
    }

    if (random) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        // NB: Use mod size to make sure we stay in vector bounds range [0..size):
        std::cout << messages[std::rand() % messages.size()] << std::endl;
    } else {
        std::cout << "Keep Going!" << std::endl;
    }

    return 0;
}
