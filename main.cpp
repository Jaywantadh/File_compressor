#include <iostream>
#include <fstream>
#include <string>
#include <zlib.h>

void compressFile(const std::string& source, const std::string& dest) {
    std::ifstream sourceFile(source, std::ios::binary);
    std::ofstream destFile(dest, std::ios::binary);
    
    if (!sourceFile.is_open() || !destFile.is_open()) {
        std::cerr << "Failed to open files!" << std::endl;
        return;
    }

    const int bufferSize = 128 * 1024;
    char buffer[bufferSize];

    z_stream strm;
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;
    strm.avail_in = 0;
    strm.next_in = Z_NULL;

    if (deflateInit(&strm, Z_BEST_COMPRESSION) != Z_OK) {
        std::cerr << "Failed to initialize compression!" << std::endl;
        return;
    }

    int flush;
    do {
        sourceFile.read(buffer, bufferSize);
        strm.avail_in = sourceFile.gcount();
        flush = sourceFile.eof() ? Z_FINISH : Z_NO_FLUSH;
        strm.next_in = reinterpret_cast<unsigned char*>(buffer);

        do {
            char out[bufferSize];
            strm.avail_out = bufferSize;
            strm.next_out = reinterpret_cast<unsigned char*>(out);
            deflate(&strm, flush);
            destFile.write(out, bufferSize - strm.avail_out);
        } while (strm.avail_out == 0);
    } while (flush != Z_FINISH);

    deflateEnd(&strm);
    sourceFile.close();
    destFile.close();
}

extern "C" {
    void compress(const char* source, const char* dest) {
        compressFile(source, dest);
    }
}
