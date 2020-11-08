# Add needed DLLs to executable
include(BundleUtilities)
fixup_bundle(${CMAKE_INSTALL_PREFIX}/bin/SnakeSFML.exe "" ${DLL_PATH})
