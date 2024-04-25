#include <iostream>
#include <cstdio>
#include <stdio.h>
#include "IO.hpp"
#pragma once


class FileReaderWriter: public ReaderWriter {
    FILE* source;
    size_t curr_pos;

public:

    FileReaderWriter(char const* src_name) : source(fopen(src_name, "w+")), curr_pos(0) { };

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
