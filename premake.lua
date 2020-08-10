workspace "clock"
	location ("build/")

	configurations {"Debug", "Release"}

	buildoptions{
		"-std=c++14"
	}

	configuration "Debug"
		defines {"DEBUG"}
		symbols "On"

	configuration "Release"
		defines {"NDEBUG"}
		optimize "On"

	project "clockapp"
		kind "ConsoleApp"
		language "C++"
		targetdir "bin/"

		includedirs{
			"include"
		}	

		files {
			"src/main.cpp",
			"src/test.cpp"
		}
