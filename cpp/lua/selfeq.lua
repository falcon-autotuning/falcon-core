--[[
- Self Equality Check Inserter for C++ operator==

 This module provides a function and command to insert a self-equality check
 (`if (this==&other) return true;`) immediately after the opening brace of the
 first `operator==` function in the current buffer.

 Usage:
   1. The command `:InsertSelfEqualityCheck` will be available when in this project.
   2. Or call from Lua: `require("selfeq").insert_self_equality_check()`

 What it does:
   - Searches for the first occurrence of 'operator==' in the buffer.
   - Finds the first '{' after that.
   - Checks if the next line is already the self-equality check.
   - If not, inserts `if (this==&other) return true;` after the brace.

 Limitations:
   - Only operates on the current buffer.
   - Only affects the first 'operator==' and '{' found.
   - Intended for C++-style equality operators. 
]]

--- Check if a line is a self-equality check (flexible whitespace, optional semicolon)
---@param line string
---@return boolean
local function is_self_equality_check(line)
	return line:find("^%s*if%s*%(%s*this%s*==%s*&other%s*%)%s*return%s*true%s*;?") ~= nil
end

--- Find the line index of the first occurrence of 'operator=='
---@param lines string[]
---@return integer|nil
local function find_operator_eq_index(lines)
	for i, line in ipairs(lines) do
		if line:find("operator==") then
			return i
		end
	end
	return nil
end

--- Find the line index of the first '{' after a given index
---@param lines string[]
---@param start_idx integer
---@return integer|nil
local function find_brace_index(lines, start_idx)
	for i = start_idx, #lines do
		if lines[i]:find("{") then
			return i
		end
	end
	return nil
end

--- Check if a self-equality check exists within the next n lines after a given index
---@param lines string[]
---@param brace_idx integer
---@param n integer
---@return boolean
local function has_self_equality_check(lines, brace_idx, n)
	for i = 1, n do
		local checkline = lines[brace_idx + i] or ""
		if is_self_equality_check(checkline) then
			return true
		end
	end
	return false
end

--- Main function to insert self-equality check
function M.insert_self_equality_check()
	local bufnr = vim.api.nvim_get_current_buf()
	local lines = vim.api.nvim_buf_get_lines(bufnr, 0, -1, false)

	local op_idx = find_operator_eq_index(lines)
	if not op_idx then
		vim.notify("operator== not found", vim.log.levels.WARN)
		return
	end

	local brace_idx = find_brace_index(lines, op_idx)
	if not brace_idx then
		vim.notify("{ not found after operator==", vim.log.levels.WARN)
		return
	end

	if has_self_equality_check(lines, brace_idx, 3) then
		vim.notify("Self-equality check already present", vim.log.levels.INFO)
		return
	end

	vim.api.nvim_buf_set_lines(bufnr, brace_idx, brace_idx, false, { "  if (this==&other) return true;" })
	vim.notify("Inserted self-equality check", vim.log.levels.INFO)
end

vim.api.nvim_create_user_command("InsertSelfEqualityCheck", function()
	require("selfeq").insert_self_equality_check()
end, {})

return M
