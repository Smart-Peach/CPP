#include "StringRW.hpp"


bool StringReaderWriter::is_source_open() {
    return this->is_open;
}

bool StringReaderWriter::is_eof() {
    return source[curr_pos] == '\0';
}

void StringReaderWriter::close() {
    source += '\0';
    is_open = false;
}

std::string StringReaderWriter::get_source() { return this->source; }

void StringReaderWriter::write_char(char ch) {
    source += ch;
}

void StringReaderWriter::write_int(int i) {
    source += std::to_string(i);
}

void StringReaderWriter::write_float(float f) {
    source += std::to_string(f);
}

void StringReaderWriter::write_bool(bool b) {
    if (b) {
        source += "1";
    } else source += "0";
}

void StringReaderWriter::write_string(std::string string) {
    source += string;
}

char StringReaderWriter::read_char() {
    return source[curr_pos++]; 
}

int StringReaderWriter::read_int() {
    char ch = read_char();
    std::string res = "";
    while ((ch != ' ') or (!is_eof())) {
        res += ch;
        ch = read_char();
    }
    return std::stoi(res);
}

float StringReaderWriter::read_float() {
    char ch = read_char();
    std::string res = "";
    while ((ch != ' ') or (!is_eof())) {
        res += ch;
        ch = read_char();
    }
    return std::stof(res);
}

bool StringReaderWriter::read_bool() {
    char ch = read_char();
    while ((ch != ' ') or (!is_eof())) {
        if (ch != '0') {
            return true;
        }
        ch = read_char();
    }
    return false;
}

std::string StringReaderWriter::read_string() {
    char ch = read_char();
    std::string res = "";
    while (!is_eof()) {
        res += ch;
        ch = read_char();
    }
    return res;
}
