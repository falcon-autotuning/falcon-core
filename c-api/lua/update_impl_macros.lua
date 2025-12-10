--[[
  update_impl_macros.lua

  Neovim Lua module for updating C API implementation (.cpp) files:
  - Uses LSP to find and remove function definitions for standard C API functions.
  - Inserts macro includes after the last #include at the top.
  - Inserts macro calls (e.g., DEFINE_C_API_COPY(Type);) after the extern "C" { line.
  - Uses the filename to infer the Type (e.g., Channel from Channel_c_api.cpp).

  Usage:
    :lua require('update_impl_macros').update_impl_macros()
]]

---@diagnostic disable: undefined-global

local macro_includes = {
	'#include "falcon_core/Precompiled_c_api.h"',
}
local include_patterns = {
	"falcon_core/generic/ErrorHandling_c_api.h",
	"falcon_core/generic/String_c_api.h",
}

local c_api_specs = {
	{ name = "copy", macro = "DEFINE_C_API_COPY" },
	{ name = "destroy", macro = "DEFINE_C_API_DESTROY" },
	{ name = "equal", macro = "DEFINE_C_API_EQUAL" },
	{ name = "not_equal", macro = "DEFINE_C_API_NOT_EQUAL" },
	{ name = "to_json_string", macro = "DEFINE_C_API_TO_JSON" },
	{ name = "from_json_string", macro = "DEFINE_C_API_FROM_JSON" },
}

---@param filename string
---@return string|nil
local function find_type_from_filename(filename)
	local base = filename:match("([^/]+)_c_api%.cpp$")
	return base
end

---@param lines string[]
---@return integer
local function find_extern_c_idx(lines)
	for i, line in ipairs(lines) do
		if line:match('^extern%s+"C"%s*{') then
			return i
		end
	end
	error('Could not find extern "C" {', 1)
end

---@param lines string[]
---@return integer
local function find_last_include(lines)
	local last_include = 0
	for i, line in ipairs(lines) do
		if line:match("^#include") then
			last_include = i
		end
	end
	return last_include
end

---@param lines string[]
---@param patterns string[]
---@return string[]
local function remove_include_lines(lines, patterns)
	local cleaned = {}
	for _, line in ipairs(lines) do
		local skip = false
		for _, pat in ipairs(patterns) do
			if line:match(pat) then
				skip = true
				print("Deleting include: " .. line)
				break
			end
		end
		if not skip then
			table.insert(cleaned, line)
		end
	end
	return cleaned
end

---@param lines string[]
---@param last_include integer
---@return string[]
local function insert_macro_includes(lines, last_include)
	for i, inc in ipairs(macro_includes) do
		table.insert(lines, last_include + i, inc)
	end
	return lines
end

---@param Type string
---@return string[]
local function get_macro_calls(Type)
	local macros = {}
	for _, spec in ipairs(c_api_specs) do
		table.insert(macros, string.format("%s(%s);", spec.macro, Type))
	end
	return macros
end

---@param lines string[]
---@param insert_idx integer
---@param Type string
---@return string[]
local function insert_macro_calls(lines, insert_idx, Type)
	local macros = get_macro_calls(Type)
	for i = #macros, 1, -1 do
		table.insert(lines, insert_idx + 1, macros[i])
	end
	return lines
end

---@param Type string
---@return table<string, boolean>
local function get_target_function_names(Type)
	local names = {}
	for _, spec in ipairs(c_api_specs) do
		names[Type .. "_" .. spec.name] = true
	end
	return names
end

---Finds all function nodes in the buffer using Treesitter.
---@param bufnr integer
---@return table
local function get_function_nodes(bufnr)
	local parser = vim.treesitter.get_parser(bufnr, "cpp")
	local tree = parser:parse()[1]:root()
	local query = vim.treesitter.query.parse(
		"cpp",
		[[
    (function_definition
      declarator: (function_declarator
        declarator: (identifier) @func_name))
  ]]
	)
	local nodes = {}
	for id, node in query:iter_captures(tree, bufnr, 0, -1) do
		local name = vim.treesitter.get_node_text(node, bufnr)
		local func_node = node:parent():parent()
		table.insert(nodes, { name = name, node = func_node })
	end
	return nodes
end

---Deletes functions by name using Treesitter.
---@param bufnr integer
---@param target_names table<string, boolean>
local function delete_functions_with_treesitter(bufnr, target_names)
	local nodes = get_function_nodes(bufnr)
	local to_delete = {}
	for _, item in ipairs(nodes) do
		if target_names[item.name] then
			local start_row, _, end_row, _ = item.node:range()
			table.insert(to_delete, { start = start_row, finish = end_row })
			print("Deleting function: " .. item.name .. " [" .. start_row .. "-" .. end_row .. "]")
		end
	end
	-- Sort and delete from bottom up
	table.sort(to_delete, function(a, b)
		return a.start > b.start
	end)
	for _, r in ipairs(to_delete) do
		vim.api.nvim_buf_set_lines(bufnr, r.start, r.finish + 1, false, {})
	end
end

---Main entry point: updates the current buffer's implementation file with macro includes and macro calls.
local function update_impl_macros()
	local bufnr = vim.api.nvim_get_current_buf()
	local filename = vim.api.nvim_buf_get_name(bufnr)
	local Type = find_type_from_filename(filename)
	if not Type then
		print("Could not determine type from filename!")
		return
	end
	-- Build target function names
	local target_names = get_target_function_names(Type)
	-- Delete functions using Treesitter
	delete_functions_with_treesitter(bufnr, target_names)
	-- Re-fetch buffer lines after deletion
	local cleaned_lines = vim.api.nvim_buf_get_lines(bufnr, 0, -1, false)
	-- Insert macro includes after last #include
	cleaned_lines = remove_include_lines(cleaned_lines, include_patterns)
	local last_include = find_last_include(cleaned_lines)
	cleaned_lines = insert_macro_includes(cleaned_lines, last_include)
	-- Find extern "C" index after includes
	local extern_c_idx = find_extern_c_idx(cleaned_lines)
	-- Insert macro calls after extern "C" {
	cleaned_lines = insert_macro_calls(cleaned_lines, extern_c_idx, Type)
	-- Write back to buffer
	vim.api.nvim_buf_set_lines(bufnr, 0, -1, false, cleaned_lines)
	print("Implementation macros updated for type: " .. Type)
end

return {
	update_impl_macros = update_impl_macros,
}
