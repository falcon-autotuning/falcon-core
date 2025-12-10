--[[
  update_header_macros.lua

  Neovim Lua module for updating C API header files:
  - Removes existing function declarations (and their category comments) for a set of standard C API functions.
  - Inserts new function declarations (with category comments) after the typedef line, based on a centralized function spec table.
  - Ensures header files are clean and up-to-date for C/C++ and cgo usage.

  This script is intended for header files only. It does not generate or modify function implementations.

  Usage:
    :lua require('update_header_macros').update_header_macros()
]]

---@diagnostic disable: undefined-global

-- Centralized function specs for standard C API functions.
-- Each entry defines the function name, return type, parameters, and category for documentation.
local c_api_specs = {
	{ name = "copy", ret = "%sHandle", params = "%sHandle handle", category = "allocation" },
	{ name = "destroy", ret = "void", params = "%sHandle handle", category = "deallocation" },
	{ name = "equal", ret = "bool", params = "%sHandle handle, %sHandle other", category = "read" },
	{ name = "not_equal", ret = "bool", params = "%sHandle handle, %sHandle other", category = "read" },
	{ name = "to_json_string", ret = "StringHandle", params = "%sHandle handle", category = "read" },
	{ name = "from_json_string", ret = "%sHandle", params = "StringHandle json", category = "allocation" },
}

---Finds the typedef line for TYPEHandle and returns the type name and line index (1-based).
---@param lines string[]
---@return string, integer
local function find_typedef_type(lines)
	for i, line in ipairs(lines) do
		local m = line:match("typedef void%* ([%w_]+)Handle;")
		if m then
			return m, i
		end
	end
	error("Could not find a typedef", 1)
end

---Generates patterns to match both full function declarations and function names for cleanup.
---@param Type string
---@return string[]
local function get_cleanup_patterns(Type)
	local patterns = {}
	for _, spec in ipairs(c_api_specs) do
		-- Match full function declaration
		local decl = string.format(
			"%s %s_%s(%s);",
			string.format(spec.ret, Type),
			Type,
			spec.name,
			string.format(spec.params, Type, Type)
		)
		table.insert(patterns, decl)
		-- Match any line containing the function name and an opening parenthesis
		table.insert(patterns, Type .. "_" .. spec.name .. "%s*%(")
	end
	return patterns
end

---Generates function declarations and associated category comments for a given type.
---@param Type string
---@return {comment: string, decl: string}[]
local function get_function_declarations(Type)
	local decls = {}
	for _, spec in ipairs(c_api_specs) do
		local decl = string.format(
			"%s %s_%s(%s);",
			string.format(spec.ret, Type),
			Type,
			spec.name,
			string.format(spec.params, Type, Type)
		)
		table.insert(decls, { comment = "// @category:" .. spec.category, decl = decl })
	end
	return decls
end

---Removes lines matching any cleanup pattern, and also removes a preceding category comment if present.
---@param lines string[]
---@param patterns string[]
---@param Type string
---@return string[]
local function cleanup_lines_with_comments(lines, patterns, Type)
	local cleaned = {}
	local skip_mode = false
	local i = 1
	while i <= #lines do
		local line = lines[i]

		-- Handle case where type is on its own line and next line is a function declaration
		if line:match("^%s*" .. Type .. "Handle%s*$") and i < #lines then
			local next_line = lines[i + 1]
			local match_next = false
			for _, pat in ipairs(patterns) do
				if next_line:match(pat) then
					match_next = true
					break
				end
			end
			if match_next then
				-- Remove preceding category comment if present
				if #cleaned > 0 and cleaned[#cleaned]:match("^%s*// @category:") then
					table.remove(cleaned, #cleaned)
				end
				-- Skip both lines
				i = i + 2
				goto continue
			end
		end

		if skip_mode then
			if line:find("%);%s*$") then
				skip_mode = false
			end
		elseif
			(function()
				for _, pat in ipairs(patterns) do
					if line:match(pat) then
						return true
					end
				end
				return false
			end)()
		then
			if #cleaned > 0 and cleaned[#cleaned]:match("^%s*// @category:") then
				table.remove(cleaned, #cleaned)
			end
			if not line:find("%);%s*$") then
				skip_mode = true
			end
		else
			table.insert(cleaned, line)
		end

		::continue::
		i = i + 1
	end
	return cleaned
end

---Inserts function declarations and category comments after the typedef line.
---@param lines string[]
---@param typedef_idx integer
---@param Type string
---@return string[]
local function insert_function_declarations(lines, typedef_idx, Type)
	local decls = get_function_declarations(Type)
	local insert_lines = {}
	for _, item in ipairs(decls) do
		table.insert(insert_lines, item.comment)
		table.insert(insert_lines, item.decl)
	end
	for i = #insert_lines, 1, -1 do
		table.insert(lines, typedef_idx + 1, insert_lines[i])
	end
	return lines
end

---Main entry point: updates the current buffer's header file with new function declarations.
local function update_header_macros()
	local bufnr = vim.api.nvim_get_current_buf()
	local lines = vim.api.nvim_buf_get_lines(bufnr, 0, -1, false)
	-- Find type and typedef index
	local Type, typedef_idx = find_typedef_type(lines)
	if not Type then
		print("Type not found in typedef!")
		return
	end
	-- Remove existing function declarations and their category comments
	local cleanup_patterns = get_cleanup_patterns(Type)
	lines = cleanup_lines_with_comments(lines, cleanup_patterns, Type)
	-- Recompute typedef index after cleanup
	_, typedef_idx = find_typedef_type(lines)
	-- Insert new function declarations after typedef
	local insert_line = typedef_idx + 1
	lines = insert_function_declarations(lines, insert_line, Type)
	-- Write back to buffer
	vim.api.nvim_buf_set_lines(bufnr, 0, -1, false, lines)
	print("Function declarations updated for type: " .. Type)
end

return {
	update_header_macros = update_header_macros,
}
