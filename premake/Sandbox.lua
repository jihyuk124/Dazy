function add_sandbox()
	project( "Sandbox" )
	
	kind "ConsoleApp"
	location "Sandbox"
	staticruntime "on"

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
	}

	includedirs
	{
		"Dazy/src",
		"Dazy/src/Core",
		"ThirdParty/spdlog/include",
		"ThirdParty",
	}

	links("Dazy")

end