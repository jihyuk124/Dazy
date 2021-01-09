return function()
	warnings 'Off'
	kind 'StaticLib'
    language 'C'
	staticruntime 'on'
	
	includedirs
	{
		'ThirdParty/glad/include'
	}

	files
	{
		'ThirdParty/glad/include/glad/glad.h',
		'ThirdParty/glad/include/KHR/khrplatform.h',
		'ThirdParty/glad/src/glad.c'
	}

	filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"
end