-- Neovim init.lua for falcon-core project
-- This file can be used by using the folwing command in Neovim:
-- :luafile init.lua
-- Add c-api/lua and cpp/lua folders to Lua's package.path for require()
package.path = package.path
	.. ";/home/tylerk/falcon-dev/falcon-core/c-api/lua/?.lua"
	.. ";/home/tylerk/falcon-dev/falcon-core/cpp/lua/?.lua"

-- Add project root to runtimepath for Neovim plugins/scripts
vim.opt.rtp:append("/home/tylerk/falcon-dev/falcon-core")
