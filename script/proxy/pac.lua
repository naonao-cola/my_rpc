function mirror(url)
     --return string.format("https://github.moeyy.xyz/%s", url)
	 return url:gsub("https://github.com", "https://github.moeyy.xyz/https://github.com")
end