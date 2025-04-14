#pragma once

// Define CI_BUILD for CI environments
#define CI_BUILD

#include <string>
#include <vector>
#include <functional>
#include <memory>

#ifdef CI_BUILD
#include "mach_compat.h" // Use our compatibility header
#else
#include <mach/mach.h>   // Use real header on iOS
#endif

namespace iOS {
    class GameDetector {
    public:
        // Constructor and destructor
        GameDetector();
        ~GameDetector();
        
        // Base methods
        bool Initialize();
        bool Refresh();
        
        // Game detection methods
        bool IsGameRunning(const std::string& gameIdentifier);
        std::string GetDetectedGameName();
        std::string GetGameExecutablePath();
        
        // Memory validation
        bool ValidatePointer(mach_vm_address_t ptr);
        
        // Just stub implementations for CI build
#ifdef CI_BUILD
    private:
        std::string m_detectedGameName;
        std::string m_gameExecutablePath;
#endif
    };
}
