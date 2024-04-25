#include <iostream>
#include "IO.hpp"
#pragma once

class StringReaderWriter: public ReaderWriter {
private:
    std::string source;
    bool is_open;
    size_t curr_pos;

public:
    StringReaderWriter(std::string src) : source(src), is_open(true), curr_pos(0) { };

    bool is_source_open() override;
    bool is_eof() override;
    void close() override;

    std::string get_source();

    void write_char(char ch) override;
    void write_int(int i)  override;
    void write_float(float f) override;
    void write_bool(bool b) override;
    void write_string(std::string string) override;

    char read_char() override;
    int read_int() override;
    float read_float() override;
    bool read_bool() override;
    std::string read_string() override;
};
