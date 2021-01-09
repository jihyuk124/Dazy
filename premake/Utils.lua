function get_platforms()
	if _ACTION == "android-studio" then
		return { "armeabi-v7a", "arm64-v8a", "x86", "x86_64" }
	end

	if os.ishost( "windows" ) then
		return { "x64" }
	end

	-- Get the ID for the host processor architecture
	local arch = os.outputof( "uname -m" )
	return { arch }
end