#include <iostream>
#include <fstream>
#include <cstdlib> // for an easy random function
#include <ctime> // for seeding the random function
#include <string>
#include <cmath> // i didn't want to make a ceiling function
#include <string_view> // saving on processing time, there's over 5000 textures in HL2

struct{
    char r;
    char g;
    char b;
} imgCol;

int main() {
    srand(static_cast<int>(time(NULL)));

    std::ifstream list, imgOld;
    std::ofstream imgNew;
    char* output = new char [0x3E]; // 66 bytes, size of a .BMP image header
    int width, height;
    std::string str, parentDir;

    list.open("list.txt");
    std::getline(list, parentDir);
    parentDir.resize(parentDir.length() - 9); // 9 characters is the length of "\list.txt"
    while(std::getline(list, str)) {

    imgCol.r = rand() % 200 + 55; imgCol.g = rand() % 200 + 55; imgCol.b = rand() % 200 + 55; // don't want the accent to be too close to black

    
    imgOld.open(str, std::fstream::in | std::fstream::binary);
    imgNew.open((str.insert(parentDir.length(), std::string_view("_new"), 0)), std::fstream::out | std::fstream::binary | std::fstream::trunc);
    // IMPORTANT: this will not create any files is the folder does not exist
    // you must have <the folder in which you created list.txt>_new with the correct file tree as outlined in the instructions

    imgOld.seekg(0);

    // if you want to understand what's happening here: https://gibberlings3.github.io/iesdp/file_formats/ie_formats/bmp.htm
    imgOld.read(output, 0x3E);
    output[0x00] = 0x42;
    output[0x01] = 0x4D;
    output[0x02] = 0x3E;
    output[0x03] = 0x0C;
    output[0x04] = 0x00;
    output[0x05] = 0x00;
    output[0x06] = 0x00;
    output[0x07] = 0x00;
    output[0x08] = 0x00;
    output[0x09] = 0x00;
    output[0x0A] = 0x3E;
    output[0x0B] = 0x00;
    output[0x0C] = 0x00;
    output[0x0D] = 0x00;
    output[0x0E] = 0x28;
    output[0x0F] = 0x00;
    output[0x10] = 0x00;
    output[0x11] = 0x00;
    // 0x12 through 0x19 is the width and height, carried over from the original image
    output[0x1A] = 0x01;
    output[0x1B] = 0x00;
    output[0x1C] = 0x04;
    output[0x1D] = 0x00;
    output[0x1E] = 0x00;
    output[0x1F] = 0x00;
    output[0x20] = 0x00;
    output[0x21] = 0x00;
    output[0x22] = 0x00;
    output[0x23] = 0x00;
    output[0x24] = 0x00;
    output[0x25] = 0x00;
    output[0x26] = 0xC4;
    output[0x27] = 0x0E;
    output[0x28] = 0x00;
    output[0x29] = 0x00;
    output[0x2A] = 0xC4;
    output[0x2B] = 0x0E;
    output[0x2C] = 0x00;
    output[0x2D] = 0x00;
    output[0x2E] = 0x02;
    output[0x2F] = 0x00;
    output[0x30] = 0x00;
    output[0x31] = 0x00;
    output[0x32] = 0x00;
    output[0x33] = 0x00;
    output[0x34] = 0x00;
    output[0x35] = 0x00;
    output[0x36] = 0x00;
    output[0x37] = 0x00;
    output[0x38] = 0x00;
    output[0x39] = 0xFF;
    output[0x3A] = imgCol.b;
    output[0x3B] = imgCol.g;
    output[0x3C] = imgCol.r;
    output[0x3D] = 0xFF;

    imgNew.write(output, 0x3E);

    unsigned int width = ((unsigned char)output[0x13] * 256) + (unsigned char)output[0x12];
    unsigned int height = ((unsigned char)output[0x17] * 256) + (unsigned char)output[0x16];
    
    /*
     * Write 8 pixels of accent color, then 8 pixels of black. Do this 8 times the image width.
     * Each byte is 2 pixels, so it works out to width * 8 / 2 = 4 * width. Then do the same but
     * with the colors flipped. Repeat this process 1/16th of the image height times becuase you
     * write 16 rows each iteration. Unlikely to work if the texture's width isn't a multiple of 8 or 16
     */
        
    for(int j{ 0 }; j < ceil(height / 16.0f); j++) {
        for(int i{ 0 }; i < 4 * width; i++) {
            imgNew.put((i / 4 % 2) * 16 + (i / 4 % 2));
        }

        for(int i{ 0 }; i < 4 * width; i++) {
            imgNew.put((!(i / 4 % 2)) * 16 + (!(i / 4 % 2)));
        }
    }

    imgOld.close();
    imgNew.close();
    }



    return 0;
}
