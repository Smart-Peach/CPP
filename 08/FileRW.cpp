#include "FileRW.hpp"


bool FileReaderWriter::is_source_open() {
    return source != nullptr;
}

bool FileReaderWriter::is_eof() {
    return !feof(source);
}

void FileReaderWriter::close() {
    fclose(source);
}

std::string FileReaderWriter::get_source() { return "lalala"; }

void FileReaderWriter::write_char(char ch) {
    fprintf(source, "%c", ch);
}

void FileReaderWriter::write_int(int i) {
    fprintf(source, "%d", i);
}

void FileReaderWriter::write_double(double d) {
    fprintf(source, "%f", d);
}

void FileReaderWriter::write_float(float f) {
    fprintf(source, "%f", f);
}

void FileReaderWriter::write_bool(bool b) {
    if (b) {
        fprintf(source, "%d", 1);
    } else fprintf(source, "%d", 0);
}

void FileReaderWriter::write_string(std::string string) {
    // fprintf(source, "%s", string);
}

char FileReaderWriter::read_char() {
    char ch;
    fscanf(source, "%c", &ch);
    return ch; 
}

int FileReaderWriter::read_int() {
    int i;
    fscanf(source, "%d", &i);
    return i;
}

double FileReaderWriter::read_double() {
    double d;
    fscanf(source, "%f", &d);
    return d;
}

float FileReaderWriter::read_float() {
    float f;
    fscanf(source, "%f", &f);
    return f;
}

bool FileReaderWriter::read_bool() {
    int b = read_int();
    if (!b) {
        return false;
    }
    return true;
}

std::string FileReaderWriter::read_string() {
    std::string s;
    fscanf(source, "%s", &s);
    return s;
}
