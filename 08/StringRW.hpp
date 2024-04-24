#include <iostream>
#include "IO.hpp"
#pragma once

class StringReaderWriter: public ReaderWriter {
    std::string source;
    bool is_open;

public:

    StringReaderWriter(): ReaderWriter() {
        source = "";
        is_open = true;
    };

    bool is_source_open() override;

    // bool is_eof(int pos) override;

    // void close() override;

    void print_source();

    // void write_char(char ch) override;

    // char read_char() override;

    // void write_int(int i)  override;

    // void write_double(double d) override;

    // void write_float(float f) override;

    // void write_bool(bool b) override;

    // void write_string(std::string string) override;
};
