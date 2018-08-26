#pragma once

#include "common.h"
#include <boost/program_options/variables_map.hpp>

namespace vk_music_fs {
    class ProgramOptions {
    public:
        ProgramOptions(uint_fast32_t argc, char **argv, const std::string &configName, const std::string &appName);
        std::string getUseragent();
        bool needHelp();
        std::string getHelpString();
        std::string getToken();
        std::string getMp3Extension();
        std::string getCacheDir();
        bool createDummyDirs();
        uint_fast32_t getFilesCacheSize();
        uint_fast32_t getSizesCacheSize();
        uint_fast32_t getNumSearchFiles();
        uint_fast32_t getNumSizeRetries();

        char **getFuseArgv();
        uint_fast32_t getFuseArgc();
    private:
        std::string getUserConfigDir(const std::string &appName);
        std::string getUserCacheDir(const std::string &appName);
        bool createDummyDirsDefault();
        void parseOptions(boost::program_options::variables_map &vm);
        std::string _helpStr;
        bool _createDummyDirs;
        bool _needHelp;
        char **_fuseArgv;
        uint_fast32_t _fuseArgc;
        std::string _useragent;
        std::string _token;
        std::string _mp3Ext;
        std::string _cacheDir;
        uint_fast32_t _filesCacheSize;
        uint_fast32_t _sizesCacheSize;
        uint_fast32_t _numSearchFiles;
        uint_fast32_t _numSizeRetries;
    };
}