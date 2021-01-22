# Add needed DLLs to executable
include(BundleUtilities)
fixup_bundle(${EXE_PATH} "" ${DLL_PATH})
