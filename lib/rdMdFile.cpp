#include "../include/ReadModelFile.h";
#include <iostream>;
#include <fstream>

char ModelArray[100];
char* Result;

/**
 * Read a model file and filter it by .o3d. Output is only .o3d files with its corresponding folders.
 * @param path Path to a cfg file.
 */

void ReadModelFile::readTheFile (const std::string& path) {
    std::ifstream ReadConfigFile(path);

    try {
        if(path == "") {
            std::cout << "Fucking File not found .. or empty.";
        } else {
            if (ReadConfigFile.is_open()) {

                while (!ReadConfigFile.eof()) {
                    ReadConfigFile >> ModelArray;
                    Result = strstr(ModelArray, ".o3d");

                    if (Result != NULL) {
                        std::cout << ModelArray << "\n";
                    }
                }
                ReadConfigFile.close();
            }
        }
    } catch (const std::exception& e) {
        std::cout << e.what();
    } catch (const std::runtime_error& e) {
        std::cout << e.what();
    } catch (const std::overflow_error& e) {
        std::cout << e.what();
    }
};