#pragma once
#include "whereami/wrapper.hpp"
#include <filesystem>

struct Paths
{
	static inline const std::filesystem::path root{wai::getExecutablePath().parent_path()};
	static inline const std::filesystem::path data{root / "data"};
	static inline const std::filesystem::path fonts{data / "Fonts"};
	static inline const std::filesystem::path locales{data / "Locales"};
	static inline const std::filesystem::path sprites{data / "Sprites"};
};
