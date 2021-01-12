return function()
	warnings 'Off'

	includedirs
	{
		'ThirdParty/glm'
	}

	files
	{
		'ThirdParty/glm/glm/**.h',
		'ThirdParty/glm/glm/**.inl',
		'ThirdParty/glm/glm/**.hpp',
		'ThirdParty/glm/glm/**.cpp'
	}
end
